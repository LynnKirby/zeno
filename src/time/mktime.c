#include <errno.h>
#include <limits.h>
#include <stdbool.h>
#include <stdint.h>
#include <time.h>

/* Number of days that have passed by the 1st of the month. */
static const int cumulative_month_len[2][12]
    = { { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 },
        { 0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335 } };

/*
 * Following two functions are modified from:
 *
 *     Howard Hinnant, "chrono-Compatible Low-Level Date Algorithms"
 *     http://howardhinnant.github.io/date_algorithms.html
 */

/* Returns number of days since 1970-01-01 (aka Unix epoch).
 * Input is January 1 of `year`. */
static int64_t unix_days_from_civil_year(int64_t year)
{
    year -= 1;
    int64_t era       = (year >= 0 ? year : year - 399) / 400;
    uint_fast32_t yoe = (uint_fast32_t)(year - era * 400);
    uint_fast32_t doe = yoe * 365 + yoe / 4 - yoe / 100 + 306;
    return era * 146097 + (int64_t)(doe)-719468;
}

/* Returns year/month/day given number of days since 1970-01-01. */
static void civil_date_from_unix_days(
    int64_t day, int64_t *day_out, int64_t *month_out, int64_t *year_out)
{
    day += 719468;
    int64_t era       = (day >= 0 ? day : day - 146096) / 146097;
    uint_fast32_t doe = (uint_fast32_t)(day - era * 146097);
    uint_fast32_t yoe = (doe - doe / 1460 + doe / 36524 - doe / 146096) / 365;
    int64_t y         = (int64_t)yoe + era * 400;
    uint_fast32_t doy = doe - (365 * yoe + yoe / 4 - yoe / 100);
    uint_fast32_t mp  = (5 * doy + 2) / 153;
    uint_fast32_t d   = doy - (153 * mp + 2) / 5 + 1;
    uint_fast32_t m   = mp + (mp < 10 ? 3 : -9);

    *year_out  = y + (m <= 2);
    *month_out = m;
    *day_out   = d;
}

static bool is_civil_year_leap(int64_t y)
{
    return (y % 4 == 0) && (y % 100 != 0 || y % 400 == 0);
}

time_t mktime(struct tm *tm)
{
    /* Normalize time and adjust days by the excess. */
    int64_t sec = tm->tm_sec;
    sec += tm->tm_min * 60LL;
    sec += tm->tm_hour * 3600LL;

    int64_t min = sec / 60;
    sec %= 60;

    if (sec < 0) {
        sec += 60;
        min--;
    }

    int64_t hour = min / 60;
    min %= 60;

    if (min < 0) {
        min += 60;
        hour--;
    }

    /* Note tm_mday is 1-based. */
    int64_t day = (tm->tm_mday - 1LL) + (hour / 24);
    hour %= 24;

    if (hour < 0) {
        hour += 24;
        day--;
    }

    /* Normalize month and adjust year by the excess. */
    int64_t month = tm->tm_mon % 12;
    int64_t year  = tm->tm_year + (tm->tm_mon / 12LL);

    if (month < 0) {
        month += 12;
        year--;
    }

    /* Adjust day and month so that month is 0. */
    if (is_civil_year_leap(year + 1900)) {
        day += cumulative_month_len[1][month];
    } else {
        day += cumulative_month_len[0][month];
    }

    /* Convert the year into days relative to Unix epoch. */
    day += unix_days_from_civil_year(year + 1900);

    /* Get the timestamp, which we return. */
    int64_t t = (day * 24 * 3600) + (hour * 3600) + (min * 60) + sec;

    if (t < 0) {
        errno = EOVERFLOW;
        return (time_t)-1;
    }

    /* Get the final date based on the days. */
    int64_t civil_day;
    int64_t civil_month;
    int64_t civil_year;
    civil_date_from_unix_days(day, &civil_day, &civil_month, &civil_year);

    if (civil_year > INT_MAX || civil_year < INT_MIN) {
        errno = EOVERFLOW;
        return -1;
    }

    tm->tm_sec  = sec;
    tm->tm_min  = min;
    tm->tm_hour = hour;
    tm->tm_mday = civil_day;
    tm->tm_mon  = civil_month - 1;
    tm->tm_year = civil_year - 1900;

    if (tm->tm_isdst < 0) {
        /* Only UTC is supported right now which is never DST. */
        tm->tm_isdst = 0;
    } else if (tm->tm_isdst > 0) {
        /* Normalize. */
        tm->tm_isdst = 1;
    }

    if (is_civil_year_leap(civil_year)) {
        tm->tm_yday = cumulative_month_len[1][civil_month - 1] + civil_day - 1;
    } else {
        tm->tm_yday = cumulative_month_len[0][civil_month - 1] + civil_day - 1;
    }

    /* Get day of the week */
    tm->tm_wday = day >= -4 ? (day + 4) % 7 : (day + 5) % 7 + 6;

    return t;
}

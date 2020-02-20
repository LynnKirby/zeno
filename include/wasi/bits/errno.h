/*
 * SPDX-License-Identifier: CC0-1.0
 * bits/errno.h private header - WASI version
 */

#ifndef _BITS_ERRNO_H
#define _BITS_ERRNO_H

#define ESUCCESS        0
#define E2BIG           1
#define EACCES          2
#define EADDRINUSE      3
#define EADDRNOTAVAIL   4
#define EAFNOSUPPORT    5
#define EAGAIN          6
#define EALREADY        7
#define EBADF           8
#define EBADMSG         9
#define EBUSY           10
#define ECANCELED       11
#define ECHILD          12
#define ECONNABORTED    13
#define ECONNREFUSED    14
#define ECONNRESET      15
#define EDEADLK         16
#define EDESTADDRREQ    17
#define EDOM            18
#define EDQUOT          19
#define EEXIST          20
#define EFAULT          21
#define EFBIG           22
#define EHOSTUNREACH    23
#define EIDRM           24
#define EILSEQ          25
#define EINPROGRESS     26
#define EINTR           27
#define EINVAL          28
#define EIO             29
#define EISCONN         30
#define EISDIR          31
#define ELOOP           32
#define EMFILE          33
#define EMLINK          34
#define EMSGSIZE        35
#define EMULTIHOP       36
#define ENAMETOOLONG    37
#define ENETDOWN        38
#define ENETRESET       39
#define ENETUNREACH     40
#define ENFILE          41
#define ENOBUFS         42
#define ENODEV          43
#define ENOENT          44
#define ENOEXEC         45
#define ENOLCK          46
#define ENOLINK         47
#define ENOMEM          48
#define ENOMSG          49
#define ENOPROTOOPT     50
#define ENOSPC          51
#define ENOSYS          52
#define ENOTCONN        53
#define ENOTDIR         54
#define ENOTEMPTY       55
#define ENOTRECOVERABLE 56
#define ENOTSOCK        57
#define ENOTSUP         58
#define ENOTTY          59
#define ENXIO           60
#define EOVERFLOW       61
#define EOWNERDEAD      62
#define EPERM           63
#define EPIPE           64
#define EPROTO          65
#define EPROTONOSUPPORT 66
#define EPROTOTYPE      67
#define ERANGE          68
#define EROFS           69
#define ESPIPE          70
#define ESRCH           71
#define ESTALE          72
#define ETIMEDOUT       73
#define ETXTBSY         74
#define EXDEV           75
#define ENOTCAPABLE     76
#define EOPNOTSUPP      ENOTSUP
#define EWOULDBLOCK     EAGAIN

#endif

#include "test.h"
#include <inttypes.h>

int main(void)
{
    assert_is_type(imaxdiv_t);

    /* fprintf macros for signed integers */

    assert_is_string(PRId8);
    assert_is_string(PRId16);
    assert_is_string(PRId32);
    assert_is_string(PRId64);

    assert_is_string(PRIdLEAST8);
    assert_is_string(PRIdLEAST16);
    assert_is_string(PRIdLEAST32);
    assert_is_string(PRIdLEAST64);

    assert_is_string(PRIdFAST8);
    assert_is_string(PRIdFAST16);
    assert_is_string(PRIdFAST32);
    assert_is_string(PRIdFAST64);

    assert_is_string(PRIdMAX);
    assert_is_string(PRIdPTR);

    assert_is_string(PRIi8);
    assert_is_string(PRIi16);
    assert_is_string(PRIi32);
    assert_is_string(PRIi64);

    assert_is_string(PRIiLEAST8);
    assert_is_string(PRIiLEAST16);
    assert_is_string(PRIiLEAST32);
    assert_is_string(PRIiLEAST64);

    assert_is_string(PRIiFAST8);
    assert_is_string(PRIiFAST16);
    assert_is_string(PRIiFAST32);
    assert_is_string(PRIiFAST64);

    assert_is_string(PRIiMAX);
    assert_is_string(PRIiPTR);

    /* fprintf macros for unsigned integers */

    assert_is_string(PRIo8);
    assert_is_string(PRIo16);
    assert_is_string(PRIo32);
    assert_is_string(PRIo64);

    assert_is_string(PRIoLEAST8);
    assert_is_string(PRIoLEAST16);
    assert_is_string(PRIoLEAST32);
    assert_is_string(PRIoLEAST64);

    assert_is_string(PRIoFAST8);
    assert_is_string(PRIoFAST16);
    assert_is_string(PRIoFAST32);
    assert_is_string(PRIoFAST64);

    assert_is_string(PRIoMAX);
    assert_is_string(PRIoPTR);

    assert_is_string(PRIu8);
    assert_is_string(PRIu16);
    assert_is_string(PRIu32);
    assert_is_string(PRIu64);

    assert_is_string(PRIuLEAST8);
    assert_is_string(PRIuLEAST16);
    assert_is_string(PRIuLEAST32);
    assert_is_string(PRIuLEAST64);

    assert_is_string(PRIuFAST8);
    assert_is_string(PRIuFAST16);
    assert_is_string(PRIuFAST32);
    assert_is_string(PRIuFAST64);

    assert_is_string(PRIuMAX);
    assert_is_string(PRIuPTR);

    assert_is_string(PRIx8);
    assert_is_string(PRIx16);
    assert_is_string(PRIx32);
    assert_is_string(PRIx64);

    assert_is_string(PRIxLEAST8);
    assert_is_string(PRIxLEAST16);
    assert_is_string(PRIxLEAST32);
    assert_is_string(PRIxLEAST64);

    assert_is_string(PRIxFAST8);
    assert_is_string(PRIxFAST16);
    assert_is_string(PRIxFAST32);
    assert_is_string(PRIxFAST64);

    assert_is_string(PRIxMAX);
    assert_is_string(PRIxPTR);

    assert_is_string(PRIX8);
    assert_is_string(PRIX16);
    assert_is_string(PRIX32);
    assert_is_string(PRIX64);

    assert_is_string(PRIXLEAST8);
    assert_is_string(PRIXLEAST16);
    assert_is_string(PRIXLEAST32);
    assert_is_string(PRIXLEAST64);

    assert_is_string(PRIXFAST8);
    assert_is_string(PRIXFAST16);
    assert_is_string(PRIXFAST32);
    assert_is_string(PRIXFAST64);

    assert_is_string(PRIXMAX);
    assert_is_string(PRIXPTR);

    /* fscanf macros for signed integers */

    assert_is_string(SCNd8);
    assert_is_string(SCNd16);
    assert_is_string(SCNd32);
    assert_is_string(SCNd64);

    assert_is_string(SCNdLEAST8);
    assert_is_string(SCNdLEAST16);
    assert_is_string(SCNdLEAST32);
    assert_is_string(SCNdLEAST64);

    assert_is_string(SCNdFAST8);
    assert_is_string(SCNdFAST16);
    assert_is_string(SCNdFAST32);
    assert_is_string(SCNdFAST64);

    assert_is_string(SCNdMAX);
    assert_is_string(SCNdPTR);

    assert_is_string(SCNi8);
    assert_is_string(SCNi16);
    assert_is_string(SCNi32);
    assert_is_string(SCNi64);

    assert_is_string(SCNiLEAST8);
    assert_is_string(SCNiLEAST16);
    assert_is_string(SCNiLEAST32);
    assert_is_string(SCNiLEAST64);

    assert_is_string(SCNiFAST8);
    assert_is_string(SCNiFAST16);
    assert_is_string(SCNiFAST32);
    assert_is_string(SCNiFAST64);

    assert_is_string(SCNiMAX);
    assert_is_string(SCNiPTR);

    /* fscanf macros for unsigned integers */

    assert_is_string(SCNo8);
    assert_is_string(SCNo16);
    assert_is_string(SCNo32);
    assert_is_string(SCNo64);

    assert_is_string(SCNoLEAST8);
    assert_is_string(SCNoLEAST16);
    assert_is_string(SCNoLEAST32);
    assert_is_string(SCNoLEAST64);

    assert_is_string(SCNoFAST8);
    assert_is_string(SCNoFAST16);
    assert_is_string(SCNoFAST32);
    assert_is_string(SCNoFAST64);

    assert_is_string(SCNoMAX);
    assert_is_string(SCNoPTR);

    assert_is_string(SCNu8);
    assert_is_string(SCNu16);
    assert_is_string(SCNu32);
    assert_is_string(SCNu64);

    assert_is_string(SCNuLEAST8);
    assert_is_string(SCNuLEAST16);
    assert_is_string(SCNuLEAST32);
    assert_is_string(SCNuLEAST64);

    assert_is_string(SCNuFAST8);
    assert_is_string(SCNuFAST16);
    assert_is_string(SCNuFAST32);
    assert_is_string(SCNuFAST64);

    assert_is_string(SCNuMAX);
    assert_is_string(SCNuPTR);

    assert_is_string(SCNx8);
    assert_is_string(SCNx16);
    assert_is_string(SCNx32);
    assert_is_string(SCNx64);

    assert_is_string(SCNxLEAST8);
    assert_is_string(SCNxLEAST16);
    assert_is_string(SCNxLEAST32);
    assert_is_string(SCNxLEAST64);

    assert_is_string(SCNxFAST8);
    assert_is_string(SCNxFAST16);
    assert_is_string(SCNxFAST32);
    assert_is_string(SCNxFAST64);

    assert_is_string(SCNxMAX);
    assert_is_string(SCNxPTR);

    return 0;
}

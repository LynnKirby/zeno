#include "header_test.h"
#include <inttypes.h>

int main(void)
{
    type(imaxdiv_t);

    /* fprintf macros for signed integers */

    string_constant(PRId8);
    string_constant(PRId16);
    string_constant(PRId32);
    string_constant(PRId64);

    string_constant(PRIdLEAST8);
    string_constant(PRIdLEAST16);
    string_constant(PRIdLEAST32);
    string_constant(PRIdLEAST64);

    string_constant(PRIdFAST8);
    string_constant(PRIdFAST16);
    string_constant(PRIdFAST32);
    string_constant(PRIdFAST64);

    string_constant(PRIdMAX);
    string_constant(PRIdPTR);

    string_constant(PRIi8);
    string_constant(PRIi16);
    string_constant(PRIi32);
    string_constant(PRIi64);

    string_constant(PRIiLEAST8);
    string_constant(PRIiLEAST16);
    string_constant(PRIiLEAST32);
    string_constant(PRIiLEAST64);

    string_constant(PRIiFAST8);
    string_constant(PRIiFAST16);
    string_constant(PRIiFAST32);
    string_constant(PRIiFAST64);

    string_constant(PRIiMAX);
    string_constant(PRIiPTR);

    /* fprintf macros for unsigned integers */

    string_constant(PRIo8);
    string_constant(PRIo16);
    string_constant(PRIo32);
    string_constant(PRIo64);

    string_constant(PRIoLEAST8);
    string_constant(PRIoLEAST16);
    string_constant(PRIoLEAST32);
    string_constant(PRIoLEAST64);

    string_constant(PRIoFAST8);
    string_constant(PRIoFAST16);
    string_constant(PRIoFAST32);
    string_constant(PRIoFAST64);

    string_constant(PRIoMAX);
    string_constant(PRIoPTR);

    string_constant(PRIu8);
    string_constant(PRIu16);
    string_constant(PRIu32);
    string_constant(PRIu64);

    string_constant(PRIuLEAST8);
    string_constant(PRIuLEAST16);
    string_constant(PRIuLEAST32);
    string_constant(PRIuLEAST64);

    string_constant(PRIuFAST8);
    string_constant(PRIuFAST16);
    string_constant(PRIuFAST32);
    string_constant(PRIuFAST64);

    string_constant(PRIuMAX);
    string_constant(PRIuPTR);

    string_constant(PRIx8);
    string_constant(PRIx16);
    string_constant(PRIx32);
    string_constant(PRIx64);

    string_constant(PRIxLEAST8);
    string_constant(PRIxLEAST16);
    string_constant(PRIxLEAST32);
    string_constant(PRIxLEAST64);

    string_constant(PRIxFAST8);
    string_constant(PRIxFAST16);
    string_constant(PRIxFAST32);
    string_constant(PRIxFAST64);

    string_constant(PRIxMAX);
    string_constant(PRIxPTR);

    string_constant(PRIX8);
    string_constant(PRIX16);
    string_constant(PRIX32);
    string_constant(PRIX64);

    string_constant(PRIXLEAST8);
    string_constant(PRIXLEAST16);
    string_constant(PRIXLEAST32);
    string_constant(PRIXLEAST64);

    string_constant(PRIXFAST8);
    string_constant(PRIXFAST16);
    string_constant(PRIXFAST32);
    string_constant(PRIXFAST64);

    string_constant(PRIXMAX);
    string_constant(PRIXPTR);

    /* fscanf macros for signed integers */

    string_constant(SCNd8);
    string_constant(SCNd16);
    string_constant(SCNd32);
    string_constant(SCNd64);

    string_constant(SCNdLEAST8);
    string_constant(SCNdLEAST16);
    string_constant(SCNdLEAST32);
    string_constant(SCNdLEAST64);

    string_constant(SCNdFAST8);
    string_constant(SCNdFAST16);
    string_constant(SCNdFAST32);
    string_constant(SCNdFAST64);

    string_constant(SCNdMAX);
    string_constant(SCNdPTR);

    string_constant(SCNi8);
    string_constant(SCNi16);
    string_constant(SCNi32);
    string_constant(SCNi64);

    string_constant(SCNiLEAST8);
    string_constant(SCNiLEAST16);
    string_constant(SCNiLEAST32);
    string_constant(SCNiLEAST64);

    string_constant(SCNiFAST8);
    string_constant(SCNiFAST16);
    string_constant(SCNiFAST32);
    string_constant(SCNiFAST64);

    string_constant(SCNiMAX);
    string_constant(SCNiPTR);

    /* fscanf macros for unsigned integers */

    string_constant(SCNo8);
    string_constant(SCNo16);
    string_constant(SCNo32);
    string_constant(SCNo64);

    string_constant(SCNoLEAST8);
    string_constant(SCNoLEAST16);
    string_constant(SCNoLEAST32);
    string_constant(SCNoLEAST64);

    string_constant(SCNoFAST8);
    string_constant(SCNoFAST16);
    string_constant(SCNoFAST32);
    string_constant(SCNoFAST64);

    string_constant(SCNoMAX);
    string_constant(SCNoPTR);

    string_constant(SCNu8);
    string_constant(SCNu16);
    string_constant(SCNu32);
    string_constant(SCNu64);

    string_constant(SCNuLEAST8);
    string_constant(SCNuLEAST16);
    string_constant(SCNuLEAST32);
    string_constant(SCNuLEAST64);

    string_constant(SCNuFAST8);
    string_constant(SCNuFAST16);
    string_constant(SCNuFAST32);
    string_constant(SCNuFAST64);

    string_constant(SCNuMAX);
    string_constant(SCNuPTR);

    string_constant(SCNx8);
    string_constant(SCNx16);
    string_constant(SCNx32);
    string_constant(SCNx64);

    string_constant(SCNxLEAST8);
    string_constant(SCNxLEAST16);
    string_constant(SCNxLEAST32);
    string_constant(SCNxLEAST64);

    string_constant(SCNxFAST8);
    string_constant(SCNxFAST16);
    string_constant(SCNxFAST32);
    string_constant(SCNxFAST64);

    string_constant(SCNxMAX);
    string_constant(SCNxPTR);

    return 0;
}

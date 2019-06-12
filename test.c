#include "fft.h"

#include <stdlib.h>
#include <stdio.h>
#include <complex.h>
#include <math.h>

#define eps 0.000001
#define ASSERT_EQ(c, a, b) if (cabs((a) - (b)) > eps) { printf("FAILURE(%s) %.2f %+.2fi != %.2f %+.2fi\n", (c), creal((a)), cimag((a)), creal((b)), cimag((b))); goto fail; }

int main(int argc, char* argv[]) {
    /* do some simple tests */
    int x[2] = {1, 0};
    double complex X[2];

    fft(x, X, 2);

    ASSERT_EQ("X[0]", X[0], 1 + 0 * I);
    ASSERT_EQ("X[1]", X[1], 1 + 0 * I);

    int b[8] = {0, 1, 0, 0, 0, 0, 0, 0};
    double complex B[8];

    fft(b, B, 8);

    ASSERT_EQ("B[0]", B[0], 1 + 0 * I);
    ASSERT_EQ("B[1]", B[1], sqrt(2) / 2 - sqrt(2) * I / 2)
    ASSERT_EQ("B[2]", B[2], 0 - 1 * I)
    ASSERT_EQ("B[3]", B[3], - sqrt(2) / 2 - sqrt(2) * I / 2)
    ASSERT_EQ("B[4]", B[4], - 1 + 0 * I)
    ASSERT_EQ("B[5]", B[5], - sqrt(2) / 2 + sqrt(2) * I / 2)
    ASSERT_EQ("B[6]", B[6], 0 + 1 * I)
    ASSERT_EQ("B[7]", B[7], sqrt(2) / 2 + sqrt(2) * I / 2)

    int c[4] = {1, 3, 5, 7};
    double complex C[4];

    fft(c, C, 4);

    ASSERT_EQ("C[0]", C[0], 16);
    ASSERT_EQ("C[1]", C[1], -4 + 4*I);
    ASSERT_EQ("C[2]", C[2], -4);
    ASSERT_EQ("C[3]", C[3], -4 - 4*I);

    printf("all tests pass\n");
    return 0;

fail:
    printf("failed test\n");
    return 1;
}

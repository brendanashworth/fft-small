#include "fft.h"

#include <stdlib.h>
#include <stdio.h>
#include <complex.h>
#include <math.h>

#define eps 0.000001
int imageq(double complex a, double complex b) {
    double dr = creal(a) - creal(b);
    double dc = cimag(a) - cimag(b);

    return dr + dc < eps;
}

#define ASSERT_EQ(a, b) if (!imageq((a), (b))) goto fail;

int main(int argc, char* argv[]) {
    /* do some simple tests */
    int x[2] = {1, 0};
    double complex X[2];

    fft(x, X, 2);

    ASSERT_EQ(X[0], 1 + 0 * I);
    ASSERT_EQ(X[1], 1 + 0 * I);

    int b[8] = {0, 1, 0, 0, 0, 0, 0, 0};
    double complex B[8];

    fft(b, B, 8);

    ASSERT_EQ(B[0], 1 + 0 * I);
    ASSERT_EQ(B[1], sqrt(2) / 2 - sqrt(2) * I / 2)
    ASSERT_EQ(B[2], 0 - 1 * I)
    ASSERT_EQ(B[3], - sqrt(2) / 2 - sqrt(2) * I / 2)
    ASSERT_EQ(B[4], - 1 + 0 * I)
    ASSERT_EQ(B[5], - sqrt(2) / 2 + sqrt(2) * I / 2)
    ASSERT_EQ(B[6], 0 + 1 * I)
    ASSERT_EQ(B[7], sqrt(2) / 2 + sqrt(2) * I / 2)

    printf("all tests pass\n");
    return 0;

fail:
    printf("failed test\n");
    return 1;
}

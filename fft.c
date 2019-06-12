/* Fast Fourier Transform
 * Cooley-Tukey algorithm with 2-radix DFT
 */

#include <stdint.h>
#include <complex.h>

#define PI 3.14159265358979323846

void fft_slow(int* x, double complex* X, uint16_t N) {
    uint16_t n, k;

    // Iterate through, allowing X_K = sum_N of the complex frequencies.
    for (k = 0; k < N; k++) {
        for (n = 0; n < N; n++) {
            X[k] += x[n] * cexp(-2 * PI * I * n * k / N);
        }
    }
}

void fft_radix2(int* x, double complex* X, uint16_t N, uint16_t s) {
    uint16_t k;
    double complex t;

    // At the lowest level pass through (delta T=0 means no phase).
    if (N == 1) {
        X[0] = x[0];
        return;
    }

    // Cooley-Tukey: recursively split in two, then combine beneath.
    fft_radix2(x, X, N/2, 2*s);
    fft_radix2(x+s, X + N/2, N/2, 2*s);

    for (k = 0; k < N/2; k++) {
        t = X[k];
        X[k] = t + cexp(-2 * PI * I * k / N) * X[k + N/2];
        X[k + N/2] = t - cexp(-2 * PI * I * k / N) * X[k + N/2];
    }
}

void fft(int* x, double complex* X, uint16_t N) {
    fft_radix2(x, X, N, 1);
}

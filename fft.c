/* Fast Fourier Transform
 * Cooley-Tukey algorithm with 2-radix DFT
 */

#include <complex.h>
#include <math.h>

void fft_slow(int* x, double complex* X, int N) {
	int n, k;

	// Iterate through k = N times.
	for (k = 0; k < N; k++) {
		for (n = 0; n < N; n++) {
			X[k] += x[n] * cexp(-2 * M_PI * I * n * k / N);
		}
	}
}

void fft(int* x, double complex* X, int N) {
	fft_slow(x, X, N);
}

/* Fast Fourier Transform
 * Cooley-Tukey algorithm with 2-radix DFT
 */

#include <complex.h>

void fft_slow(int* x, double complex* X, int N);

void fft(int* x, double complex* X, int N);

/* Fast Fourier Transform
 * Cooley-Tukey algorithm with 2-radix DFT
 */

#include <stdint.h>
#include <complex.h>

void fft_slow(int* x, double complex* X, uint16_t N);

void fft(int* x, double complex* X, uint16_t N);
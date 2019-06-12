# Fast Fourier Transform

This is an implementation of the [Cooley-Tukey FFT algorithm](https://en.wikipedia.org/wiki/Cooley%E2%80%93Tukey_FFT_algorithm)
designed for embedded systems. It uses the 2-radix variation to grow with `O(n log n)` complexity.

### Usage
```c
/* Fast Fourier Transform
 * Cooley-Tukey algorithm with 2-radix DFT
 */

void fft_slow(int* x, double* X, int N);

void fft(int* x, double* X, int N);

```

### License
MIT

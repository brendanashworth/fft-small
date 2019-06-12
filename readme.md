# Fast Fourier Transform

This is an implementation of the [Cooley-Tukey FFT algorithm](https://en.wikipedia.org/wiki/Cooley%E2%80%93Tukey_FFT_algorithm)
designed for embedded systems. It uses the 2-radix variation to grow with `O(n log n)` complexity.

This implementation, unlike most found elsewhere, does not dynamically allocate memory on the heap and thus
is easier to use in embedded systems. It also has a deterministic runtime given any size sample.

### Usage
```c
/* Fast Fourier Transform
 * Cooley-Tukey algorithm with 2-radix DFT
 */

void fft_slow(int* x, double complex* X, uint16_t N);

void fft(int* x, double complex* X, uint16_t N);

```

### License
MIT

#include "fft.h"

#include <stdlib.h>
#include <stdio.h>
#include <complex.h>

int main(int argc, char* argv[]) {
	/* do some simple tests */
	int x[2] = {1, 0};
	double X[2];

	fft(x, X, 2);

	if (X[0] != 1 + 0 * I) {
		printf("X[0] != 1\n");
		exit(1);
	}
	if (X[1] != 1 + 0 * I) {
		printf("X[1] != 1\n");
		exit(1);
	}

	printf("all tests pass\n");
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define LAMBDA 2

int main(void)
{
	printf("%f\n", -log(1 - 1.0 * rand() / RAND_MAX) / LAMBDA);

	return 0;
}
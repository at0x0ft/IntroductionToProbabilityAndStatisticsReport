#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 12
#define MU 2
#define SIGMA 4

double genND(double mu, double sigma)
{
	int i = 0;
	double rdm = 0.0;

	for(i = 0; i < N; i++)
		rdm += 1.0 * rand() / RAND_MAX;

	return sqrt(sigma) * (rdm - 6) + mu;
}

int main(void)
{
	int i, n;

	printf("Input the number of random numbers you want to generate : ");
	scanf("%d", &n);

	FILE *fp = fopen("data4.csv", "w");
	if(fp == NULL)
	{
		printf("File open error.\n");
		exit(1);
	}

	for(i = 0; i < n; i++)
	{
		fprintf(fp, "%f\n", genND(MU, SIGMA));
	}

	fclose(fp);

	return 0;
}
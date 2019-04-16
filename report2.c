#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define X_0 1
#define A 2

double invPrtd(double rdm, double x_0, double a)
{
	return x_0 * pow(1 - rdm, -1 / a);
}

int main(void)
{
	int i, n;
	double rdm;

	printf("Input the number of random numbers you want to generate : ");
	scanf("%d", &n);

	FILE *fp = fopen("data2.csv", "w");
	if(fp == NULL)
	{
		printf("File open error.\n");
		exit(1);
	}

	for(i = 0; i < n; i++)
	{
		rdm = 1.0 * rand() / RAND_MAX;
		fprintf(fp, "%f\n", invPrtd(rdm, X_0, A));
	}

	fclose(fp);

	return 0;
}
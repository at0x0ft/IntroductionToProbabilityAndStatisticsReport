#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define LAMBDA 2
#define MAX_FILENAME_LENGTH 32

double invExd(double rdm, double lambda)
{
	return -log(1 - rdm) / lambda;
}

int main(void)
{
	int i, n;
	double rdm;

	printf("Input the number of random numbers you want to generate : ");
	scanf("%d", &n);

	FILE *fp = fopen("data.csv", "w");
	if(fp == NULL)
	{
		printf("File open error.\n");
		exit(1);
	}

	for(i = 0; i < n; i++)
	{
		rdm = 1.0 * rand() / RAND_MAX;
		fprintf(fp, "%f\n", invExd(rdm, LAMBDA));
	}

	fclose(fp);

	return 0;
}
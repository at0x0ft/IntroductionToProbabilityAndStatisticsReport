#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 13
#define LAMBDA 2.5
#define SIGMA 4

double factrial(int n)
{
	int i, ans = 1;
	for(i = 1; i <= n; i++)
		ans *= i;
	return 1.0 * ans;
}

int genPoD(double poissonCD[N])
{
	int i;
	double rdm = 1.0 * rand() / RAND_MAX;

	if(rdm < poissonCD[0])
		return 0;

	for(i = 0; i < N; i++)
	{
		if(rdm >= poissonCD[i] && rdm < poissonCD[i + 1])
			break;
	}

	printf("i:%d\n", i + 1);

	return i + 1;
}

int main(void)
{
	int i, n;
	double poissonCD[N];
	poissonCD[0] = exp(-LAMBDA);

	for(i = 1; i < N; i++)
	{
		poissonCD[i] = poissonCD[i - 1];
		poissonCD[i] += pow(LAMBDA, i) * exp(-LAMBDA) / factrial(i);
	}

	printf("Input the number of random numbers you want to generate : ");
	scanf("%d", &n);

	FILE *fp = fopen("data5.csv", "w");
	if(fp == NULL)
	{
		printf("File open error.\n");
		exit(1);
	}

	for(i = 0; i < n; i++)
	{
		fprintf(fp, "%d\n", genPoD(poissonCD));
	}

	fclose(fp);

	return 0;
}
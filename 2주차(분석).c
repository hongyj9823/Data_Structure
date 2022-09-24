//1¹ø
#pragma warning(disable: 4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int modulo(int a, int b);
int main()
{
	int n1 = 0;
	int n2 = 0;
	scanf("%d %d", &n1, &n2);
	printf("%d", modulo(n1, n2));
	return 0;
}
int modulo(int a, int b) {
	int i = 0;
	while (1)
	{
		if (a >= b)
		{
			a = a - b;

		}
		else
			break;
	}
	return a;
}
//2¹ø
#pragma warning(disable: 4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int mostOnes(int a[100][100], int n);
int main()
{
	int n = 0;
	int i = 0, j = 0;
	int a[100][100] = { 0 };
	int b[100] = { 0 };
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	printf("%d", mostOnes(a, n));
	return 0;
}
int mostOnes(int a[100][100], int n)
{
	int max = 0;
	int i = 0;
	int j = 0;
	while (1)
	{
		if (a[i][j] == 1)
		{
			j++;
		}
		else
		{
			i++;
			if (a[i][j] == 1)
			{
				max = i;
			}
		}
		if (j == n)
		{
			max = i;
			break;
		}
		if (i == n)
		{
			break;
		}
	}
	return max;
}
//3¹ø
#pragma warning(disable: 4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int *prefixAverages1(int X[], int n);
int *prefixAverages2(int X[], int n);
int main() {
	int *x = NULL;
	int *ans;
	int *an;
	int n = 0;
	int i = 0;
	scanf("%d", &n);
	x = (int*)malloc(n * sizeof(int));
	if (x == NULL)
	{
		printf("Not enough memory!");
		return -1;
	}
	for (i = 0; i < n; i++)
	{
		scanf("%d", &x[i]);
	}
	ans = prefixAverages1(x, n);
	an = prefixAverages1(x, n);
	for (ans = an; ans < an + n; ans++)
	{
		printf("%d ", *ans);
	}
	printf("\n");
	ans = prefixAverages2(x, n);
	an = prefixAverages2(x, n);
	for (ans = an; ans < an + n; ans++)
	{
		printf("%d ", *ans);
	}
	free(x);

	return 0;
}
int *prefixAverages1(int X[], int n) {
	int *A = NULL;
	int i = 0;
	double sum = 0.0;
	int j = 0;
	A = (int*)malloc(n * sizeof(int));
	if (A == NULL)
	{
		printf("Not enough memory!");
		return -1;
	}
	for (i = 0; i <= n - 1; i++)
	{
		sum = 0.0;
		for (j = 0; j <= i; j++)
		{
			sum = sum + (X[j] * 1.0);
		}
		A[i] = (int)((sum / (i + 1)) + 0.5);
	}


	return A;
}
int *prefixAverages2(int X[], int n) {
	int *A = NULL;
	int i = 0;
	double sum = 0.0;
	int j = 0;
	A = (int*)malloc(n * sizeof(int));
	if (A == NULL)
	{
		printf("Not enough memory!");
		return -1;
	}
	for (i = 0; i <= n - 1; i++)
	{


		sum = sum + (X[i] * 1.0);

		A[i] = (int)((sum / (i + 1)) + 0.5);
	}

	return A;
}


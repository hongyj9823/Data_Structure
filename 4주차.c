//1번
#pragma warning(disable: 4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int N = 0;
	int ki = 0;
	int x[1000] = { 0 };
	int *p1 = x;
	int swap = 0;
	int x2[1000] = { 0 };
	int *p3 = x;
	int k = 0;
	int i = 0;
	int cnt = 0;
	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		scanf("%d", &x[i]);
	}
	scanf("%d", &k);
	for (i = 0; i < (2 * k); i++)
	{
		scanf("%d", &x2[i]);
	}
	for (ki = 0; ki <= 2 * k; ki += 2)
	{
		cnt = 0;
		for (p1 = x + x2[ki], p3 = x + x2[ki + 1]; p1 <= x + x2[ki + 1], p3 >= x + x2[ki]; p1++, p3--)
		{
			swap = *p1;
			*p1 = *p3;
			*p3 = swap;
			cnt++;
			if (((x2[ki + 1] - x2[ki]) / 2) + 1 == cnt)
				break;
		}
	}
	for (i = 0; i < N; i++)
	{
		printf(" %d", x[i]);
	}
	printf("\n");
	return 0;
}
//2번
#pragma warning(disable: 4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int N = 0;
	int x[100] = { 0 };
	int ans = 0;
	int x2[100] = { 0 };
	int i = 0;
	int swap = 0;

	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		scanf("%d", &x[i]);
	}
	scanf("%d", &ans);
	for (i = 0; i < ans; i++)
	{
		scanf("%d", &x2[i]);
	}
	swap = x[x2[0]];
	for (i = ans - 1; i > 1; i--)
	{

		x[x2[i]] = x[x2[i - 1]];
	}//뒤로부터 당겨져 와야함
	x[x2[1]] = swap;
	for (i = 0; i < N; i++)
	{
		printf(" %d", x[i]);
	}
	return 0;
}


//3번
#pragma warning(disable: 4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int N = 0;
	int i = 0;
	int j = 0;
	int k = 1;
	int x[100][100] = { 0 };
	scanf("%d", &N);
	while (k <= N * N)

	{
		if (i % 2 == 0)
		{
			for (j = 0; j < N; j++)
			{
				x[i][j] = k;
				k++;
			}
			i++;

		}
		else
		{
			for (j = N - 1; j >= 0; j--)
			{
				x[i][j] = k;
				k++;
			}

			i++;
		}
	}
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			printf(" %d", x[i][j]);
		}
		printf("\n");
	}
	return 0;
}


//4번
#pragma warning(disable:4996)
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int arr[100][100], i, j, n, m, a = 0, b = -1, k = 1, cnt = 1, nn, mm;
	scanf("%d %d", &n, &m);
	nn = n;
	mm = m;

	while (1)
	{
		if (cnt == nn * mm + 1)
			break;

		for (i = 0; i < m; i++)
		{
			b += k;
			arr[a][b] = cnt++;

		}
		n--;
		if (cnt == nn * mm + 1)
			break;
		for (i = 0; i < n; i++)
		{
			a += k;
			arr[a][b] = cnt++;
		}
		m--;

		k *= -1;
	}
	for (i = 0; i < nn; i++) {
		for (j = 0; j < mm; j++)
		{
			printf(" %d", arr[i][j]);
		}
	}
}
//5번
#pragma warning(disable: 4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int k = 1;
	int i = 0;
	int j = 0;
	int N = 0;
	int M = 0;
	int sum = 0;
	int t = 1;
	int x[100][100] = { 0 };
	scanf("%d %d", &N, &M);
	if (N < M)
	{
		for (sum = 0; sum < N; sum++)
		{
			for (i = 0; i <= sum; i++)
			{
				x[i][sum - i] = k;
				k++;
			}
		}
		for (; sum <= M + N - 1; sum++)
		{
			for (i = 0; i <= sum; i++)
			{
				if ((sum - i) < M)

				{

					x[i][sum - i] = k;
					k++;
					if (i == N - 1)
						break;
				}

			}

		}

	}
	else
	{
		for (sum = 0; sum < M; sum++)
		{
			for (i = 0; i <= sum; i++)
			{
				x[i][sum - i] = k;
				k++;
			}
		}
		for (; sum <= M + N - 1; sum++)
		{
			for (i = t; i <= sum; i++)
			{

				{

					x[i][sum - i] = k;
					k++;
					if (sum - i == 0)
						break;
					if (i == N - 1)
						break;
				}

			}
			t++;

		}

	}
	for (i = 0; i<N; i++)
	{
		for (j = 0; j < M; j++)
		{
			printf(" %d", x[i][j]);
		}
		printf("\n");
	}


	return 0;
}





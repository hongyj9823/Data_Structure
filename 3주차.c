//1번
int sum(int N);
int main()
{
	int N = 0;
	scanf("%d", &N);
	printf("%d", sum(N));
	return 0;
}
int sum(int N)
{
	if (N == 1)
		return 1;
	else
		return sum(N - 1) + N;
}
//2번
int total(int N);
int main()
{
	int N = 0;
	scanf("%d", &N);
	total(N);
	return 0;
}
int total(int N)
{
	int i = 0;
	int N2 = N % 10;
	int N3 = N;

	while (N3 != 0)
	{
		N3 = N3 / 10;
		i++;
	}
	if (i != 0)
	{
		N = N / 10;
		total(N);
		printf("%d\n", N2);
	}
	return 0;
}
//3번
int total(int N);
int main()
{
	int N = 0;
	scanf("%d", &N);
	total(N);
	return 0;
}
int total(int N)
{
	int i = 0;
	int N2 = N % 10;
	int N3 = N;

	while (N3 != 0)
	{
		N3 = N3 / 10;
		i++;
	}
	if (i != 0)
	{
		N = N / 10;
		printf("%d\n", N2);
		total(N);
	}

	return 0;
}
//4번
int total(int a[], int N);
int main()
{
	int N = 0;
	int a[20] = { 0 };
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &a[i]);

	}
	printf("%d", total(a, N));
	return 0;
}
int total(int a[], int N)
{
	//동생들의 최댓값과 마지막 수를 비교
	int max = 0;
	int ans = 0;
	if (N != 0)
	{

		total(a, N - 1);
		for (int i = 0; i < N - 1; i++)
		{
			if ((a[i]) > max)
			{
				max = a[i];
			}
		}


		ans = max > a[N - 1] ? max : a[N - 1];
	}

	return ans;
}
//5번
void hanoi(int N, char A, char B, char C);
int main()
{
	int N = 0;
	char A = 'A';
	char B = 'B';
	char C = 'C';
	scanf("%d", &N);
	hanoi(N, A, B, C);


	return 0;
}
void hanoi(int N, char A, char B, char C)
{
	if (N == 1)
	{
		printf("%c %c\n", A, C);
	}
	else
	{
		hanoi(N - 1, A, C, B);
		printf("%c %c\n", A, C);
		hanoi(N - 1, B, A, C);
	}

	return 0;
}
//6번
int gcd(int a, int b);
int main() {
	int a = 0;
	int b = 0;
	scanf("%d %d", &a, &b);
	printf("%d", gcd(a, b));
	return 0;
}
int gcd(int a, int b) {
	int r = a % b;
	if (r == 0)
	{
		return b;
	}
	else
	{
		gcd(b, r);
	}

}
//7번
int find(char str[], int N, char ch, int result);
int main() {
	char str[100] = "";
	char ans = '\0';
	int len = 0;
	int result = 0;

	scanf("%s", str);
	len = strlen(str);
	getchar();
	scanf("%c", &ans);
	printf("%d", find(str, len, ans, result));

	return 0;
}
int find(char str[], int N, char ch, int result)
{

	if (N == 0)
	{
		return result;
	}
	else
	{
		N = N - 1;
		if (str[N] == ch)

		{
			result++;
		}
		find(str, N, ch, result);

	}

}




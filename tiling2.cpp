#include <cstdio>

const int divisor= 1000000007;
int num_fill_square[101];

void fill_square()
{
	for (int i = 0; i <= 2; i++)
	{
		num_fill_square[i] = i;
	}
	for (int i = 3; i <= 100; i++)
	{
		num_fill_square[i] = (num_fill_square[i - 1] + num_fill_square[i - 2]) % divisor;
	}
}

int main()
{
	int test_case = 0;

	scanf("%d", &test_case);
	fill_square();

	for (int t = 0; t < test_case; t++)
	{
		int n;
		scanf("%d", &n);
		printf("%d\n", num_fill_square[n]);
	}
	return 0;
}
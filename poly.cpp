#include <cstdio>
#include <string.h>

const int MOD = 10000000;
int cache[101][101];


int poly(int n, int first)
{ 
	int & ret = cache[n][first];

	if (n == first)
		return 1;

	if (ret != -1)
		return ret;

	ret = 0;

	for (int s = 1; s <= n - first; s++)
	{
		ret += ((poly(n - first, s) % MOD) * (first + s - 1)) % MOD;
		ret %= MOD;
	}

	return ret;
}
int main()
{
	freopen("sample.txt", "r", stdin);

	int test_case;
	scanf("%d", &test_case);

	for (int t = 0; t < test_case; t++)
	{
		memset(cache, -1, sizeof(cache));
		int n;
		scanf("%d", &n);

		int sum = 0; 
		for (int i = 1; i <= n; i++)
		{
			sum += poly(n, i);
			sum %= MOD;
		}
		printf("%d\n", sum);
	}

	return 0;
}
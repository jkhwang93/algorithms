#include <cstdio>

const int MOD = 1000000007;
int tile[101];

void init_tile()
{
	int i = 0;
	tile[0] = tile[1] = 1;
	for (i = 2; i <= 100; i++)
	{
		tile[i] = (tile[i - 1] + tile[i - 2]) % MOD;
	}
}

int asymtiling(int num)
{
	int  ret;
	if (num == 1 || num == 2)
		return 0;

	if (num % 2) // odd num
	{
		ret = (tile[num] - tile[num / 2] + MOD) %MOD;
	}
	else
	{
		ret = (((tile[num] - tile[num / 2] + MOD) % MOD) - tile[(num / 2) - 1] + MOD) % MOD;
	}

	return ret;
}

int main()
{
	int test;
	freopen("sample.txt", "r", stdin);
	scanf("%d", &test);
	init_tile();
	for (int t = 0; t < test; t++)
	{
		int num;
		scanf("%d", &num);
		printf("%d\n", asymtiling(num));
	}
	return 0;
}
#include <cstdio>
#include <cstring>

int rainy_day_length, well_depth;
double cache[1001][2000+2000];

double cal_escape(int date, int depth)
{
	double & ret = cache[date][depth+2000];

	if (ret != -1.0)
		return ret;

	if (date == 0)
	{
		return ret = depth <= 0 ? 1.0 : 0.0;
	}

	ret = 0.0;

	ret += cal_escape(date - 1, depth - 1) / 4;
	ret += (3 * cal_escape(date - 1, depth - 2)) / 4;

	return ret ;
}

int main()
{
	int test_case;
	freopen("sample.txt", "r", stdin);
	scanf("%d", &test_case);

	for (int t = 0; t < test_case; t++)
	{
		for (int i = 0; i < 1001; i++)
		{
			for (int j = 0; j < 4000; j++)
			{
				cache[i][j] = -1.0;
			}
		}
		scanf("%d %d", &well_depth, &rainy_day_length);
		
		printf("%.10f\n", cal_escape(rainy_day_length, well_depth));
	}

	return 0;
}
#include <cstdio>
#include <cstring>
double cache[1001][1001];

double cal_escape(int day, int depth)
{
	double & ret = cache[day][depth];
	
	if (day == 0)
		return ret = depth <= 0 ? 1.0 : 0.0;

	if (depth <= 0)
		return 1.0;

	if (ret >= 0.0)
		return ret;

	ret = 1.0;
	ret = 0.75*cal_escape(day - 1, depth - 2) + 0.25*cal_escape(day - 1, depth - 1);
	
	return ret;
}

void cache_init()
{
	for (int i = 0; i < 1001; i++)
		for (int j = 0; j < 1001; j++)
			cache[i][j] = -1.0;
}
int main()
{
	int test;
	freopen("sample.txt", "r", stdin);
	scanf("%d", &test);
	for (int t = 0; t < test; t++)
	{
		cache_init();
		int rainy_day_length, well_depth;
		scanf("%d %d", &well_depth, &rainy_day_length);

		printf("%.10f\n" , cal_escape(rainy_day_length,well_depth));
	}
	return 0;
}
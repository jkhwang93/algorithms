#include <cstdio>
#include <cstring>
#include <algorithm>

int triangle[101][101];
int tri_path[101][101][2];
int n;

void cal_tri_path()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j < i + 1; j++)
		{
			if (tri_path[i - 1][j][0] > tri_path[i - 1][j - 1][0])
			{
				tri_path[i][j][0] = tri_path[i - 1][j][0] + triangle[i][j];
				tri_path[i][j][1] = tri_path[i - 1][j][1];
			}
			else if (tri_path[i - 1][j][0] < tri_path[i - 1][j - 1][0])
			{
				tri_path[i][j][0] = tri_path[i - 1][j - 1][0] + triangle[i][j];
				tri_path[i][j][1] = tri_path[i - 1][j - 1][1];
			}
			else
			{
				tri_path[i][j][0] = tri_path[i - 1][j][0] + triangle[i][j];
				tri_path[i][j][1] = tri_path[i - 1][j][1] + tri_path[i - 1][j - 1][1];
			}
		}
	}
	return;
}
int cal_max()
{
	int max = -1;
	int count = 0;
	for (int i = 1; i <= n; i++)
	{
		if (max < tri_path[n][i][0])
		{
			max = tri_path[n][i][0];
			count = tri_path[n][i][1];
		}
		else if (max == tri_path[n][i][0])
		{
			count += tri_path[n][i][1];
		}
	}
	return count;
}
int main()
{
	//freopen("sample.txt", "r", stdin);
	int test_case = 0;
	scanf("%d", &test_case);

	for (int t = 0; t < test_case; t++)
	{
		memset(triangle, 0, sizeof(triangle));
		memset(tri_path, 0, sizeof(tri_path));

		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j < i + 1; j++)
			{
				scanf("%d", &triangle[i][j]);
			}
		}
		tri_path[0][0][1] = 1;
		cal_tri_path();
		printf("%d\n",cal_max());

	}

	return 0;
}
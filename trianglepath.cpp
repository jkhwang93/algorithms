#include <stdio.h>
//
//  Problem : https://algospot.com/judge/problem/read/TRIANGLEPATH
//
//  Created by JK on 2018. 1. 28.
//

#include <string.h>

const int MAX_SIZE = 100;

int triangle[MAX_SIZE + 1][MAX_SIZE + 1];
int sum_path[2][MAX_SIZE+1];
int size_triangle;

void sum_triangle(int index, int depth)
{
	if (depth == size_triangle + 1)
		return;

	int prev_sum;
	for (int i = 1; i < depth+1; i++)
	{
		prev_sum = sum_path[!index][i - 1] > sum_path[!index][i] ? sum_path[!index][i - 1] : sum_path[!index][i];
		sum_path[index][i] = prev_sum + triangle[depth][i];
	}
	sum_triangle(!index, depth + 1);
	return;
}
int max_sum_path(int size_bottom)
{
	sum_triangle(0, 1);

	int index = (size_bottom + 1) % 2;
	int max = 0;
	for (int i = 1; i <= size_triangle; i++)
	{
		max = max > sum_path[index][i] ? max : sum_path[index][i];
	}
	return max;
}
int main()
{
	freopen("sample.txt", "r", stdin);
	int test_case;

	scanf("%d", &test_case);
	for (int t = 0; t < test_case; t++)
	{
		memset(triangle, -1, sizeof(triangle));
		memset(sum_path, 0, sizeof(sum_path));

		scanf("%d", &size_triangle);

		for (int i = 1; i <= size_triangle; i++)
		{
			for (int j = 1; j < i+1; j++)
			{
				scanf("%d", &triangle[i][j]);
			}
		}

		printf("%d\n", max_sum_path(size_triangle));

	}
	return 0;
}
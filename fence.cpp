//
//  Problem : https://algospot.com/judge/problem/read/FENCE
//
//  Created by JK on 2018. 1. 23.
//

#include <stdio.h>

const int MAX_FENCE = 20000;

int fence[MAX_FENCE];

int width;
int max_area;

int cal_area(int height)
{
	int max_count = 0;
	int count = 0;
	
	if (width * height < max_area)
		return 0;

	for (int i = 0; i < width; i++)
	{
		if (fence[i] < height)
		{
			max_count = max_count > count ? max_count : count;
			count = 0;
		}
		else
		{
			count++;
		}
	}
	max_count = max_count > count ? max_count : count;
	
	return (max_count * height);
}

int main()
{
	freopen("sample.txt", "r", stdin);
	int test_case = 0;
	scanf("%d", &test_case);

	for (int i = 0; i < test_case; i++)
	{
		int max_height = 0;
		int area;
		bool is_height[MAX_FENCE] = { false };
		
		max_area = 0;
		
		scanf("%d", &width);
		for (int j = 0; j < width; j++)
		{
			scanf("%d", &fence[j]);
			is_height[fence[j]] = true;
			max_height = max_height < fence[j] ? fence[j] : max_height;
		}
		
		for (int j = max_height; j > 0; j--)
		{
			if (is_height[j])
			{
				area = cal_area(j);
				max_area = max_area < area ? area : max_area;
			}
		}
		printf("%d\n",max_area);
	}
	return 0;
}
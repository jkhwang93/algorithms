//
//  Problem : https://algospot.com/judge/problem/read/FENCE
//
//  Created by JK on 2018. 1. 26.
//

#include <stdio.h>

const int MAX_WIDTH = 20000, MAX_HEIGHT = 10000;

int fence_height[MAX_WIDTH];

int cal_area(int left, int right)
{
	if (left == right)
		return fence_height[left];

	int max_area , max_left_area, max_right_area, max_middle_area;
	int middle = left + (right - left) / 2;

	max_left_area = cal_area(left, middle);
	max_right_area = cal_area(middle+1, right);
	max_area = max_left_area > max_right_area ? max_left_area : max_right_area;

	int low = middle;
	int high = middle + 1;

	int height = fence_height[low] < fence_height[high] ? fence_height[low] : fence_height[high];
	int area = 0;
	max_middle_area = 0;
	
	while (left <= low || right >= high)
	{
		area = ((high - low) + 1)*height;
		max_middle_area = max_middle_area > area ? max_middle_area : area;

		if (left == low && right == high)
			break;
		
		if (high == right || ((low != left) && (fence_height[low - 1] > fence_height[high + 1])))
		{
			height = height < fence_height[low - 1] ? height : fence_height[low - 1];
			low--;
		}
		else
		{
			height = height < fence_height[high + 1] ? height : fence_height[high + 1];
			high++;
		}
	}

	max_area = max_area > max_middle_area ? max_area : max_middle_area;

	return max_area;
}

int main()
{
	freopen("sample.txt", "r", stdin);

	int test_case;
	scanf("%d", &test_case);

	for (int i = 0; i < test_case; i++)
	{
		int width;
		scanf("%d", &width);

		for (int j = 0; j < width; j++)
		{
			scanf("%d", &fence_height[j]);
		}

		printf("%d\n", cal_area(0, width-1));
	}
}
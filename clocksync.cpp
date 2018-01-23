//
//  Problem : https://algospot.com/judge/problem/read/CLOCKSYNC
//
//  Created by JK on 2018. 1. 23.
//

#include <stdio.h>

const int CLOCK_SIZE = 16;
const int SWITCH_NUM = 10;
const int MAX_LINK = 5;

const int PLUS = 1;
const int MINUS = 0;
const int MAX = 987654321;

const int clock_link[SWITCH_NUM][MAX_LINK + 1] = {
{0,1,2,-1},
{3,7,9,11,-1},
{4,10,14,15,-1},
{0,4,5,6,7,-1},
{6,7,8,10,12,-1},
{0,2,14,15,-1},
{3,14,15,-1},
{4,5,7,14,15,-1},
{1,2,3,4,5,-1},
{3,4,5,9,13,-1} };

int clock[CLOCK_SIZE];
int min_click_sum;

void count_clock(int button, int click_num, int flag)
{
	int index = 0;

	while (clock_link[button][index] != -1)
	{
		if (flag == PLUS)
			clock[clock_link[button][index]] = (clock[clock_link[button][index]] + (3 * click_num) + 12) % 12;
		else
			clock[clock_link[button][index]] = (clock[clock_link[button][index]] - (3 * click_num) + 12) % 12;
		
		index++;
	}
}

int click_switch(int button , int click_sum)
{
	if (click_sum > min_click_sum)
		return min_click_sum;
		
	if (button == SWITCH_NUM)
	{
		int sum_clock,index;
		sum_clock = index = 0;
		while (index < CLOCK_SIZE && !sum_clock)
		{
			sum_clock += clock[index];
			index++;
		}
		if(!sum_clock)
			min_click_sum = min_click_sum < click_sum ? min_click_sum : click_sum;
		
		return min_click_sum;
	}

	for (int i = 0; i < 4; i++)
	{
		count_clock(button, i, PLUS);
		click_switch(button + 1, click_sum + i);
		count_clock(button, i, MINUS);
	}

	return min_click_sum;
}

int main()
{
	//freopen("sample.txt", "r", stdin);
	int test_case;
	scanf("%d", &test_case);

	for (int i = 0; i < test_case; i++)
	{
		min_click_sum = MAX;
		for (int j = 0; j < CLOCK_SIZE; j++)
		{
			scanf("%d", &clock[j]);
		}

		click_switch(0,0);
		
		if (min_click_sum == MAX)
			min_click_sum = -1;

		printf("%d\n", min_click_sum);
	}
	return 0;
}
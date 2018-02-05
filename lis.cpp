//
//  Problem : https://algospot.com/judge/problem/read/LIS
//
//  Created by JK on 2018. 2. 5.
//

#include <stdio.h>
#include <string.h>

int sequence[500];
int max_subsequence[501];

int check_subsequence(int index, int length)
{
	if (sequence[index] == 0)
		return length;

	int location;
	for (location = length; location > 0; location--)
	{
		if (max_subsequence[location] < sequence[index])
			break;
	}

	max_subsequence[location + 1] = sequence[index];
	length = length > location + 1 ? length : (location + 1);

	length = check_subsequence(index + 1, length);

	return length;
}

int main()
{
	//freopen("sample.txt", "r", stdin);
	int test_case;
	scanf("%d", &test_case);

	for (int i = 0; i < test_case; i++)
	{
		int num;
		scanf("%d", &num);
		memset(max_subsequence, 0, sizeof(max_subsequence));
		memset(sequence, 0, sizeof(sequence));
		
		for (int j = 0; j < num; j++)
		{
			scanf("%d", &sequence[j]);
		}

		printf("%d\n", check_subsequence(0, 0));
	}
	return 0;
}
#include <stdio.h>

char str[1001];

void change_arr(int prev, int last, int end)
{

	char change_arr[1001] = { 0 };
	int index = 0;

	for (int i = last; i < end; i++)
	{
		change_arr[index] = str[i];
		index++;
	}
	for (int i = prev; i < last; i++)
	{
		change_arr[index] = str[i];
		index++;
	}

	index = 0;
	for (int i = prev; i < end; i++)
	{
		str[i] = change_arr[index];
		index++;
	}

	return;
}

int revert_tree(int index)
{
	if (str[index] != 'x')
	{
		return 1;
	}

	int length[4] = { 0 };
	int location[4] = { 0 };
	
	int total_length = 1; // 'x' current length

	for (int i = 0; i < 4; i++)
	{
		location[i] = index + total_length;
		length[i] = revert_tree(location[i]);
		total_length += length[i];
	}
	change_arr(location[0], location[2], index+total_length);

	return total_length;
}

int main()
{
	int test_case;
	//freopen("sample.txt", "r", stdin);
	scanf("%d", &test_case);
	for (int t = 0; t < test_case; t++)
	{
		scanf("%s", str);
		revert_tree(0);
		printf("%s\n", str);
	}
	return 0;
}
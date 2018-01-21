//
//  Problem : https://algospot.com/judge/problem/read/QUADTREE
//
//  Created by JK on 2018. 1. 21.
//

#include <stdio.h>

const int MAX = 1000;
char tree[MAX+1];

void change_arr(int first, int second, int end)
{

	char change_tree[MAX+1] = { 0 };
	int index = 0;

	for (int i = second; i < end; i++)
	{
		change_tree[index] = tree[i];
		index++;
	}
	for (int i = first; i < second; i++)
	{
		change_tree[index] = tree[i];
		index++;
	}

	index = 0;
	for (int i = first; i < end; i++)
	{
		tree[i] = change_tree[index];
		index++;
	}
	return;
}

void revert_tree(int index, int& revert_size)
{
	if (tree[index] != 'x')
	{
		revert_size = 1;
		return;
	}

	int node_length[4] = { 0 };
	int node_index[4] = { 0 };
	
	int total_length = 1; // 'x' length

	for (int i = 0; i < 4; i++)
	{
		node_index[i] = index + total_length;
		revert_tree(node_index[i], node_length[i]);
		total_length += node_length[i];
	}

	change_arr(node_index[0], node_index[2], index+total_length);

	revert_size = total_length;
	return;
}

int main()
{
	int test_case;
	//freopen("sample.txt", "r", stdin);
	scanf("%d", &test_case);
	for (int t = 0; t < test_case; t++)
	{
		int revert_length = 0;

		scanf("%s", tree);
		revert_tree(0, revert_length);
		printf("%s\n", tree);
	}
	return 0;
}
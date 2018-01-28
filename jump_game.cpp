//
//  Problem : https://algospot.com/judge/problem/read/JUMPGAME
//
//  Created by JK on 2018. 1. 28.
//

#include <stdio.h>
#include <string.h>

const int MAX_SIZE = 100;

int board[MAX_SIZE + 1][MAX_SIZE + 1];
int is_jump_possible[MAX_SIZE + 1][MAX_SIZE + 1];

int board_size;

inline bool is_out_of_area(int y, int x)
{
	return ((y >= board_size) || (x >= board_size));
}
int is_reachable(int y, int x)
{
	if (is_out_of_area(y, x))
		return 0;

	if (is_jump_possible[y][x] != -1)
		return is_jump_possible[y][x];

	int& ret = is_jump_possible[y][x];

	if (y == (board_size - 1) && x == (board_size - 1))
		return ret = 1;

	return ret = (is_reachable(y + board[y][x], x) || is_reachable(y, x + board[y][x]));
}

int main()
{
	freopen("sample.txt", "r", stdin);
	int test_case;

	scanf("%d", &test_case);
	for (int t = 0 ; t < test_case ; t++) 
	{
		memset(board, -1, sizeof(board));
		memset(is_jump_possible, -1, sizeof(is_jump_possible));

		scanf("%d", &board_size);

		for (int i = 0; i < board_size; i++)
		{
			for (int j = 0; j < board_size; j++)
			{
				scanf("%d", &board[i][j]);
			}
		}
		
		printf("%s\n", is_reachable(0, 0) == 1 ? "YES" : "NO");
	}

	return 0;
}
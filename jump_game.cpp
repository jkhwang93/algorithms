//
//  Problem : https://algospot.com/judge/problem/read/JUMPGAME
//
//  Created by JK on 2018. 1. 28.
//

#include <stdio.h>
#include <string.h>

const int MAX_SIZE = 100;

int board[MAX_SIZE + 1][MAX_SIZE + 1];
bool is_jump_possible[MAX_SIZE + 1][MAX_SIZE + 1];

int board_size;

inline bool is_out_of_area(int y, int x)
{
	return ((y >= board_size) || (x >= board_size));
}
bool jump(int y, int x)
{
	if (is_out_of_area(y, x))
		return false;

	if (!is_jump_possible[y][x])
		return false;
	
	if (board[y][x] == 0)
		return true;

	bool& ret = is_jump_possible[y][x];

	return ret = (jump(y + board[y][x], x) || jump(y, x + board[y][x]));
}

int main()
{
	freopen("sample.txt", "r", stdin);
	int test_case;

	scanf("%d", &test_case);
	for (int t = 0 ; t < test_case ; t++) 
	{
		memset(board, -1, sizeof(board));
		memset(is_jump_possible, true, sizeof(is_jump_possible));

		scanf("%d", &board_size);

		for (int i = 0; i < board_size; i++)
		{
			for (int j = 0; j < board_size; j++)
			{
				scanf("%d", &board[i][j]);
			}
		}
		
		printf("%s\n", jump(0, 0) ? "YES" : "NO");
	}

	return 0;
}
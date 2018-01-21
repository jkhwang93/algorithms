#include <stdio.h>
#include <string.h>

char board[21][21];
const int tile[4][3][2] = { { { 0,0 },{ 1,0 },{ 0,1 } },
					{ { 0,0 },{ 0,1 },{ 1,1 } },
					{ { 0,0 },{ 1,0 },{ 1,1 } },
					{ { 0,0 },{ 1,0 },{ 1,-1 } } };

int W, H;

inline bool is_out_of_range(int y, int x)
{
	return !(y >= 0 && y < H && x >= 0 && x < W);
}
inline bool is_possible(int y , int x)
{
	if (is_out_of_range(y, x))
	{
		return false;
	}
	if (board[y][x] != '.')
	{
		return false;
	}

	return true;
}

int solve(int y, int x)
{
	int res = 0;

	y = y + x / W;
	x = x % W;
	
	if (x == 0 && y == H) 
	{
		return 1;
	}

	if (board[y][x] != '.') 
	{
		return solve(y, x + 1);
	}

	for (int i = 0; i < 4; i++)
	{
		int check_flag = 1;

		for (int j = 0; j < 3; j++)
		{
			
			if(! is_possible(y + tile[i][j][0], x + tile[i][j][1]))
			{
				check_flag = 0;
				break;
			}
		}
		if (check_flag) {
			for (int j = 0; j < 3; j++)
			{
				board[y + tile[i][j][0]][x + tile[i][j][1]] = '#';
			}

			res += solve(y, x + 1);

			for (int j = 0; j < 3; j++) 
			{
				board[y + tile[i][j][0]][x + tile[i][j][1]] = '.';
			}
		}
	}
	return res;
}

int main()
{
	int test_case;

	//freopen("sample.txt", "r", stdin);
	scanf("%d", &test_case);
	
	for (int t = 0; t < test_case; ++t)
	{
		memset(board, 0, sizeof(char) * 21 * 21);
		scanf("%d %d", &H, &W);

		for (int i = 0; i < H; ++i)
		{
			scanf("%s", board[i]);
		}
		printf("%d\n", solve(0, 0));
	}

	return 0;
}
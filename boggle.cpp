#include <stdio.h>
#include <string.h>

#define LINE 5
#define MAX_LENGTH 10

char game[6][6];
char answer[10][11];
int depth_flag[5][5][10]; // depth_flag[y][x][flag]

int dy[8] = { 1,1,1,0,-1,-1,-1,0 };
int dx[8] = { 1,0,-1,-1,-1,0,1,1 };

void clear_flag_arr()
{
	memset(depth_flag, 0, sizeof(int)*LINE*LINE*MAX_LENGTH);
	return ;
}

int check(int y, int x, int index, int depth)
{
	if (answer[index][depth] == '\0')
		return 1;

	/* if the flag was checked, no need to check 8 direction from the current position.
	already checked impossible. */
	if (depth_flag[y][x][depth]) 
		return 0;

	int res; 

	for (int i = 0; i < 8; i++)
	{
		if (y + dy[i] >= LINE || y + dy[i] < 0 || x + dx[i] >= LINE || x + dx[i] < 0)
			continue;
		if (game[y + dy[i]][x + dx[i]] == answer[index][depth])
		{
			res = check(y + dy[i], x + dx[i], index, depth + 1);
			if (res)
				return 1;
		}
	}

	depth_flag[y][x][depth] = 1;
	
	return 0;
}
int check_answer(int index)
{
	int res = 0;

	for (int y = 0; y < LINE; y++) {
		for (int x = 0; x < LINE; x++) {
			if (game[y][x] == answer[index][0])
				res = check(y, x, index, 1);

			if (res)
				return 1;
		}
	}


	return 0;
}

int main()
{
	//freopen("sample.txt", "r", stdin);
	
	int T;
	scanf("%d", &T);

	for (int test = 0; test < T; test++)
	{
		for (int i = 0; i < LINE; i++)
			scanf("%s", game[i]);

		int num_answer;
		scanf("%d", &num_answer);

		for (int i = 0; i < num_answer; i++)
			scanf("%s", answer[i]);

		int res;
		for (int i = 0; i < num_answer; i++)
		{
			res = check_answer(i);
			printf("%s %s\n", answer[i], res ? "YES" : "NO");
			clear_flag_arr();
		}
	}
	return 0;
}
#include <stdio.h>
#define MAX_STUDENT 10
#define MAX_PAIR (MAX_STUDENT*(MAX_STUDENT-1))/2

int pair[MAX_STUDENT][MAX_STUDENT];

void clear_arr()
{
	for (int i = 0; i < MAX_STUDENT; i++)
		for (int j = 0; j < MAX_STUDENT; j++)
			pair[i][j] = 0;

	return ;
}

void check_pair(int * need_pair, int student, int num_student, int* sum)
{
	if (student == num_student-1) {
		*sum += 1;
		return;
	}

	if (need_pair[student])
	{
		check_pair(need_pair, student + 1, num_student, sum);
		return ;
	}
	

	for (int i = student+1; i < num_student; i++)
	{
		if (pair[student][i] && need_pair[i] == 0)
		{
			need_pair[student] = 1;
			need_pair[i] = 1; 

			check_pair(need_pair, student + 1, num_student, sum);

			need_pair[student] = 0;
			need_pair[i] = 0;
		}
	}

	return ;
}

int main()
{
	int test_case, T;
	int num_student, pair_student;
	int student_a, student_b;
	int sum;
	//freopen("sample.txt", "r", stdin);

	scanf("%d", &T);

	for (test_case = 0; test_case < T; test_case++)
	{
		int res = 0; 
		int need_pair[MAX_STUDENT] = { 0 }; // 0 value is needed pair, 1 valude is already had pair.

		scanf("%d %d", &num_student, &pair_student);
		for (int i = 0; i < pair_student; i++)
		{
			scanf("%d %d", &student_a, &student_b);
			if (student_a < student_b)
				pair[student_a][student_b] = 1;
			else
				pair[student_b][student_a] = 1;
		}
		
		sum = 0;
		check_pair(need_pair, 0, num_student, &sum);
		printf("%d\n", sum);

		clear_arr();
	}
	return 0;
}

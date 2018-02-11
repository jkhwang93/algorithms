#include <cstdio>
#include <cstring>
#include <algorithm>

const int SEQUENCE_LENGTH = 101;
const long long int MIN = -11987654321;

long long int A_sequence[SEQUENCE_LENGTH];
long long int B_sequence[SEQUENCE_LENGTH];
int cache[SEQUENCE_LENGTH][SEQUENCE_LENGTH];
int A_num, B_num;

int join_lis(int a_index, int b_index)
{
	int & ret = cache[a_index][b_index];

	if (ret != -1)
		return ret;
	
	long long int max = std::max(A_sequence[a_index], B_sequence[b_index]);
	ret = 1;
	
	for (int i = a_index + 1; i <= A_num; i++)
	{
		if (A_sequence[i] > max)
		{
			ret = std::max(ret, (1 + join_lis(i, b_index)));
		}
	}
	
	for (int i = b_index + 1; i <= B_num; i++)
	{
		if (B_sequence[i] > max)
		{
			ret = std::max(ret, (1 + join_lis(a_index, i)));
		}
	}
	return ret;
}

int main()
{
	freopen("sample.txt", "r", stdin);
	int test_case;

	scanf("%d", &test_case);

	for (int i = 0; i < test_case; i++)
	{
		memset(cache, -1, sizeof(cache));
	
		scanf("%d %d", &A_num, &B_num);
		for (int j = 1; j <= A_num; j++)
		{
			scanf("%lld", &A_sequence[j]);
		}
		for (int j = 1; j <= B_num; j++)
		{
			scanf("%lld", &B_sequence[j]);
		}
		A_sequence[0] = B_sequence[0] = MIN;

		printf("%d\n", join_lis(0, 0)-1);

	}
	return 0;
}
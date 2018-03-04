#include <cstdio>
#include <cstring>
#include <algorithm>

int sequence[100];
int quantization_value[100][101]; // 2번째 인자는 끝점. [) 형태의 배열
int cache[10][100];

const int INF = 1987654321;
int min;
int length, num_group;

int calculate_quantization_group(int start, int end)
{
	int& ret = quantization_value[start][end];
	
	if (ret != -1)
		return ret;

	int middle;
	int sum = 0;

	for (int i = start; i < end; i++)
	{
		sum += sequence[i];
	}
	middle = sum / (end - start);

	if (((double)sum / (end - start)) - middle >= 0.5)
		middle += 1;

	sum = 0;
	for (int i = start; i < end; i++)
	{
		sum += (sequence[i] - middle)*(sequence[i] - middle);
	}
	ret = sum;
	return ret;
}

int divide_group(int start, int end, int depth)// [ )
{
	int & partial_sum = cache[depth][start];

	if (partial_sum != -1)
		return partial_sum;

	if (start >= length)
		return 0;

	if (depth == (num_group - 1))
	{
		return partial_sum = calculate_quantization_group(start, end);
	}
	partial_sum = INF;
	for (int i = start+1 ; i <= end; i++)
	{
		int calc = calculate_quantization_group(start, i);
		partial_sum = std::min(divide_group(i, end, depth + 1) + calc, partial_sum);
	}

	return partial_sum;
}

int compare(const void * a, const void *b)
{
	return (*(int*)a - *(int*)b);
}

int main()
{
	int test_case;
	freopen("sample.txt", "r", stdin);

	scanf("%d", &test_case);

	for (int t = 0; t < test_case; t++)
	{
		memset(sequence, 0, sizeof(sequence));
		memset(quantization_value, -1, sizeof(quantization_value));
		memset(cache, -1, sizeof(cache));

		scanf("%d %d", &length, &num_group);
		for (int i = 0; i < length; i++)
		{
			scanf("%d", &sequence[i]);
		}
		qsort(sequence, length, sizeof(int), compare);
		
		printf("%d\n", divide_group(0, length, 0) );
	}
}
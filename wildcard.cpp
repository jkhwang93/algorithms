#include <iostream>
#include <cstring>

const int STR_LENGTH = 101;
const int FILE_MAX = 50;

char wildcard[STR_LENGTH];
char file[FILE_MAX][STR_LENGTH];
int index_of_matched_file[FILE_MAX];
int num_file;

bool is_matched(const char* based_str, const char* compared_str)
{
	bool ret = false;

	if (compared_str[0] == '\0' && (based_str[0] == '\0' || strcmp(based_str, "*") == 0))
		return true;
	else if (based_str[0] == '\0' || compared_str[0] == '\0')
		return false;

	if (based_str[0] == '?')
		ret = is_matched(&based_str[1], &compared_str[1]);
	else if (based_str[0] == '*')
		ret = (is_matched(&based_str[0], &compared_str[1]) || is_matched(&based_str[1], &compared_str[0]));
	else if (based_str[0] == compared_str[0])
		ret = is_matched(&based_str[1], &compared_str[1]);
	else
		ret = false;

	return ret;

}

int num_of_matched_file(int num_file)
{
	int match_count = 0;
	for(int i = 0 ; i < num_file ; i++)
	{
		if (is_matched(wildcard, file[i]))
		{
			index_of_matched_file[match_count++] = i;
		}
	}

	return match_count;
}

int main()
{
	int test_case;

	std::cin >> test_case;

	for (int t = 0; t < test_case; t++)
	{
		memset(wildcard, 0, sizeof(wildcard));
		memset(file, 0, sizeof(file));
		memset(index_of_matched_file, 0, sizeof(index_of_matched_file));

		std::cin >> wildcard;

		std::cin >> num_file;
		for (int i = 0; i < num_file; i++)
		{
			std::cin >> file[i];
		}

		qsort(file, num_file, sizeof(char) * STR_LENGTH, (int(*)(const void *, const void *))strcmp);
		
		int num = num_of_matched_file(num_file);

		for (int i = 0; i < num; i++)
		{
			std::cout << file[index_of_matched_file[i]] << std::endl;
		}	
	}

	return 0;
}
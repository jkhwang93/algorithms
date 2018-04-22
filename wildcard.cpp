#include <iostream>
#include <algorithm>

const int STR_LENGTH = 101;
const int FILE_MAX = 50;

char wildcard[STR_LENGTH];
char file[FILE_MAX][STR_LENGTH];
int index_of_matched_file[FILE_MAX];
int num_file;

int find_char(char check, const char * str, int* location_list)
{
	int location = 0;
	int num = 0;
	while (str[location] != '\0')
	{
		if (str[location] == check)
			location_list[num++] = location;
		location++;
	}

	return num;
}

bool is_matched(int file_index, const char* based_str, const char* compared_str)
{
	int index = 0;
	bool ret = false;

	while (based_str[index] != '\0' && compared_str[index] != '\0')
	{
		if (based_str[index] != '*')
		{
			if (based_str[index] == '?')
			{
				index++;
				continue;
			}

			if (based_str[index] != compared_str[index])
				break;
			else
				index++;
		}
		else
		{
			int compared_index = index;
			int char_location_list[STR_LENGTH] = { 0 };

			int num = find_char(based_str[index + 1], &compared_str[compared_index], char_location_list);
			for (int i = 0; i < num; i++)
			{

			}

			if (compared_index)
				ret = is_matched(file_index, &based_str[index + 1], &compared_str[compared_index]);
		}
	}

	return ret;
}

int num_of_matched_file(int num_file)
{
	int match_index = 0;
	while (match_index < num_file)
	{
		if (is_matched(match_index, wildcard, file[match_index]))
		{
			match_index++;
		}
	}

	return 0;
}

int main()
{
	int test_case;

	std::cin >> test_case;

	for (int t = 0; t < test_case; t++)
	{
		std::cin >> wildcard;

		std::cin >> num_file;
		for (int i = 0; i < num_file; i++)
		{
			std::cin >> file[i];
			std::cout << file[i] << std::endl;
		}
		/*
		std::sort(file[0], file[FILE_MAX]);

		for (int i = 0; i < num_file; i++)
		{
			std::cout << file[i] << std::endl;
		}
		*/
		int num = num_of_matched_file(num_file);

		for (int i = 0; i < num; i++)
		{
			std::cout << file[index_of_matched_file[i]] << std::endl;
		}
	
	}

	return 0;
}
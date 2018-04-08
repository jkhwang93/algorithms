#include <functional>
#include <iostream>
#include <queue>
#include <vector>

typedef struct party_set {
	char group;
	int value;
}party_set;

auto cmp = [](party_set s1, party_set s2) { return s1.value < s2.value; };
std::priority_queue<party_set, std::vector<party_set >, decltype(cmp)> party_q(cmp);

template<typename priority_queue> void evaluate(priority_queue& q, int flag) {
	while (!q.empty()) {		
		party_set s = q.top();
		q.pop();
		s.value = s.value - 1;
		if (s.value > 0)
			q.push(s);

		if (flag)
			std::cout << s.group << " ";
		else
			std::cout << s.group;
		
		flag = !flag;
	}
	std::cout << '\n';
}

int main()
{
	int T;
	std::cin >> T;

	for (int test = 1; test <= T; test++)
	{
		int total_senate = 0;
		int input;
		int num_party;
		
		std::cin >> num_party;
		for (int i = 0; i < num_party; i++)
		{
			std::cin >> input;
			party_set s;
			s.group = i+'A';
			s.value = input;

			total_senate += input;
			
			party_q.push(s);
		}
		std::cout << "Case #" << test << ": ";
		evaluate(party_q, total_senate%2);
	}
	return 0;
}
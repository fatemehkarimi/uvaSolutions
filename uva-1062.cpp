//uva 1062
//Containers

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void)
{
	string input;
	int tcounter = 0;
	while (1) {
		++tcounter;
		cin >> input;

		if (input == "end")
			break;

		vector <char> arr(26, '{');

		for (int i = 0; i < input.size(); ++i)
			for (int j = 0; j < 26; ++j)
				if (arr[j] >= input[i]){
					arr[j] = input[i];
					break;
				}


		int stackCount = 0;
		for (auto a : arr)
			if (a != '{')
				++stackCount;

		cout << "Case " << tcounter << ": " << stackCount << endl;

	}
	return 0;
}

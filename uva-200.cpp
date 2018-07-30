//uva 200
//Rare Order

#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(void)
{
	map <char, vector <char> > Graph;
	map <char, int> inEdge;
	vector <string> input;

	while (true) {
		string str;
		cin >> str;

		if (str == "#")
			break;

		input.push_back(str);
	}

	for (int i = 0; i < input.size() - 1; ++i)
		for (int j = 0; j < min(input[i].size(), input[i + 1].size());++j)
			if (input[i][j] != input[i + 1][j]){
				if (inEdge.find(input[i][j]) == inEdge.end())//not inserted to the map yet
					inEdge[input[i][j]] = 0;

				Graph[input[i][j]].push_back(input[i + 1][j]);
				++inEdge[input[i + 1][j]];

				break;
			}

	string result;
	while (true) {
		char origin = ' ';
		for (auto & a : inEdge)
			if (a.second == 0){
				a.second = -1;//indicates removed character
				origin = a.first;
				break;
			}

		if (origin == ' ')
			break;//all charecters has been used

		for (auto a : Graph[origin])
			--inEdge[a];

		result = result + origin;
	}

	cout << result << endl;

	return 0;
}

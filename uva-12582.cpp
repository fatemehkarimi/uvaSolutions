//uva 12582
//Wedding of Sultan

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <map>

using namespace std;

int main(void)
{
	int T = 0;
	cin >> T;

	for (int t = 1; t <= T; ++t){
		string input;
		cin >> input;

		stack <char> Stack;
		map <char, int> counts;

		for (int i = 0; i < input.size(); ++i)
			if (Stack.empty())
				Stack.push(input[i]);
			else if (Stack.top() != input[i]){
				++counts[Stack.top()];
				++counts[input[i]];
				Stack.push(input[i]);
			}
			else if (Stack.top() == input[i])
				Stack.pop();


		cout << "Case " << t << endl;
		for (auto a : counts)
			cout << a.first << " = " << a.second << endl;
	}

	return 0;
}

//uva 732
//Anagrams by Stack

#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

void anagram(string & input, string & target, string actions, string soFar, stack <char> Stack, int index, vector <string> & result);

int main(void)
{
	string input;
	while(cin >> input) {
		string target;
		cin >> target;

		vector <string> result;
		stack <char> Stack;

		anagram(input, target, "", "", Stack, 0, result);

		sort(result.begin(), result.end());

		cout << '[' << endl;
		for (auto a : result){
			cout << a[0];
			for (int i = 1; i < a.size(); ++i)
				cout << ' ' << a[i];

			cout << endl;
		}

		cout << ']' << endl;

	}

	return 0;
}

void anagram(string & input, string & target, string actions, string soFar, stack <char> Stack, int index, vector <string> & result)
{
	if (index == input.size()){
		while (!Stack.empty()){
			soFar = soFar + Stack.top();
			Stack.pop();
			actions = actions + 'o';
		}

		if (soFar == target)
			result.push_back(actions);

		return;
	}

	for (int i = 0; i < min(target.size(), soFar.size()); ++i)
		if (target[i] != soFar[i])
			return;


	Stack.push(input[index]);
	actions = actions + 'i';

	anagram(input, target, actions, soFar, Stack, index + 1, result);

	Stack.pop();

	while (!Stack.empty()){
		actions[actions.size() - 1] = 'o';

		soFar = soFar + Stack.top();
		Stack.pop();

		Stack.push(input[index]);
		actions = actions + 'i';

		anagram(input, target, actions, soFar, Stack, index + 1, result);

		Stack.pop();
	}

	return;
}

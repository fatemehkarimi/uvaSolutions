//uva 11988
//Broken Keyboard (a.k.a. Beiju Text)

#include <iostream>
#include <list>

using namespace std;

int main(void)
{
	string input;
	while (cin >> input) {
		bool mode = 0;//0 means end, 1 means home
		list <char> result;
		list <char> tmp;

		for (int i = 0; i < input.size(); ++i)
			if (input[i] == '['){
				if (mode)
					result.splice(result.begin(), tmp);
				else
					result.splice(result.end(), tmp);
				mode = 1;
			}
			else if (input[i] == ']'){
				if (mode)
					result.splice(result.begin(), tmp);
				else
					result.splice(result.end(), tmp);
				mode = 0;
			}
			else
				tmp.push_back(input[i]);

		if (mode)
			result.splice(result.begin(), tmp);
		else
			result.splice(result.end(), tmp);

		for (auto a : result)
			cout << a;

		cout << endl;
	}

	return 0;
}

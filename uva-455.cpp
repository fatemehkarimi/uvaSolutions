//uva 455
//Periodic Strings

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string substring(string input, int index);


int main(void)
{
	int t = 0;
	cin >> t;

	while (t--) {
		string input;
		cin >> input;

		string priod = substring(input, 0);

		for (int i = 1; i < input.size();) {
			int j = 0;
			int pre_i = i;

			while (i < input.size() && j < priod.size() && priod[j] == input[i++]){
				++j;
			}

			int start_index = i;
			for (int k = i; k > pre_i; --k)
				if (input[k] == priod[0]){
					start_index = k;
					break;
				}

			if (j != priod.size()){
				i = start_index;
				priod = substring(input, i - 1);
			}

		}

		cout << priod.size() << endl;

		if (t != 0)
			cout << endl;
	}

	return 0;
}


string substring(string input, int index)
{
	string result;
	for(int i = 0; i <= index; ++i)
		result = result + input[i];

	return result;
}

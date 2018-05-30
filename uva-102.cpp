//Ecological Bin Packing
//UVa 102

#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	while (true) {
		long long int arr[3][3] = {};
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
				if (cin >> arr[i][j]);
				else
					return 0;

		long long int answer = 0;
		string str;

		//case 1. BCG
		answer = arr[1][0] + arr[2][0] + arr[0][2] + arr[2][2] + arr[0][1] + arr[1][1];
		str = "BCG";

		//case 2. BGC
		long long int temp = 0;
		temp = arr[1][0] + arr[2][0] + arr[2][1] + arr[0][1] + arr[0][2] + arr[1][2];

		if (temp < answer) {
			answer = temp;
			str = "BGC";
		}

		//case 3. CBG
		temp = arr[1][2] + arr[2][2] + arr[2][0] + arr[0][0] + arr[0][1] + arr[1][1];

		if (temp < answer) {
			answer = temp;
			str = "CBG";
		}

		//case 4. CGB
		temp = arr[1][2] + arr[2][2] + arr[0][1] + arr[2][1] + arr[0][0] + arr[1][0];

		if (temp < answer) {
			answer = temp;
			str = "CGB";
		}

		//case 5. GBC
		temp = arr[1][1] + arr[2][1] + arr[0][0] + arr[2][0] + arr[0][2] + arr[1][2];

		if (temp < answer) {
			answer = temp;
			str = "GBC";
		}

		//case 6. GCB
		temp = arr[1][1] + arr[2][1] + arr[0][2] + arr[2][2] + arr[0][0] + arr[1][0];

		if (temp < answer) {
			answer = temp;
			str = "GCB";
		}

		cout << str << ' ' << answer << endl;
	}
}
//uva-100
//the 3n + 1 problem
//Solved

#include <iostream>

using namespace std;

int main(void)
{
	int i = 0, j = 0;
	while ((cin >> i) && (cin >> j)) {

		if (i == 0 | j == 0)
			break;

		int maxAnswer = 0;
		if (i <= j) {
			for (int k = i; k <= j; ++k) {
				int temp = 0;
				int x = k;

				while (x != 1) {
					if (x % 2 == 1)
						x = 3 * x + 1;
					else
						x /= 2;

					++temp;
				}

				if (maxAnswer < temp)
					maxAnswer = temp;
			}

		}
		else {
			for (int k = j; k <= i; ++k) {
				int temp = 0;
				int x = k;

				while (x != 1) {
					if (x % 2 == 1)
						x = 3 * x + 1;
					else
						x /= 2;

					++temp;
				}

				if (maxAnswer < temp)
					maxAnswer = temp;
			}
		}

		cout << i << ' ' << j << ' ' << ++maxAnswer << endl;
	}

	return 0;
}
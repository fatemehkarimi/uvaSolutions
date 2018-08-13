//uva 10920
//Spiral Tap

#include <iostream>

using namespace std;

int main(void)
{
	long long int n = 0, num;
	while (true) {
		cin >> n >> num;

		if (n == 0)
			break;

		long long int x = n / 2;
		long long int y = n / 2;

		long long int n_col = 1;
		long long int n_row = 1;

		bool direction = 1;//1 indicates up/down, 0 indicates left/right
		int value = -1;

		num -= 1;

		while (num > 0) {
			long long int amount = min(num, direction ? n_col : n_row);
			num -= amount;

			if (direction){//travel up/down
				x += (amount * value);
				++n_col;
			}
			else{
				y += (amount * value);
				++n_row;
				value *= -1;
			}

			direction = !direction;

		}

		cout << "Line = " << n - x << ", column = " <<  y + 1 << "." << endl;

	}

	return 0;
}

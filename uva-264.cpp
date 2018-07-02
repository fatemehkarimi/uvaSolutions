//uva 264
//Count on Cantor

#include <iostream>

using namespace std;

int main(void)
{
	int n = 0;
	while (cin >> n) {

		int nominator = 1;
		int denominator = 1;
		int counter = 1;

		if (n == 1) {
			cout << "TERM " << n << " IS " << nominator << '/' << denominator << endl;
			continue;
		}

		while (true) {
			if (nominator == 1) {
				++denominator;
				++counter;
				//going down
				while (counter < n && denominator > 1) {
					++nominator;
					--denominator;
					++counter;
				}
			}
			else if (denominator == 1) {
				++nominator;
				++counter;
				//going up
				while (counter < n && nominator > 1) {
					--nominator;
					++denominator;
					++counter;
				}
			}

			if (counter == n)
				break;
		}

		cout << "TERM " << n << " IS " << nominator << '/' << denominator << endl;
		
	}

	return 0;
}
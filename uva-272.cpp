//uva-272
//TEX Quotes

#include <iostream>

using namespace std;

int main(void)
{
	char a = ' ';
	long long int counter = 0;

	while ((a = getchar()) != EOF) {
		if (a == '"' && counter % 2 == 0) {
			cout << "``";
			++counter;
		}
		else if (a == '"' && counter % 2 == 1) {
			cout << "''";
			++counter;
		}
		else
			cout << a;
	}

	return 0;
}
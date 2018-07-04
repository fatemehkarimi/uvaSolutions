//uva 294
//Divisors

#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
	int n = 0;
	cin >> n;
	while (n--) {
		long long int l = 0, u = 0;
		cin >> l >> u;

		int maxdivisor = 0;
		long long int num = 0;

		for (long long int i = l; i <= u; ++i) {
			long long int limit = (long long int)sqrt(i);

			int divisortmp = 2;

			for (long long int tmp = 2; tmp <= limit; ++tmp)
				if (i % tmp == 0)
					divisortmp += 2;

			if (limit * limit == i)
				--divisortmp;

			if (divisortmp > maxdivisor) {
				maxdivisor = divisortmp;
				num = i;
			}
		}


		cout << "Between " << l << " and " << u << ", " << num << " has a maximum of " << maxdivisor << " divisors." << endl;
	}

	return 0;
}
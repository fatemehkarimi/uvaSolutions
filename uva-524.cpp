//uva 524
//Prime Ring Problem

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

bool isPrime(int a);
void possibleStates(int n, int index, vector <vector <int> > & result, vector <int> order, vector <bool> used);

int main(void)
{
	int n = 0;
	int tcounter = 0;

	while (cin >> n) {

		if (tcounter != 0)
			cout << endl;
		
		++tcounter;

		vector <bool> used(n);
		vector <int> order(n);
		vector <vector <int> > result;

		order[0] = 1;
		used[0] = 1;

		cout << "Case " << tcounter << ":" << endl;

		possibleStates(n, 1, result, order, used);

		for (auto a : result){
			cout << a[0];
			for (int i = 1; i < a.size(); ++i)
				cout << " " << a[i];
			cout << endl;
		}
	}

	return 0;
}

void possibleStates(int n, int index, vector <vector <int> > & result, vector <int> order, vector <bool> used)
{
	if (index == n) {
		if (isPrime(order[n - 1] + order[0]))
			result.push_back(order);
		return;
	}

	for (int i = 2; i <= n; ++i)
		if (!used[i - 1] && isPrime(i + order[index - 1])){
			used[i - 1] = 1;
			order[index] = i;
			possibleStates(n, index + 1, result, order, used);
			used[i - 1] = 0;
		}

	return;
}

bool isPrime(int a)
{
	bool prime[] = {0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0
				, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0};
	return prime[a];
}

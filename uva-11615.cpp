//uva 11615
//Family Tree

#include <iostream>
#include <cmath>

using namespace std;

int find_level(int n);

int main(void)
{
	int T;
	cin >> T;
	while(T--){
		int n, a, b;
		cin >> n >> a >> b;

		int level_a = find_level(a);
		int level_b = find_level(b);

		long long int total_pop = pow(2, n) - 1;
		long long int redun_pop_a = pow(2, n - level_a) - 1 - 1;
		long long int redun_pop_b = pow(2, n - level_b) - 1 - 1;

		cout << total_pop - min(redun_pop_a, redun_pop_b) << endl;
	}
	return 0;
}

int find_level(int n)
{
	int level = 0;
	while(n != 1){
		if(n % 2)
			--n;
		n /= 2;
		++level;
	}
	return level;
}

//uva 11991
//Easy Problem from Rujia Liu?

#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(void)
{
	int n, m;

	while (cin >> n >> m){
		map <int, vector <int> > num;
		for (int i = 0; i < n; ++i) {
			int t;
			cin >> t;

			num[t].push_back(i);
		}

		for (int i = 0; i < m; ++i){
			int k, v;
			cin >> k >> v;

			if (num[v].size() >= k)
				cout << num[v][k - 1] + 1 << endl;
			else
				cout << "0" << endl;
		}
	}
	return 0;
}

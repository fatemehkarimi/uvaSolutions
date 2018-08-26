//uva 990
//Diving for gold

#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int t = 0, w = 0;
	bool newLine = 0;
	while (cin >> t >> w) {
		int n = 0;
		cin >> n;

		if (newLine)
			cout << endl;
		else
			newLine = 1;

		vector < pair <int, int> > treasure;
		for (int i = 0; i < n; ++i){
			int d, v;
			cin >> d >> v;

			treasure.push_back(make_pair(d, v));
		}

		vector < vector <int> > arr(n + 1, vector <int> (t + 1, 0));

		for (int i = 1; i <= n; ++i){
			int requiredTime = 3 * w * treasure[i - 1].first;
			int value = treasure[i - 1].second;

			for (int j = 1; j <= t; ++j)
				if (j - requiredTime >= 0)
					arr[i][j] = max(arr[i - 1][j], arr[i - 1][j - requiredTime] + value);
				else
					arr[i][j] = arr[i - 1][j];
		}

		cout << arr[n][t] << endl;

		vector <int> result;
		int x = n, y = t;
		while (x > 0 && y > 0){
			if (arr[x][y] != arr[x - 1][y]) {
				int usedTime = 3 * w * treasure[x - 1].first;
				y -= usedTime;
				result.push_back(x - 1);
			}
			--x;
		}

		cout << result.size() << endl;

		for (auto a = result.rbegin(); a != result.rend(); ++a)
			cout << treasure[*a].first << ' ' << treasure[*a].second << endl;
	}

	return 0;
}

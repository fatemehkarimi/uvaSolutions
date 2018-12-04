//uva 10803
//Thunder Mountain

#include <iostream>
#include <iomanip>
#include <climits>
#include <vector>
#include <cmath>

using namespace std;

double distance(pair <int, int> x, pair <int, int> y);

int main(void)
{
	int T = 0;
	int tcounter = 0;
	cin >> T;
	while(T--){
		++tcounter;

		int n = 0;
		cin >> n;

		vector < pair <int, int> > coordiante(n);
		for(int i = 0; i < n; ++i){
			int x, y;
			cin >> x >> y;

			coordiante[i] = make_pair(x, y);
		}

		vector < vector <double> > Graph(n, vector <double> (n, INT_MAX));

		for(int i = 0; i < n; ++i)
			for(int j = i + 1; j < n; ++j){
				double d = distance(coordiante[i], coordiante[j]);

				if(d > 10)
					continue;

				Graph[i][j] = d;
				Graph[j][i] = d;
			}

		for(int i = 0; i < n; ++i)
			Graph[i][i] = 0;


		for(int k = 0; k < n; ++k)
			for(int i = 0; i < n; ++i)
				for(int j = 0; j < n; ++j)
					if(Graph[i][k] != INT_MAX && Graph[k][j] != INT_MAX)
						Graph[i][j] = min(Graph[i][j], Graph[i][k] + Graph[k][j]);
					

		double result = INT_MIN;
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j)
				result = max(result, Graph[i][j]);


		cout << "Case #" << tcounter << ":" << endl;
		if(result == INT_MAX)
			cout << "Send Kurdy" << endl;
		else
			cout << fixed << left << setprecision(4) << result << endl;

		cout << endl;
	}

	return 0;
}

double distance(pair <int, int> x, pair <int, int> y)
{
	return sqrt((x.first - y.first) * (x.first - y.first)
		+ (x.second - y.second) * (x.second - y.second));
}

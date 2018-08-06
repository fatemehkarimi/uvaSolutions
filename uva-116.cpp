//uva 116
//Unidirectional TSP

#include <iostream>
#include <climits>
#include <vector>
#include <iomanip>

using namespace std;

bool comparePath(vector <int> & path1, vector <int> & path2);

int main(void)
{
	int m, n;
	while (cin >> m >> n) {
		vector <vector <int> > arr(m, vector <int> (n));

		for (int i = 0; i < m; ++i)
			for (int j = 0; j < n; ++j)
				cin >> arr[i][j];


		vector < vector <int> > value(m, vector <int> (n, INT_MAX));
		vector < vector < vector <int> > > path(m, vector < vector <int> > (n));

		for (int i = 0; i < m; ++i){
			value[i][0] = arr[i][0];
			path[i][0].push_back(i);
		}


		for (int j = 1; j < n; ++j)
			for (int i = 0; i < m; ++i){
				int up = (i - 1 + m) % m;
				int down = (i + 1) % m;

				if (value[up][j - 1] + arr[i][j] < value[i][j]){
					value[i][j] = value[up][j - 1] + arr[i][j];

					path[i][j] = path[up][j - 1];
				}
				else if (value[up][j - 1] + arr[i][j] == value[i][j] && comparePath(path[up][j - 1], path[i][j]))
					path[i][j] = path[up][j - 1];

				if (value[i][j - 1] + arr[i][j] < value[i][j]){
					value[i][j] = value[i][j - 1] + arr[i][j];

					path[i][j] = path[i][j - 1];
				}
				else if (value[i][j - 1] + arr[i][j] == value[i][j] && comparePath(path[i][j - 1], path[i][j]))
					path[i][j] = path[i][j - 1];

				if (value[down][j - 1] + arr[i][j] < value[i][j]){
					value[i][j] = value[down][j - 1] + arr[i][j];

					path[i][j] = path[down][j - 1];
				}
				else if (value[down][j - 1] + arr[i][j] == value[i][j] && comparePath(path[down][j - 1], path[i][j]))
					path[i][j] = path[down][j - 1];

				path[i][j].push_back(i);
			}

		int minimumValue = value[0][n - 1];
		vector <int> result;

		for (int i = 0; i < m; ++i)
			if (minimumValue > value[i][n - 1])
				minimumValue = value[i][n - 1];

		for (int i = 0; i < m; ++i)
			if (value[i][n - 1] == minimumValue){

				if (result.empty())
					result = path[i][n - 1];
				else if (comparePath(path[i][n - 1], result))
					result = path[i][n - 1];
			}

		cout << result[0] + 1;
		for (int i = 1; i < result.size(); ++i)
			cout << ' ' << result[i] + 1;
		cout << endl << minimumValue << endl;

	}
	return 0;
}

bool comparePath(vector <int> & path1, vector <int> & path2)
{
	int index = 0;

	while (path1[index] == path2[index] && index < min(path1.size(), path2.size()))
		++index;

	return path1[index] < path2[index] ? 1 : 0;
}

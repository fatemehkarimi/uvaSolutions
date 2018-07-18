//uva 10003
//Cutting Sticks

#include <iostream>
#include <climits>
#include <vector>

using namespace std;

int min(int a, int b);

int main(void)
{
	int l = 0;
	while (1) {
		cin >> l;
		if (l == 0)
			break;

		int n = 0;
		cin >> n;
		vector <int> cuts(n + 2);

		for (int i = 1; i < n + 1; ++i)
			cin >> cuts[i];

		cuts[n + 1] = l;

		vector < vector <int> > arr(cuts.size(), vector <int> (cuts.size(), INT_MAX));

		for (int z = 1; z <= cuts.size(); ++z)
			for (int x = 0; x < cuts.size() - z + 1; ++x){
				int y = x + z - 1;

				for (int k = x + 1; k < y; ++k)
					arr[x][y] = min(arr[x][y], arr[x][k] + arr[k][y] + cuts[y] - cuts[x]);

				if (arr[x][y] == INT_MAX)
					arr[x][y] = 0;

			}

		cout << "The minimum cutting is " << arr[0][cuts.size() - 1] << '.' << endl;

	}

	return 0;
}

int min(int a, int b)
{
	return a > b ? b : a;
}

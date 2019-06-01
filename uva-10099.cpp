//uva 10099
//The Tourist Guide

#include <iostream>
#include <climits>
#include <vector>

using namespace std;

int main(void)
{
	int n, m, tcounter = 0;
	while(true){
		cin >> n >> m;
		if(n == 0 && m == 0)
			break;

		++tcounter;

		vector <vector <int> > Graph(n, vector <int>(n, INT_MIN));
		
		for(int i = 0; i < m; ++i){
			int c1, c2, p;
			cin >> c1 >> c2 >> p;
			--c1, --c2;

			Graph[c1][c2] = p;
			Graph[c2][c1] = p;
		}

		int source, dest, n_pass;
		cin >> source >> dest >> n_pass;
		--source, -- dest;

		for(int k = 0; k < n; ++k)
			for(int i = 0; i < n; ++i)
				for(int j = 0; j < n; ++j)
					Graph[i][j] = max(Graph[i][j], min(Graph[i][k], Graph[k][j]));

		int n_trip = n_pass / (Graph[source][dest] - 1);
		if(n_pass % Graph[source][dest])
			++n_trip;

		cout << "Scenario #" << tcounter << endl;
		cout << "Minimum Number of Trips = " << n_trip << endl;
		cout << endl;
	}
	return 0;
}

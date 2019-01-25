//uva 11015
//05-2 Rendezvous

#include <iostream>
#include <vector>
#include <string>
#include <climits>

using namespace std;

int main(void)
{
	int n, m;
	int tcounter = 0;
	while(true){
		cin >> n >> m;

		if(n == 0 && m == 0) break;
		++tcounter;

		vector <string> people(n);
		for(int i = 0; i < n; ++i)
			cin >> people[i];

		vector <vector <int> > Graph(n, vector <int> (n, INT_MAX));
		for(int i = 0; i < n; ++i)
			Graph[i][i] = 0;

		for(int i = 0; i < m; ++i){
			int u, v, value;
			cin >> u >> v >> value;

			--u, --v;
			Graph[u][v] = value;
			Graph[v][u] = value;
		}

		for(int k = 0; k < n; ++k)
			for(int i = 0; i < n; ++i)
				for(int j = 0; j < n; ++j)
					if(Graph[i][k] != INT_MAX && Graph[k][j] != INT_MAX)
						Graph[i][j] = min(Graph[i][k] + Graph[k][j], Graph[i][j]);

		int minDist = INT_MAX;
		string person;
		for(int i = 0; i < n; ++i){
			int cost = 0;
			for(int j = 0; j < n; ++j)
				cost += Graph[i][j];

			if(minDist > cost){
				minDist = cost;
				person =  people[i];
			}
		}

		cout << "Case #" << tcounter << " : " << person << endl;
	}
	return 0;
}

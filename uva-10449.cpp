//uva 10449
//Traffic

#include <iostream>
#include <climits>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

int main(void)
{
	int n, m;
	int tcounter = 0;
	while(cin >> n){
		++tcounter;

		vector <int> bussiness(n + 1);
		for(int i = 0; i < n; ++i)
			cin >> bussiness[i];

		vector < map <int, int> > Graph(n + 1);
		cin >> m;
		for(int i = 0; i < m; ++i){
			int a, b;
			cin >> a >> b;
			--a, --b;
			Graph[a][b] = pow(bussiness[b] - bussiness[a], 3);
		}

		vector <int> distance(n + 1, INT_MAX);
		distance[0] = 0;

		for(int i = 0; i < n - 1; ++i)
			for(int u = 0; u < n; ++u)
				for(auto v : Graph[u])
					if(distance[u] != INT_MAX)
						distance[v.first] = min(distance[v.first], distance[u] + v.second);

		for(int i = 0; i < n - 1; ++i)
			for(int u = 0; u < n; ++u)
				for(auto v : Graph[u])
					if(distance[u] == INT_MIN || (distance[u] != INT_MAX && distance[u] + v.second < distance[v.first]))
						distance[v.first] = INT_MIN;

		int query;
		cin >> query;
		cout << "Set #" << tcounter << endl;
		for(int q = 0; q < query; ++q){
			int vertex;
			cin >> vertex;

			--vertex;
			if(distance[vertex] < 3 || distance[vertex] == INT_MAX)
				cout << "?" << endl;
			else
				cout << distance[vertex] << endl;
		}

	}
	return 0;
}

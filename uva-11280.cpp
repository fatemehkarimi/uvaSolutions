//uva 11280
//Flying to Fredericton

#include <iostream>
#include <climits>
#include <vector>
#include <string>
#include <map>

using namespace std;

void bellMan_Ford(map <pair <int, int>, int> & edges, vector <int> & tolerance);

int main(void)
{
	int T = 0;
	cin >> T;
	int tcounter = 0;

	while(T--){
		++tcounter;

		int n = 0;
		cin >> n;

		map <string, int> cities;
		
		for(int i = 0; i < n; ++i){
			string city;
			cin >> city;
			cities[city] = i;
		}

		map < pair <int, int>, int> edges;

		int m = 0;
		cin >> m;

		for(int i = 0; i < m; ++i){
			string city1, city2;
			int cost;

			cin >> city1 >> city2 >> cost;

			int code1 = cities[city1];
			int code2 = cities[city2];

			if(edges.find(make_pair(code1, code2)) != edges.end())
				edges[make_pair(code1, code2)] = min(edges[make_pair(code1, code2)], cost);
			else
				edges[make_pair(code1, code2)] = cost;
		}

		vector <int> tolerance(n, INT_MAX);
		bellMan_Ford(edges, tolerance);

		cout << "Scenario #" << tcounter << endl;

		int query = 0;
		cin >> query;

		for(int i = 0; i < query; ++i){
			int max_tolerance;
			cin >> max_tolerance;

			max_tolerance = min(max_tolerance, n - 2);

			if(tolerance[max_tolerance] != INT_MAX)
				cout << "Total cost of flight(s) is $" << tolerance[max_tolerance] << endl;
			else
				cout << "No satisfactory flights" << endl;
		}

		if(T)
			cout << endl;
	}
	return 0;
}


void bellMan_Ford(map <pair <int, int>, int> & edges, vector <int> & tolerance)
{
	int n = tolerance.size();//number of nodes in the Graph
	vector <int> cost(n, INT_MAX);
	cost[0] = 0;

	for(int i = 0; i < n - 1; ++i){
		for(auto edge = edges.rbegin(); edge != edges.rend(); ++edge){
			int u = edge->first.first;
			int v = edge->first.second;
			int value = edge->second;

			if(cost[u] != INT_MAX)
				cost[v] = min(cost[u] + value, cost[v]);
		}

		tolerance[i] = min(i > 0 ? tolerance[i - 1] : INT_MAX, cost[n - 1]);
	}

	return;
}


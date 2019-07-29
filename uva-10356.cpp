//uva 10356
//Rough Roads

#include <iostream>
#include <climits>
#include <vector>
#include <map>
#include <set>

using namespace std;

int Dijkstra(vector < vector <pair <int, int> > > & Graph);

int main(void)
{
	int n, r, T = 0;
	while(cin >> n >> r){
		vector < vector <pair <int, int> > > Graph(n);
		for(int i = 0; i < r; ++i){
			int u, v, cost;
			cin >> u >> v >> cost;
			Graph[u].push_back(make_pair(v, cost));
			Graph[v].push_back(make_pair(u, cost));
		}
		++T;
		cout << "Set #" << T << endl;
		int result = Dijkstra(Graph);
		if(result == INT_MAX)
			cout << "?" << endl;
		else
			cout << result << endl;
	}
	return 0;
}

int Dijkstra(vector < vector <pair <int, int> > > & Graph)
{
	int n = Graph.size();
	set < pair <pair <int, int>, int> > Heap;
	map < int, map <int, int> > min_distance;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j <= 1; ++j)
			min_distance[i][j] = INT_MAX;

	for(auto a : Graph[0]){
		min_distance[a.first][0] = a.second;
		Heap.insert(make_pair(make_pair(a.second, 0), a.first));
	}

	while(!Heap.empty()){
		int cost = Heap.begin()->first.first;
		int status = Heap.begin()->first.second;
		int node = Heap.begin()->second;
		Heap.erase(Heap.begin());

		for(auto a : Graph[node])
			if(cost + a.second < min_distance[a.first][!status]){
				Heap.erase(make_pair(make_pair(min_distance[a.first][!status], !status), a.first));
				min_distance[a.first][!status] = cost + a.second; 
				Heap.insert(make_pair(make_pair(min_distance[a.first][!status], !status), a.first));
			}
	}
	return min_distance[n - 1][1];
}

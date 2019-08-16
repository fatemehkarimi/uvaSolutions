//uva 12144
//Almost Shortest Path

#include <iostream>
#include <climits>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;

int Dijkstra(vector < map <int, int> > & graph, int s, int d);

int main(void)
{
	int n, m;
	while(cin >> n >> m, n){
		int s, d;
		vector < map <int, int> > Graph(n);

		cin >> s >> d;
		for(int i = 0; i < m; ++i){
			int u, v, p;
			cin >> u >> v >> p;
			Graph[u].insert(make_pair(v, p));
		}
		Dijkstra(Graph, s, d);
		int result = Dijkstra(Graph, s, d);
		if(result == INT_MAX)
			cout << -1 << endl;
		else
			cout << result << endl;
	}
	return 0;
}

int Dijkstra(vector < map <int, int> > & graph, int s, int d)
{
	vector <int> min_cost(graph.size(), INT_MAX);
	vector <set <int> > parent(graph.size());
	set <pair <int, int> > Heap;
	min_cost[s] = 0;
	Heap.insert(make_pair(0, s));

	while(!Heap.empty()){
		int front = Heap.begin()->second;
		Heap.erase(Heap.begin());

		for(auto a : graph[front])
			if(min_cost[front] + a.second < min_cost[a.first]){
				Heap.erase(make_pair(min_cost[a.first], a.first));
				min_cost[a.first] = min_cost[front] + a.second;
				Heap.insert(make_pair(min_cost[a.first], a.first));
				parent[a.first].clear();
				parent[a.first].insert(front);
			}
			else if(min_cost[front] + a.second == min_cost[a.first])
				parent[a.first].insert(front);
	}

	queue <int> Queue;
	Queue.push(d);
	while(!Queue.empty()){
		int front = Queue.front();
		Queue.pop();

		for(auto a : parent[front]){
			graph[a].erase(front);
			Queue.push(a);
		}
	}

	return min_cost[d];
}

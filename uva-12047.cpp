//uva 12047
//Highest Paid Toll

#include <iostream>
#include <climits>
#include <vector>
#include <set>

using namespace std;

void Dijkstra(vector <vector <pair <int, int> > > & Graph, vector <int> & min_path, int s);

int main(void)
{
	int T = 0;
	cin >> T;
	while(T--){
		int n, m, s, t, p;
		cin >> n >> m >> s >> t >> p;
		--s, --t;

		vector <vector <pair <int, int> > > Graph(n);
		vector <vector <pair <int, int> > > TGraph(n);

		for(int i = 0; i < m; ++i){
			int u, v, c;
			cin >> u >> v >> c;
			--u, --v;
			Graph[u].push_back(make_pair(v, c));
			TGraph[v].push_back(make_pair(u, c));
		}

		vector <int> min_path_graph(n, INT_MAX);
		vector <int> min_path_tgraph(n, INT_MAX);
		Dijkstra(Graph, min_path_graph, s);
		Dijkstra(TGraph,min_path_tgraph, t);

		int max_edge = -1;
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < Graph[i].size(); ++j){
				int u = i;
				int v = Graph[i][j].first;
				int edge_cost = Graph[i][j].second;

				if(min_path_graph[u] != INT_MAX && min_path_tgraph[v] != INT_MAX && min_path_graph[u] + edge_cost + min_path_tgraph[v] <= p)
					max_edge = max(max_edge, edge_cost);
			}
		cout << max_edge << endl;
	}
	return 0;
}


void Dijkstra(vector <vector <pair <int, int> > > & Graph, vector <int> & min_path, int s)
{
	min_path[s] = 0;
	set <pair <int, int> > Heap;
	Heap.insert(make_pair(0, s));

	while(!Heap.empty()){
		int front = Heap.begin()->second;
		Heap.erase(Heap.begin());

		for(auto a : Graph[front])
			if(min_path[front] + a.second < min_path[a.first]){
				Heap.erase(make_pair(min_path[a.first], a.first));
				min_path[a.first] = min_path[front] + a.second;
				Heap.insert(make_pair(min_path[a.first], a.first));
			}
	}
	return;
}


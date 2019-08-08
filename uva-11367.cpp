//uva 11367
//Full Tank?

#include <iostream>
#include <climits>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int Dijkstra(vector <vector <pair <int, int> > > & Graph, vector <int> & price, int source, int destin, int capacity);

typedef struct state{
	int node;
	int extra;
	int cost;

	state(int n, int e, int c)
	:node(n), extra(e), cost(c)
	{}

	bool operator<(const state & a)const{
		return cost > a.cost;
	}
}state;

int main(void)
{
	int n, m;
	cin >> n >> m;
	vector <int> price(n);
	for(int i = 0; i < n; ++i)
		cin >> price[i];

	vector <vector <pair <int, int> > > Graph(n);
	for(int i = 0; i < m; ++i){
		int u, v, d;
		cin >> u >> v >> d;
		Graph[u].push_back(make_pair(v, d));
		Graph[v].push_back(make_pair(u, d));
	}

	int q;
	cin >> q;
	while(q--){
		int capacity, source, destination;
		cin >> capacity >> source >> destination;
		
		int result = Dijkstra(Graph, price, source, destination, capacity);
		if(result == INT_MAX)
			cout << "impossible" << endl;
		else
			cout << result << endl;
	}
	return 0;
}


int Dijkstra(vector <vector <pair <int, int> > > & Graph, vector <int> & price, int source, int destin, int capacity)
{
	vector < vector <int> > min_cost(Graph.size(), vector <int> (capacity + 1, INT_MAX));
	priority_queue <state> Heap;
	Heap.push(state(source, 0, 0));
	min_cost[source][0] = 0;

	while(!Heap.empty()){
		state front = Heap.top();
		Heap.pop();

		if(front.node == destin)
			return front.cost;

		if(front.extra < capacity && front.cost + price[front.node] < min_cost[front.node][front.extra + 1]){
			min_cost[front.node][front.extra + 1] = front.cost + price[front.node];
			Heap.push(state(front.node, front.extra + 1, min_cost[front.node][front.extra + 1]));
		}

		for(auto d : Graph[front.node])
			if(front.extra >= d.second && front.cost < min_cost[d.first][front.extra - d.second]){
				min_cost[d.first][front.extra - d.second] = front.cost;
				Heap.push(state(d.first, front.extra - d.second, min_cost[d.first][front.extra - d.second]));
			}
	}
	return INT_MAX;
}

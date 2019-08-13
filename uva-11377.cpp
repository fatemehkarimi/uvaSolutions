//uva 11377
//Airport Setup
#include <iostream>
#include <climits>
#include <vector>
#include <set>
#include <map>

using namespace std;

int Dijkstra(vector <vector <int> > & Graph, vector <bool> & has_airport, int source, int destin);

int main(void)
{
	int T = 0;
	cin >> T;
	for(int tcounter = 1; tcounter <= T; ++tcounter){
		int n, m, k;
		cin >> n >> m >> k;

		vector <bool> has_airport(n, false);
		for(int i = 0; i < k; ++i){
			int tmp;
			cin >> tmp;
			--tmp;
			has_airport[tmp] = true;
		}

		vector <vector <int> > Graph(n);
		for(int i = 0; i < m; ++i){
			int u, v;
			cin >> u >> v;
			--u, --v;
			Graph[u].push_back(v);
			Graph[v].push_back(u);
		}
		cout << "Case " << tcounter << ":" << endl;
		int Query = 0;
		cin >> Query;
		while(Query--){
			int source, destin;
			cin >> source >> destin;
			--source, --destin;
			int result = Dijkstra(Graph, has_airport, source, destin);
			cout << result << endl;
		}
		cout << endl;
	}
	return 0;
}


int Dijkstra(vector <vector <int> > & Graph, vector <bool> & has_airport, int source, int destin)
{
	if(source == destin)
		return 0;

	int n = Graph.size();
	vector <int> min_airport(n, INT_MAX);
	set <pair <int, int> > Heap;

	min_airport[source] = !has_airport[source];
	Heap.insert(make_pair(min_airport[source], source));

	while(!Heap.empty()){
		int front = Heap.begin()->second;
		Heap.erase(Heap.begin());

		for(auto a : Graph[front]){
			int count_airport = min_airport[front];
			if(!has_airport[a])
				++count_airport;

			if(count_airport < min_airport[a]){
				Heap.erase(make_pair(min_airport[a], a));
				min_airport[a] = count_airport;
				Heap.insert(make_pair(min_airport[a], a));
			}
		}
	}
	return min_airport[destin] == INT_MAX ? -1 : min_airport[destin];
}

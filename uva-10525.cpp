//uva 10525
//New to Bangladesh?

#include <iostream>
#include <climits>
#include <vector>
#include <set>
#include <map>

using namespace std;

pair <int, int> Dijkstra(vector < multimap <int, pair <int, int> > > & Graph, int source, int destination);

int main(void)
{
	int T = 0;
	cin >> T;
	while(T--){
		int n, e;
		cin >> n >> e;

		vector < multimap <int, pair <int, int> > > Graph(n);

		for(int i = 0; i < e; ++i){
			int u, v, t, d;
			cin >> u >> v >> t >> d;

			--u, --v;

			Graph[u].insert(make_pair(v, make_pair(t, d)));
			Graph[v].insert(make_pair(u, make_pair(t, d)));
		}

		int query;
		cin >> query;
		int source, destination;

		while(query--){
			cin >> source >> destination;
			--source, --destination;

			pair <int, int > result = Dijkstra(Graph, source, destination);

			if(result.first == INT_MAX)
				cout << "No Path." << endl;
			else
				cout << "Distance and time to reach destination is " << result.first << " & " << result.second << "." << endl;
		}

		if(T) cout << endl;
	}
	return 0;
}


pair <int, int> Dijkstra(vector < multimap <int, pair <int, int> > > & Graph, int source, int destination)
{
	int n = Graph.size();
	vector <int> minDis(n, INT_MAX);
	vector <int> minTime(n, INT_MAX);

	set <pair <int, int> > currTime;

	minTime[source] = 0;
	minDis[source] = 0;
	currTime.insert(make_pair(0, source));

	while(!currTime.empty()){
		int nodeTime = currTime.begin()->first;
		int node = currTime.begin()->second;

		currTime.erase(currTime.begin());

		for(auto a : Graph[node])
			if(a.second.first + nodeTime < minTime[a.first]){
				currTime.erase(make_pair(minTime[a.first], a.first));
				minTime[a.first] = a.second.first + nodeTime;
				minDis[a.first] = minDis[node] + a.second.second;
				currTime.insert(make_pair(minTime[a.first], a.first));
			}
			else if(a.second.first + nodeTime == minTime[a.first])
				minDis[a.first] = min(minDis[a.first], minDis[node] + a.second.second);
	}

	return make_pair(minDis[destination], minTime[destination]);
}


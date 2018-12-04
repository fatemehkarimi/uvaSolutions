//uva 11463
//Commandos

#include <iostream>
#include <climits>
#include <vector>
#include <queue>
#include <set>

using namespace std;

vector <int> BFS(vector < set <int> > & Graph, int start);

int main(void)
{
	int T = 0;
	int tcounter = 0;
	cin >> T;
	while(T--) {
		++tcounter;

		int n, e;
		cin >> n >> e;

		vector < set <int> > Graph(n);

		for(int i = 0; i < e; ++i){
			int u, v;
			cin >> u >> v;

			Graph[u].insert(v);
			Graph[v].insert(u);
		}

		int s, d;
		cin >> s >> d;

		vector <int> bfsStart = BFS(Graph, s);
		vector <int> bfsDis = BFS(Graph, d);

		int result = INT_MIN;

		for(int i = 0; i < n; ++i)
			result = max(result, bfsStart[i] + bfsDis[i]);


		cout << "Case " << tcounter << ": " << result << endl;

	}

	return 0;
}

vector <int> BFS(vector < set <int> > & Graph, int start)
{
	int n = Graph.size();
	vector <int> levels(n, INT_MAX);
	vector <bool> visited(n, false);

	levels[start] = 0;
	visited[start] = 1;

	queue <int> Queue;
	Queue.push(start);

	while(!Queue.empty()){
		int front = Queue.front();
		Queue.pop();

		for(auto a : Graph[front])
			if(!visited[a]){
				visited[a] = true;
				levels[a] = levels[front] + 1;
				Queue.push(a);
			}
	}

	return levels;
}

//uva 11080
//Place the Guards

#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int bipartite(vector < set <int> > & Graph, vector <bool> & visited, int start);

int main(void)
{
	int T = 0;
	cin >> T;
	while(T--){
		int v, e;
		cin >> v >> e;

		vector < set <int> > Graph(v);

		for(int i = 0; i < e; ++i){
			int x, y;
			cin >> x >> y;

			Graph[x].insert(y);
			Graph[y].insert(x);
		}

		int minGuards = 0;
		bool minGuardPossible = 1;
		vector <bool> visited(v, false);
		for(int i = 0; i < v; ++i)
			if(!visited[i]){
				int tmp = bipartite(Graph, visited, i);
				if(tmp == -1){
					minGuardPossible = 0;
					break;
				}
				minGuards += tmp;
			}

		if(!minGuardPossible)
			cout << "-1" << endl;
		else
			cout << minGuards << endl;
	}
	return 0;
}

int bipartite(vector < set <int> > & Graph, vector <bool> & visited, int start)
{
	int n = Graph.size();
	bool is_bipartite = 1;

	int count0 = 1, count1 = 0;//start node is colored black

	vector <bool> color(n, false);
	queue <int> Queue;

	visited[start] = 1;
	Queue.push(start);

	while(!Queue.empty()){
		int front = Queue.front();
		Queue.pop();

		for(auto a : Graph[front])
			if(visited[a] && color[a] == color[front])
				is_bipartite = 0;
			else if(!visited[a]){
				color[a] = !color[front];

				if(color[a]) ++count1;
				else ++count0;

				visited[a] = true;
				Queue.push(a);
			}
	}

	if(is_bipartite){
		int result = min(count0, count1);
		if(result)
			return result;
		else //case only one group exist
			return max(count0, count1);
	}
	return -1;
}

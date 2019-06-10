//uva 10842
//Traffic Flow

#include <iostream>
#include <climits>
#include <vector>
#include <set>

using namespace std;

int kruskal(int n, set < pair <int, pair <int, int> >, greater <pair <int, pair <int, int> > > > & Edges);
void _union(vector <int> & ufds, int x, int y);
int findParent(vector <int> & ufds, int x);

int main(void)
{
	int T, tcounter = 0;
	cin >> T;
	while(T--){
		++tcounter;

		int n, m;
		cin >> n >> m;

		set < pair <int, pair <int, int> >, greater <pair <int, pair <int, int> > > > Edges;

		for(int i = 0; i < m; ++i){
			int u, v, cost;
			cin >> u >> v >> cost;
			Edges.insert(make_pair(cost, make_pair(u, v)));
		}

		int result = kruskal(n, Edges);
		cout << "Case #" << tcounter << ": ";
		cout << result << endl;
	}
	return 0;
}

int kruskal(int n, set < pair <int, pair <int, int> >, greater <pair <int, pair <int, int> > > > & Edges)
{
	vector <int> ufds(n, -1);
	int maxEdgeInTree = INT_MAX;

	while(!Edges.empty()){
		int cost = Edges.begin()->first;
		int u = Edges.begin()->second.first;
		int v = Edges.begin()->second.second;
		Edges.erase(Edges.begin());

		if(findParent(ufds, u) != findParent(ufds, v)){
			_union(ufds, u, v);
			maxEdgeInTree = min(maxEdgeInTree, cost);
		}
	}
	return maxEdgeInTree;
}

int findParent(vector <int> & ufds, int x)
{
	int root = x;
	while(ufds[root] != -1)
		root = ufds[root];

	while(ufds[x] != -1){
		int next = ufds[x];
		ufds[x] = root;
		x = next;
	}
	return root;
}

void _union(vector <int> & ufds, int x, int y)
{
	int p1 = findParent(ufds, x);
	int p2 = findParent(ufds, y);
	ufds[p1] = p2;
	return;
}

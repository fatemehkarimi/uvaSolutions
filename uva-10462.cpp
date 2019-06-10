//uva 10462
//Is There A Second Way Left ?

#include <iostream>
#include <climits>
#include <vector>
#include <set>

using namespace std;

void _union(vector <int> & ufds, int x, int y);
int findParent(vector <int> & ufds, int x);
int Kruskal(int n, multiset <pair <int, pair <int, int> > > & Edges, multiset < pair <int, pair <int, int> > > & unUsed);
int dfs(vector < vector <pair <int, int> > > & Tree, vector <bool> & visited, int root, int dest);

int main(void)
{
	int T = 0, tcounter = 0;
	cin >> T;
	while(T--){
		++tcounter;

		int n, m;
		cin >> n >> m;

		multiset <pair <int, pair <int, int> > > Edges;
		for(int i = 0; i < m; ++i){
			int u, v, cost;
			cin >> u >> v >> cost;
			--u, --v;

			if(u == v)
				continue;
			
			Edges.insert(make_pair(cost, make_pair(u, v)));
		}

		multiset < pair <int, pair <int, int> > > unUsed;
		int result = Kruskal(n, Edges, unUsed);
		cout << "Case #" << tcounter << " : ";
		if(result == -1){
			cout << "No way" << endl;
			continue;
		}
		else if(unUsed.empty()){
			cout << "No second way" << endl;
			continue;
		}
		int secondMin = INT_MAX;
		vector < vector < pair <int, int> > > Tree(n);
		for(auto a : Edges){
			Tree[a.second.first].push_back(make_pair(a.second.second, a.first));
			Tree[a.second.second].push_back(make_pair(a.second.first, a.first));
		}

		for(auto a : unUsed){
			int cost = a.first;
			int u = a.second.first;
			int v = a.second.second;

			vector <bool> visited(n, false);
			int minEdge = dfs(Tree, visited, u, v);
			secondMin = min(secondMin, result - minEdge + cost);
		}

		cout << secondMin << endl;
	}
	return 0;
}

int Kruskal(int n, multiset <pair <int, pair <int, int> > > & Edges, multiset < pair <int, pair <int, int> > > & unUsed)
{
	int result = 0;
	vector <int> ufds(n, -1);
	multiset <pair <int, pair <int, int> > > Heap = Edges;

	while(!Heap.empty()){
		int cost = Heap.begin()->first;
		int u = Heap.begin()->second.first;
		int v = Heap.begin()->second.second;
		Heap.erase(Heap.begin());

		if(findParent(ufds, u) != findParent(ufds, v)){
			_union(ufds, u, v);
			result += cost;
		}
		else{
			unUsed.insert(make_pair(cost, make_pair(u, v)));
			auto itr = Edges.find(make_pair(cost, make_pair(u, v)));
			Edges.erase(itr);
		}
	}
	for(int i = 1; i < n; ++i)
		if(findParent(ufds, 0) != findParent(ufds, i))
			result = -1;

	return result;
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
	ufds[p2] = p1;
	return;
}

int dfs(vector < vector <pair <int, int> > > & Tree, vector <bool> & visited, int root, int dest)
{
	int minEdge = INT_MIN;
	visited[root] = true;

	for(auto a : Tree[root])
		if(!visited[a.first]){
			if(a.first == dest)
				return a.second;
			int result = dfs(Tree, visited, a.first, dest);
			if(result != INT_MIN)
				minEdge = max(a.second, result);
		}
	return minEdge;
}

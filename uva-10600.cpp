//uva 10600
//ACM contest and Blackout

#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <set>

using namespace std;

int findParent(vector <int> & ufds, int x);
void _union(vector <int> & ufds, int x, int y);
int Kruskal(set < pair <int, pair <int, int> > > Edges, set < pair <int, pair <int, int> > > & Unused, vector <int> & ufds);

int main(void)
{
	int T;
	cin >> T;
	while(T--){
		int n, m;
		cin >> n >> m;

		set < pair <int, pair <int, int> > > Edges;
		for(int i = 0; i < m; ++i){
			int u, v, cost;
			cin >> u >> v >> cost;
			--u, --v;
			Edges.insert(make_pair(cost, make_pair(u, v)));
		}

		set < pair <int, pair <int, int> > > Unused;
		vector <int> ufds(n, -1);
		int firstMinCost = Kruskal(Edges, Unused, ufds);
		int secondMinCost = INT_MAX;

		for(auto a : Unused){
			int cost = a.first;
			int u = a.second.first;
			int v = a.second.second;
			std::fill(ufds.begin(), ufds.end(), -1);
			set < pair <int, pair <int, int> > > tmp;
			_union(ufds, u, v);
			cost += Kruskal(Edges, tmp, ufds);
			secondMinCost = min(secondMinCost, cost);
		}
		cout << firstMinCost << ' ' << secondMinCost << endl;
	}
	return 0;
}

int Kruskal(set < pair <int, pair <int, int> > > Edges, set < pair <int, pair <int, int> > > & Unused, vector <int> & ufds)
{
	int result = 0;
	while(!Edges.empty()){
		int cost = Edges.begin()->first;
		int u = Edges.begin()->second.first;
		int v = Edges.begin()->second.second;
		Edges.erase(Edges.begin());

		if(findParent(ufds, u) != findParent(ufds, v)){
			_union(ufds, u, v);
			result += cost;
		}
		else
			Unused.insert(make_pair(cost, make_pair(u, v)));
	}
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

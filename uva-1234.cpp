//uva 1234
//RACING

#include <iostream>
#include <vector>
#include <set>

using namespace std;

int parent(vector <int> & ufds, int a);
void Union(vector <int> & ufds, int a, int b);

int main(void)
{
	int T = 0;
	cin >> T;
	while(T--){
		int n, m;
		cin >> n >> m;

		set < pair <int, pair <int, int> >, greater <pair <int, pair <int, int> > > > kruskalSet;

		long long int totalCost = 0;

		for(int i = 0; i < m; ++i){
			int u, v, cost;
			cin >> u >> v >> cost;

			--u, --v;
			totalCost += cost;
			kruskalSet.insert(make_pair(cost, make_pair(u, v)));
		}

		vector <int> ufds(n, -1);
		long long int treeCost = 0;

		while(!kruskalSet.empty()){
			int cost = kruskalSet.begin()->first;
			int u = kruskalSet.begin()->second.first;
			int v = kruskalSet.begin()->second.second;

			kruskalSet.erase(kruskalSet.begin());

			if(parent(ufds, u) != parent(ufds, v)){
				Union(ufds, u, v);
				treeCost += cost;
			}
		}

		cout << totalCost - treeCost << endl;
	}
	cin >> T; //removing 0 at the end of input

	return 0;
}

void Union(vector <int> & ufds, int a, int b)
{
	int p1 = parent(ufds, a);
	int p2 = parent(ufds, b);

	if(p1 == p2) return;//already in a set

	ufds[p2] = p1;
}

int parent(vector <int> & ufds, int a)
{
	int x = a;
	while(ufds[x] != -1)
		x = ufds[x];

	while(ufds[a] != -1){
		int tmp = ufds[a];
		ufds[a] = x;
		a = tmp;
	}

	return x;
}

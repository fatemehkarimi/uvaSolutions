//uva 1208
//Oreon

#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>

using namespace std;

void Prim(vector < map <int, int> > & Graph, set <pair <int, pair <int, int> > > & result);

int main(void)
{
	int T = 0, tcounter = 0;
	cin >> T;
	while(T--){
		++tcounter;

		int n = 0;
		cin >> n;

		vector < map <int, int> > Graph(n);
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j){
				int personnel = 0;
				scanf("%d,", &personnel);
				if(!personnel)
					continue;

				Graph[i].insert(make_pair(j, personnel));
				Graph[j].insert(make_pair(i, personnel));
			}

		set <pair <int, pair <int, int> > > result;
		Prim(Graph, result);

		cout << "Case " << tcounter << ":" << endl;
		for(auto a : result)
			cout << (char)(min(a.second.second, a.second.first) + 'A') << '-' << (char)(max(a.second.second, a.second.first) + 'A')
				 << ' ' << a.first << endl;
	}
	return 0;
}

void Prim(vector < map <int, int> > & Graph, set <pair <int, pair <int, int> > > & result)
{
	vector <bool> visited(Graph.size(), false);
	set < pair <int, pair <int, int> > > Heap;
	visited[0] = true;

	for(auto a : Graph[0])
		Heap.insert(make_pair(a.second, make_pair(0, a.first)));

	while(!Heap.empty()){
		pair <int, pair <int, int> > edge = *Heap.begin();
		Heap.erase(Heap.begin());

		int value = edge.first;
		int u = edge.second.first;
		int v = edge.second.second;

		if(!visited[v]){
			result.insert(make_pair(value, make_pair(u, v)));
			visited[v] = true;
			for(auto a : Graph[v])
				Heap.insert(make_pair(a.second, make_pair(v, a.first)));
		}
	}
	return;
}

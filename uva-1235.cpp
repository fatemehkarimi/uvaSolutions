//uva 1235
//Anti Brute Force Lock

#include <iostream>
#include <climits>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

int calc_cost(string a, string b);
int Prim(vector < multimap <int, int> > & Graph);

int main(void)
{
	int T = 0;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		++n;
		vector <string> locks(n);
		locks[0] = "0000";
		for(int i = 1; i < n; ++i)
			cin >> locks[i];

		vector < multimap <int, int> > Graph(n);
		int min_cost_for_zero = calc_cost(locks[0], locks[1]);//"0000" has only 1 edge to the lock
		int min_cost_zero_index = 1;						 //with minimum cost
		for(int i = 2; i < n; ++i){
			int edgeCost = calc_cost(locks[0], locks[i]);
			if(min_cost_for_zero > edgeCost){
				min_cost_for_zero = edgeCost;
				min_cost_zero_index = i;
			}
		}

		Graph[0].insert(make_pair(min_cost_zero_index, min_cost_for_zero));

		for(int i = 1; i < n; ++i)
			for(int j = 1; j < n; ++j)
				Graph[i].insert(make_pair(j, calc_cost(locks[i], locks[j])));

		int result = Prim(Graph);
		cout << result << endl;
	}
	return 0;
}

int Prim(vector < multimap <int, int> > & Graph)
{
	int root = 0;
	int minCost = 0;
	int n = Graph.size();
	vector <bool> visited(n, false);
	set < pair <int, pair <int, int> > > Heap;

	for(auto a : Graph[root])
		Heap.insert(make_pair(a.second, make_pair(root, a.first)));
	visited[root] = true;

	while(!Heap.empty()){
		pair <int, pair <int, int> > Edge = *Heap.begin();
		Heap.erase(Heap.begin());

		int v = Edge.second.second;
		int cost = Edge.first;

		if(!visited[v]){
			visited[v] = true;
			minCost += cost;
			root = v;
			for(auto a : Graph[root])
				Heap.insert(make_pair(a.second, make_pair(root, a.first)));
		}
	}
	return minCost;
}

int calc_cost(string a, string b)
{
	int cost = 0;
	for(unsigned int i = 0; i < a.size(); ++i){
		char smaller = min(a[i], b[i]);
		char greater = max(a[i], b[i]);
		cost += min(greater - smaller, 10 - (greater - smaller));
	}
	return cost;
}

//uva 534
//Frogger

#include <iostream>
#include <climits>
#include <iomanip>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

void Prim(vector < pair <int, int> > & Stones, vector < vector <int> > & Tree);
double minDis(pair <int, int> a, pair <int, int> b);
void dfs(vector < vector <int> > & Tree, vector <bool> & visited, vector <int> & parent, int root);

int main(void)
{
	int n = 0, tcounter = 0;
	while(true){
		++tcounter;
		cin >> n;

		if(n == 0)
			break;

		vector < pair <int, int> > Stones(n);
		for(int i = 0; i < n; ++i)
			cin >> Stones[i].first >> Stones[i].second;

		vector < vector <int> > Tree(n);//MST tree result from Prim
		Prim(Stones, Tree);

		vector <int> parents(n, -1);
		vector <bool> visited(n, false);
		dfs(Tree, visited, parents, 0);

		vector <int> Path;
		int destin = 1;
		while(destin != -1){
			Path.push_back(destin);
			destin = parents[destin];
		}

		double minEdgeValue = LLONG_MIN;
		for(int i = 0; i < (int)Path.size() - 1; ++i)
			minEdgeValue = max(minEdgeValue, minDis(Stones[Path[i]], Stones[Path[i + 1]]));

		cout << "Scenario #" << tcounter << endl;
		cout << "Frog Distance = " << fixed << setprecision(3) << minEdgeValue << endl;
		cout << endl; 
	}
	return 0;
}

void Prim(vector < pair <int, int> > & Stones, vector < vector <int> > & Tree)
{
	int n = Stones.size();
	vector <bool> visited(n, false);
	set < pair <double, pair <int, int> > > Heap;
	int start = 0;

	for(int i = 0; i < n; ++i)
		if(i != start)
			Heap.insert(make_pair(minDis(Stones[start], Stones[i]), make_pair(start, i)));
	visited[start] = true;

	while(!Heap.empty()){
		pair <double , pair <int, int> > Edge = *Heap.begin();
		Heap.erase(Heap.begin());
		int u = Edge.second.first;
		int v = Edge.second.second;

		if(!visited[v]){
			visited[v] = true;
			Tree[u].push_back(v);
			Tree[v].push_back(u);
			start = v;
			for(int i = 0; i < n; ++i)
			if(i != start)
				Heap.insert(make_pair(minDis(Stones[start], Stones[i]), make_pair(start, i)));
		}
	}
	return;
}

void dfs(vector < vector <int> > & Tree, vector <bool> & visited, vector <int> & parent, int root)
{
	visited[root] = true;
	for(auto a : Tree[root])
		if(!visited[a]){
			parent[a] = root;
			dfs(Tree, visited, parent, a);
		}
	return;
}

double minDis(pair <int, int> a, pair <int, int> b)
{
	double result = 0;
	result = (a.first - b.first) * (a.first - b.first);
	result += ((a.second - b.second) * (a.second - b.second));
	result = sqrt(result);
	return result;
}

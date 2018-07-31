//uva 11504
//Dominos

#include <iostream>
#include <vector>
#include <stack>
#include <map>

using namespace std;

void DFS(vector <vector <int> > & Graph, vector <int> & visited, int start, int group);
void DFS(vector < vector <int> > & Graph, vector <bool> & visited, int start, stack <int> & order);

int main(void)
{
	int T = 0;
	cin >> T;

	while (T--) {
		int n, m;
		cin >> n >> m;

		vector < vector <int> > Graph(n);
		vector < vector <int> > TGraph(n);

		for (int i = 0; i < m; ++i){
			int t1, t2;
			cin >> t1 >> t2;
			--t1;
			--t2;

			Graph[t1].push_back(t2);
			TGraph[t2].push_back(t1);
		}

		vector <bool> visited(n, 0);
		stack <int> order;
		for (int i = 0; i < n; ++i)
			if (!visited[i])
				DFS(Graph, visited, i, order);


		vector <int> group(n, -1);
		while (!order.empty()){
			int top = order.top();
			order.pop();

			if (group[top] == -1)
				DFS(TGraph, group, top, top);
		}

		map <int, int> inEdge;
		for (int i = 0; i < n; ++i)
			inEdge[group[i]] = 0;

		for (int i = 0; i < n; ++i)
			for (int j = 0; j < Graph[i].size(); ++j)
				if (group[i] != group[Graph[i][j]])
					++inEdge[group[Graph[i][j]]];


		int falls = 0;
		for (auto a : inEdge)
			if (a.second == 0)
				++falls;

			cout << falls << endl;
	}
	return 0;
}


void DFS(vector < vector <int> > & Graph, vector <bool> & visited, int start, stack <int> & order)
{
	visited[start] = 1;

	for (auto a : Graph[start])
		if (!visited[a])
			DFS(Graph, visited, a, order);

	order.push(start);
	return;
}

void DFS(vector < vector <int> > & Graph, vector <int> & visited, int start, int group)
{
	visited[start] = group;

	for (auto a : Graph[start])
		if (visited[a] == -1)
			DFS(Graph, visited, a, group);

	return;
}

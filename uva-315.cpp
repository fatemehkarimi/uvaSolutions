//uva 315
//Network

#include <cstdio>
#include <iostream>
#include <vector>
#include <list>

using namespace std;

void DFS(vector < list<int> > & Graph, vector <bool> & visited, int start);

int main(void)
{
	int n = 0;
	while (1) {
		cin >> n;

		if (n == 0)
			break;

		vector <list <int> > Graph(n);

		while (1) {
			int vertex;
			cin >> vertex;

			if (vertex == 0)
				break;

			--vertex;

			char c = ' ';
			int u = 0;
			while(1){
				scanf("%c", &c);
				if (c == '\n')
					break;

				scanf("%d", &u);

				--u;
				Graph[vertex].push_back(u);
				Graph[u].push_back(vertex);

			}
		}

		int bottleneck = 0;
		for (int i = 0; i < n; ++i){
			vector <list <int> > tmpGraph(n);

			for (int j = 0; j < n; ++j)
				if (j != i){
					for (auto a : Graph[j])
						if (a != i)
							tmpGraph[j].push_back(a);
				}

			vector <bool> visited(n, false);
			DFS(tmpGraph, visited, (i + 1) % n);

			for(int x = 0; x < n; ++x)
				if (x != i && !visited[x]){
					++bottleneck;
					break;
				}
		}

		cout << bottleneck << endl;
	}
	return 0;
}


void DFS(vector < list<int> > & Graph, vector <bool> & visited, int start)
{
	visited[start] = true;

	for (auto a : Graph[start])
		if (!visited[a])
			DFS(Graph, visited, a);

	return;
}

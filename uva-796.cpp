//uva 796
//Critical Links

#include <iostream>
#include <vector>
#include <set>

using namespace std;

void DFS(vector < vector <int> > & Graph, vector <int> & components, int start, int group);

int main(void)
{
	int n = 0;
	while (cin >> n) {
		vector < vector <int> > Graph(n);
		set < pair <int, int> > edges;

		for (int i = 0; i < n; ++i){

			int t1;
			cin >> t1;

			char c;
			cin >> c;

			int e;
			cin >> e;

			cin >> c;

			for (int i = 0; i < e; ++i){
				int t2;
				cin >> t2;

				Graph[t1].push_back(t2);

				if (edges.find(make_pair(t1, t2)) == edges.end() && edges.find(make_pair(t2, t1)) == edges.end())
					edges.insert(make_pair(t1, t2));
			}
		}


		vector <int> components(n, -1);
		for (int i = 0; i < n; ++i)
			if (components[i] == -1)
				DFS(Graph, components, i, i);

		set < pair <int, int> > result;


		while (!edges.empty()){
			pair <int, int> edge = *edges.begin();
			edges.erase(edges.begin());

			vector < vector <int> > tmpGraph(n);

			for (int i = 0; i < n; ++i)
				for (int j = 0; j < Graph[i].size(); ++j)
					if (i != edge.first  && i != edge.second){
						tmpGraph[i].push_back(Graph[i][j]);
					}
					else if (i == edge.first || i == edge.second){
						if (Graph[i][j] != edge.first && Graph[i][j] != edge.second)
							tmpGraph[i].push_back(Graph[i][j]);
					}


			vector <int> parts(n, -1);
			for (int i = 0; i < n; ++i)
				if (parts[i] == -1)
					DFS(tmpGraph, parts, i, i);


			for (int i = 0; i < n; ++i)
				if (parts[i] != components[i]){
					if (edge.first <= edge.second)
						result.insert(edge);
					else
						result.insert(make_pair(edge.second, edge.first));
					break;
				}
		}


		cout << result.size() << " critical links" << endl;
		for (auto a : result)
			cout << a.first << " - " << a.second << endl;

		cout << endl;
	}
	return 0;
}


void DFS(vector < vector <int> > & Graph, vector <int> & components, int start, int group)
{
	components[start] = group;
	for (auto a : Graph[start])
		if (components[a] == -1)
			DFS(Graph, components, a, group);

	return;
}

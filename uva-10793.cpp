//uva 10793
//The Orc Attack

#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <map>

using namespace std;

void floyd_warshall(vector < vector <int> > & Graph);

int main(void)
{
	int T = 0, map_counter = 0;
	cin >> T;
	while(T--){
		++map_counter;

		int l, d;
		cin >> l >> d;
		vector < vector <int> > Graph(l, vector <int> (l, INT_MAX));

		for(int i = 0; i < l; ++i)
			Graph[i][i] = 0;

		for(int i = 0; i < d; ++i){
			int u, v, c;
			cin >> u >> v >> c;

			--u, --v;

			Graph[u][v] = Graph[v][u] = min(Graph[u][v], c);
		}

		floyd_warshall(Graph);

		int result_node = -2;
		int min_distance = INT_MAX;

		for(int i = 0; i < l; ++i){
			bool valid_node = 1;
			for(int j = 0; j < 5; ++j)
				if(Graph[j][i] != Graph[0][i])
					valid_node = 0;

			if(valid_node){
				int far_dist = *std::max_element(Graph[i].begin(), Graph[i].end());

				if(far_dist < min_distance){
					result_node = i;
					min_distance = far_dist;
				}
			}
		}
		cout << "Map " << map_counter<< ": " << (result_node != -2 ? min_distance : -1) << endl;
	}
	return 0;
}


void floyd_warshall(vector < vector <int> > & Graph)
{
	int n = Graph.size();

	for(int k = 0; k < n; ++k)
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j)
				if(Graph[i][k] != INT_MAX && Graph[k][j] != INT_MAX)
					Graph[i][j] = min(Graph[i][j], Graph[i][k] + Graph[k][j]);
	return;
}

//uva 10724
//Road Construction

#include <iostream>
#include <climits>
#include <vector>
#include <cmath>
#include <map>
#include <set>

using namespace std;

double distance(pair <int, int> a, pair <int, int> b);
void Floyd_Warshall(vector < vector <double> > & Graph);

int main(void)
{
	int n, m;
	while(true){
		cin >> n >> m;

		if(n == 0 && m == 0)
			break;

		vector < pair <int, int> > points(n);

		for(int i = 0; i < n; ++i){
			int x, y;
			cin >> x >> y;

			points[i] = make_pair(x, y);
		}

		vector < vector <double> > Graph(n, vector <double> (n, LLONG_MAX));
		vector < vector <bool> > edges(n ,vector <bool> (n, false));

		for(int i = 0; i < n; ++i){
			Graph[i][i] = 0;
			edges[i][i] = true;
		}

		for(int i = 0; i < m; ++i){
			int u, v;
			cin >> u >> v;

			--u, --v;

			Graph[u][v] = distance(points[u], points[v]);
			Graph[v][u] = Graph[u][v];

			edges[u][v] = true;
			edges[v][u] = true;
		}

		Floyd_Warshall(Graph);

		double max_CEdge = 0;
		pair <int, int> result_edge;

		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j)
				if(!edges[i][j]){
					double C_ij = 0;
					double edge_cost = distance(points[i], points[j]);

					for(int p = 0; p < n; ++p)
						for(int q = 0; q < n; ++q){
							double new_way_cost = Graph[p][i] + edge_cost + Graph[j][q];
							new_way_cost = min(new_way_cost, Graph[p][q]);

							C_ij += (Graph[p][q] - new_way_cost);
						}

					if(C_ij > 1){
						if(C_ij > max_CEdge){
							max_CEdge = C_ij;
							result_edge = make_pair(i, j);
						}
						else if(C_ij == max_CEdge && distance(points[result_edge.first], points[result_edge.second]) < edge_cost)
							result_edge = make_pair(i, j);
					}
				}

		if(max_CEdge != 0)
			cout << min(result_edge.first, result_edge.second) + 1 << ' ' << max(result_edge.first, result_edge.second) + 1 << endl;
		else
			cout << "No road required" << endl;
	}
	return 0;
}


double distance(pair <int, int> a, pair <int, int> b)
{
	int tmp1 = a.first - b.first;
	tmp1 *= tmp1;

	int tmp2 = a.second - b.second;
	tmp2 *= tmp2;

	return sqrt(tmp1 + tmp2);
}


void Floyd_Warshall(vector < vector <double> > & Graph)
{
	int n = Graph.size();

	for(int k = 0; k < n; ++k)
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j)
				if(Graph[i][k]  != LLONG_MAX && Graph[k][j] != LLONG_MAX)
					Graph[i][j] = min(Graph[i][k] + Graph[k][j], Graph[i][j]);

	return;
}

//uva 10354
//Avoiding Your Boss

#include <iostream>
#include <vector>
#include <climits>
#include <map>
#include <set>

using namespace std;


int Dijkstra(vector <map <int, int> > & Graph, vector <int> & path, int source, int destination);


int main(void)
{
	int n, e, Bd, Bs, Ys, Yd;
	while(cin >> n >> e >> Bs >> Bd >> Ys >> Yd){
		--Bd, --Bs, --Ys, --Yd;

		vector <map <int, int> > Graph(n);

		for(int i = 0; i < e; ++i){
			int u, v, d;
			cin >> u >> v >> d;

			--u, --v;

			Graph[u][v] = d;
			Graph[v][u] = d;
		}

		for(int i = 0; i < n; ++i)
			Graph[i][i] = 0;

		vector <int> bossPath;
		vector <int> removeNode;
		int bossPathCost = Dijkstra(Graph, bossPath, Bs, Bd);

		if(bossPathCost != INT_MAX){//there is a path for boss to get to destination
			for(auto a : bossPath)
				removeNode.push_back(a);

			for(int i = 0; i < bossPath.size() - 1; ++i){
				Graph[bossPath[i]].erase(bossPath[i + 1]);
				Graph[bossPath[i + 1]].erase(bossPath[i]);
			}


			while(true){
				bossPath.clear();
				int cost = Dijkstra(Graph, bossPath, Bs, Bd);

				if(cost != bossPathCost)
					break;

				for(auto a : bossPath)
					removeNode.push_back(a);

				for(int i = 0; i < bossPath.size() - 1; ++i){
					Graph[bossPath[i]].erase(bossPath[i + 1]);
					Graph[bossPath[i + 1]].erase(bossPath[i]);
				}
			}
		}

		for(auto node : removeNode)
			for(int i = 0; i < n; ++i){
				Graph[i].erase(node);
				Graph[node].erase(i);
			}

		int yourCost = Dijkstra(Graph, bossPath, Ys, Yd);
		if(yourCost == INT_MAX)
			cout << "MISSION IMPOSSIBLE." << endl;
		else
			cout << yourCost << endl;
	} 

	return 0;
}

int Dijkstra(vector <map <int, int> > & Graph, vector <int> & path, int source, int destination)
{
	int n = Graph.size();
	vector <int> minCost(n, INT_MAX);
	vector <int> parent(n, -1);
	set <pair <int, int> > currCost;

	if(Graph[source].find(source) == Graph[source].end())
		return INT_MAX;
	else
		minCost[source] = Graph[source][source];

	currCost.insert(make_pair(minCost[source], source));

	while(!currCost.empty()){
		int value = currCost.begin()->first;
		int node = currCost.begin()->second;

		currCost.erase(currCost.begin());

		for(auto a : Graph[node])
			if(a.second + value < minCost[a.first]){
				currCost.erase(make_pair(minCost[a.first], a.first));
				minCost[a.first] = a.second + value;
				parent[a.first] = node;
				currCost.insert(make_pair(minCost[a.first], a.first));
 			}
	}
	
	//making path
	path.push_back(destination);
	int dst = parent[destination];

	while(dst != -1 && parent[dst] != -1){
		path.push_back(dst);
		dst = parent[dst];
	}
	path.push_back(source);

	return minCost[destination];
}

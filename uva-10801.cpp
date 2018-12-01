//uva 10801
//Lift Hopping

#include <iostream>
#include <sstream>
#include <climits>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

int Dijkstra(map <int, map <int, map <int, int> > > & Graph, int destination);

int main(void)
{
	int n, k;
	while(cin >> n >> k){
		vector <int> time(n);

		for(int i = 0; i < n; ++i)
			cin >> time[i];
		getchar();

		map <int, map <int, map <int, int> > > Graph;//node1, node2, elevator num, cost

		for(int i = 0; i < n; ++i){
			string str;
			getline(std::cin, str);
			vector <int> floors;
			stringstream sstr(str);
			int f;
			while(sstr >> f)
				floors.push_back(f);

			for(int p = 0; p < floors.size(); ++p)
				for(int q = p + 1; q < floors.size(); ++q){
					int pqTime = abs(floors[p] - floors[q]) * time[i];
					Graph[floors[p]][floors[q]][i] = pqTime;
					Graph[floors[q]][floors[p]][i] = pqTime;
				}
		}

		int result = Dijkstra(Graph, k);
		if(result == INT_MAX)
			cout << "IMPOSSIBLE" << endl;
		else
			cout << result << endl;

	}
	return 0;
}

int Dijkstra(map <int, map <int, map <int, int> > > & Graph, int destination)
{
	map <int, int> bestTime;
	for(auto a : Graph)
		bestTime.insert(make_pair(a.first, INT_MAX));
	bestTime[0] = 0;

	set < pair <int, int> > curr_time;//value, node
	curr_time.insert(make_pair(0, 0));

	map <int, int> curr_elev;
	for(auto a : Graph)
		curr_elev.insert(make_pair(a.first, -1));

	while(!curr_time.empty()){
		int value = curr_time.begin()->first;
		int node1 = curr_time.begin()->second;
		curr_time.erase(curr_time.begin());

		for(auto a : Graph[node1]){
			int node2 = a.first;
			int node2_currTime = bestTime[node2];
			bool nodeModified = 0;

			for(auto b : a.second){
				int elev = b.first;
				int elev_time = b.second;

				if((curr_elev[node1] == -1 || curr_elev[node1] == elev) && value + elev_time < node2_currTime){
					node2_currTime = value + elev_time;
					curr_elev[node2] = elev;
					nodeModified = 1;
				}

				if(curr_elev[node1] != elev && value + elev_time + 60 < node2_currTime){
					node2_currTime = value + elev_time + 60;
					curr_elev[node2] = elev;
					nodeModified = 1;
				}
			}

			if(nodeModified){
				curr_time.erase(make_pair(bestTime[node2], node2));
				bestTime[node2] = node2_currTime;
				curr_time.insert(make_pair(bestTime[node2], node2));
			}
		}

	}

	if(bestTime.find(destination) == bestTime.end())
		return INT_MAX;
	else
		return bestTime[destination];
}

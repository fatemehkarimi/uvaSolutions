//uva 10947
//Bear with me, again..

#include <iostream>
#include <climits>
#include <vector>
#include <cmath>
#include <map>
#include <set>

using namespace std;

typedef struct island{
	int x;
	int y;
	int r;
}island;

double distance(island &a, island &b);
void Dijkstra(vector < map <int, double> > & Graph, vector <double> & min_distance);

int main(void)
{
	int K, M;
	while(cin >> K >> M){
		vector <island> islands(2);

		cin >> islands[0].x >> islands[0].y >> islands[0].r; //source island
		cin >> islands[1].x >> islands[1].y >> islands[1].r; //destination island

		int n;
		cin >> n;

		for(int i = 0; i < n; ++i){
			island tmp;
			cin >> tmp.x >> tmp.y >> tmp.r;
			islands.push_back(tmp);
		}

		n += 2;// number of islands

		vector < map <int, double> > Graph(n);
		for(int i = 0; i < n; ++i)
			for(int j = i + 1; j < n; ++j){
				double dis = distance(islands[i], islands[j]);
				if(dis <= K * M){
					Graph[i].insert(make_pair(j, dis));
					Graph[j].insert(make_pair(i, dis));
				}
			}

		vector <double> min_distance(n, LLONG_MAX);
		Dijkstra(Graph, min_distance);

		if(min_distance[1] != LLONG_MAX)
			cout << "Larry and Ryan will escape!" << endl;
		else
			cout << "Larry and Ryan will be eaten to death." << endl;
	}
	return 0;
}


double distance(island &a, island &b)
{
	int tmp1 = a.x - b.x;
	tmp1 *= tmp1;

	int tmp2 = a.y - b.y;
	tmp2 *= tmp2;

	return (sqrt(tmp1 + tmp2) - a.r - b.r);
}

void Dijkstra(vector < map <int, double> > & Graph, vector <double> & min_distance)
{
	min_distance[0] = 0;

	set < pair <double, int> > minHeap;
	minHeap.insert(make_pair(0, 0));

	while(!minHeap.empty()){
		int top = minHeap.begin()->second;
		double cost = minHeap.begin()->first;
		minHeap.erase(minHeap.begin());

		for(auto a : Graph[top])
			if(cost + a.second < min_distance[a.first]){
				minHeap.erase(make_pair(min_distance[a.first], a.first));
				min_distance[a.first] = cost + a.second;
				minHeap.insert(make_pair(min_distance[a.first], a.first));
			}
	}
	return;
}

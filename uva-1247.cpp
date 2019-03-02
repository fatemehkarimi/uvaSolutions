//uva 1247
//Interstar Transport

#include <iostream>
#include <climits>
#include <vector>
#include <stack>
#include <set>
#include <map>

using namespace std;

void Dijkstra(vector < map <int, int> > & Graph, int source, int destin, stack <int> & path);

int main(void)
{
	int s, p;
	while(cin >> s >> p){
		vector < map <int, int> > Graph(26);

		for(int i = 0; i < p; ++i){
			char p1, p2;
			int value;

			cin >> p1 >> p2 >> value;

			int index1 = p1 - 'A';
			int index2 = p2 - 'A';
			Graph[index1].insert(make_pair(index2, value));
			Graph[index2].insert(make_pair(index1, value));
		}

		int query;
		cin >> query;

		for(int i = 0; i < query; ++i){
			char p1, p2;
			cin >> p1 >> p2;

			stack <int> path;
			Dijkstra(Graph, (int)(p1 - 'A'), (int)(p2 - 'A'), path);

			cout << (char)(path.top() + 'A');
			path.pop();
			while(!path.empty()){
				cout << ' ' << (char)(path.top() + 'A');
				path.pop();
			}

			cout << endl;
		}
	}
	return 0;
}

void Dijkstra(vector < map <int, int> > & Graph, int source, int destin, stack <int> & path)
{
	vector <int> min_distance(26, INT_MAX);
	vector <int> parent(26, -1);
	vector <int> levels(26, INT_MAX);
	set < pair <int, int> > minHeap;

	min_distance[source] = true;
	levels[source] = 0;
	minHeap.insert(make_pair(0, source));

	while(!minHeap.empty()){
		int top = minHeap.begin()->second;
		minHeap.erase(minHeap.begin());

		for(auto node : Graph[top])
			if(min_distance[top] + node.second < min_distance[node.first]){
				minHeap.erase(make_pair(min_distance[node.first], node.first));
				min_distance[node.first] = min_distance[top] + node.second;
				minHeap.insert(make_pair(min_distance[node.first], node.first));

				levels[node.first] = levels[top] + 1;
				parent[node.first] = top;
			}
			else if(min_distance[top] + node.second == min_distance[node.first])
				if(levels[top] + 1 < levels[node.first]){
					levels[node.first] = levels[top] + 1;
					parent[node.first] = top;
				}
	}

	path.push(destin);
	destin = parent[destin];
	while(destin != -1 && parent[destin] != -1){
		path.push(destin);
		destin = parent[destin];
	}
	path.push(source);
	return;
}

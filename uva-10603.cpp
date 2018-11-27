//uva 10603
//Fill

#include <iostream>
#include <climits>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;

vector <int> Dijkstra(map <int, map <int, int> > & Graph);

int main(void)
{
	int T = 0;
	cin >> T;
	while(T--){
		vector <int> capacity(3);
		int d;
		cin >> capacity[0] >> capacity[1] >> capacity[2] >> d;

		map <int, vector <int> > code_node;
		map <vector <int>,  int> node_code;

		map <int, map <int, int> > Graph;

		vector <int> root_value = {0, 0, capacity[2]};
		code_node[0] = root_value;
		node_code[root_value] = 0;

		int unused_code = 1;

		queue <int> Queue;
		Queue.push(0);

		while(!Queue.empty()){
			int node = Queue.front();
			Queue.pop();

			vector <int> node_values = code_node[node];

			for(int i = 0; i < 3; ++i){//from jug i, pour water to jugs i - 1 && i + 1 if possible
				int pre = (i - 1 + 3) % 3;
				int next = (i + 1) % 3;

				vector <int> pre_value = node_values;
				vector <int> next_value = node_values;

				int rem_pre = capacity[pre] - node_values[pre];//remainder capacity of jugs
				int rem_next = capacity[next] - node_values[next];

				int moved_water_pre = min(rem_pre, node_values[i]);
				int moved_water_next = min(rem_next, node_values[i]);

				pre_value[i] -= moved_water_pre;
				pre_value[pre] += moved_water_pre;

				next_value[i] -= moved_water_next;
				next_value[next] += moved_water_next;

				bool inserted_before_pre = 1;
				bool inserted_before_next = 1;

				if(node_code.find(pre_value) == node_code.end())
					inserted_before_pre = 0;
				if(node_code.find(next_value) == node_code.end())
					inserted_before_next = 0;

				if(!inserted_before_pre){
					node_code[pre_value] = unused_code;
					code_node[unused_code] = pre_value;
					Queue.push(unused_code++);
				}

				if(!inserted_before_next){
					node_code[next_value] = unused_code;
					code_node[unused_code] = next_value;
					Queue.push(unused_code++);
				}


				Graph[node].insert(make_pair(node_code[pre_value], moved_water_pre));
				Graph[node].insert(make_pair(node_code[next_value], moved_water_next));
			}
		}

		//uncomment to see the nodes and the code assigned to each node
		//also you can see the Graph with the values on each edge
		/*for(auto a : code_node){
			cout << a.first << ": ";
			for(auto b : a.second)
				cout << b << ' ';
			cout << endl;
		}

		for(auto a : Graph){
			cout << a.first << ": ";//a.first=node1
			for(auto b : a.second)
				cout << b.first << ' ' << b.second << ", ";//b.first=node2, b.second=value on edge
			cout << endl;
		}*/

		int max_water = 0;
		int water_moved = INT_MAX;

		vector <int> result = Dijkstra(Graph);

		for(int i = 0; i < result.size(); ++i){
			vector <int> node_value = code_node[i];

			for(int j = 0; j < 3; ++j)
				if(node_value[j] > max_water && node_value[j] <= d){
					max_water = node_value[j];
					water_moved = result[i];
				}
				else if (node_value[j] == max_water && result[i] < water_moved)
					water_moved = result[i];
		}

		cout << water_moved << ' ' << max_water << endl;
	}

	return 0;
}

vector <int> Dijkstra(map <int, map <int, int> > & Graph)
{
	vector <int> distance(Graph.size(), INT_MAX);
	distance[0] = 0;

	set <pair <int, int> > tmp_dis;
	tmp_dis.insert(make_pair(0, 0));

	while(!tmp_dis.empty()){
		pair <int, int> top = *tmp_dis.begin();
		tmp_dis.erase(top);

		int value = top.first;
		int node = top.second;

		for(auto a : Graph[node])
			if(value + a.second < distance[a.first]){
				tmp_dis.erase(make_pair(distance[a.first], a.first));
				distance[a.first] = value + a.second;
				tmp_dis.insert(make_pair(distance[a.first], a.first));
			}
	}

	return distance;
}

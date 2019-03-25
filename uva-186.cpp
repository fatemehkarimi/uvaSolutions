//uva 186
//Trip Routing

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <climits>
#include <map>
#include <set>

using namespace std;

void Dijkstra(map <int, vector < pair <int, int> > > & Graph, int source, int dest, vector <int> & path);

int main(void)
{
	map <string, int> city_code;
	map <int, string> code_city;
	map < pair <int, int>, string> road_names;
	map <int, vector < pair <int, int> > > road_distance;

	int n_city = 0;
	while(true){
		string segment;
		getline(std::cin, segment);

		if(segment == "")
			break;

		stringstream stream1(segment);
		string left, right, name, num;
		int distance;

		getline(stream1, left, ',');
		getline(stream1, right, ',');
		getline(stream1, name, ',');
		stream1 >> distance;

		if(city_code.find(left) == city_code.end()){
			city_code[left] = n_city;
			code_city[n_city] = left;
			++n_city;
		}

		if(city_code.find(right) == city_code.end()){
			city_code[right] = n_city;
			code_city[n_city] = right;
			++n_city;
		}		

		road_names.insert(make_pair(make_pair(city_code[left], city_code[right]), name));
		road_names.insert(make_pair(make_pair(city_code[right], city_code[left]), name));
		road_distance[city_code[left]].push_back(make_pair(city_code[right], distance));
		road_distance[city_code[right]].push_back(make_pair(city_code[left], distance));
	}

	while(true){
		string segment;
		getline(std::cin, segment);

		if(segment == "")
			break;

		stringstream stream1(segment);
		string source, destination;

		getline(stream1, source, ',');
		getline(stream1, destination, ',');

		int code_source = city_code[source];
		int code_dest = city_code[destination];

		vector <int> path;
		Dijkstra(road_distance, code_source, code_dest, path);

		cout << endl << endl;

		cout << "From                 To                   Route      Miles" << endl;
		cout << "-------------------- -------------------- ---------- -----" << endl;
		int path_cost = 0;
		for(int i = path.size() - 2; i >= 0; --i){
			cout << code_city[path[i + 1]];
			for(int j = code_city[path[i + 1]].size(); j <= 20; ++j)
				cout << ' ';
			cout << code_city[path[i]];
			for(int j = code_city[path[i]].size(); j <= 20; ++j)
				cout << ' ';

			cout << road_names[make_pair(path[i + 1], path[i])];
			for(int j = road_names[make_pair(path[i + 1], path[i])].size(); j <= 10; ++j)
				cout << ' ';

			int cost = INT_MAX;
			for(auto a : road_distance[path[i]])
				if(a.first == path[i + 1])
					cost = min(cost, a.second);

			path_cost += cost;
			std::string str_cost = std::to_string(cost);
			for(int j = 1; j <= 5 - str_cost.size(); ++j)
				cout << ' ';
			cout << str_cost << endl;
		}

		cout << "                                                     -----" << endl;
		cout << "                                          Total      ";
		std::string str_cost = std::to_string(path_cost);
		for(int i = 1; i <= 5 - str_cost.size(); ++i)
			cout << ' ';
		cout << str_cost << endl;
	}

	return 0;
}

void Dijkstra(map <int, vector < pair <int, int> > > & Graph, int source, int dest, vector <int> & path)
{
	int n = Graph.size();
	vector <int> min_distance(n, INT_MAX);
	vector <int> parent(n, -1);

	set < pair <int, int> > cur_values;

	min_distance[source] = 0;
	cur_values.insert(make_pair(0, source));

	while(!cur_values.empty()){
		int node = cur_values.begin()->second;
		cur_values.erase(cur_values.begin());


		for(auto a : Graph[node])
			if(min_distance[node] + a.second < min_distance[a.first]){
				cur_values.erase(make_pair(min_distance[a.first], a.first));
				min_distance[a.first] = min_distance[node] + a.second;
				parent[a.first] = node;
				cur_values.insert(make_pair(min_distance[a.first], a.first));
			}
	}

	while(parent[dest] != -1 && dest != -1){
		path.push_back(dest);
		dest = parent[dest];
	}
	path.push_back(source);
	return;
}

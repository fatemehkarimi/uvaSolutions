//uva 274
//Cat and Mouse

#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

void dfs(vector <vector <int> > & Graph, vector <bool> & visited, int start);
void way_without_cat(vector < vector <int> > & Graph, vector <bool> & bad_rooms, vector <bool> & visited, int start);

int main(void)
{
	int T = 0;
	cin >> T;
	while(T--){
		int n, c_home, m_home;
		cin >> n >> c_home >> m_home;

		--m_home, --c_home;

		vector < vector <int> > cat_graph(n);
		vector < vector <int> > mouse_graph(n);

		while(true){
			int u, v;
			cin >> u >> v;

			if(u == -1 && v == -1)
				break;
			--u, --v;
			cat_graph[u].push_back(v);
		}

		getchar();

		while(true){
			int u, v;
			string tmp;
			getline(std::cin, tmp);

			if(tmp == "")
				break;

			stringstream stream(tmp);
			stream >> u >> v;
			--u, --v;
			mouse_graph[u].push_back(v);
		}

		vector <bool> cat_rooms(n, false);
		vector <bool> mouse_rooms(n, false);

		dfs(cat_graph, cat_rooms, c_home);
		dfs(mouse_graph, mouse_rooms, m_home);

		bool result1 = 0, result2 = 0;

		for(int i = 0; i < n; ++i)
			if(cat_rooms[i] & mouse_rooms[i])
				result1 = 1;

		std::fill(mouse_rooms.begin(), mouse_rooms.end(), false);
		way_without_cat(mouse_graph, cat_rooms, mouse_rooms, m_home);

		result2 = mouse_rooms[m_home];

		if(result1)
			cout << 'Y';
		else
			cout << 'N';
		cout << ' ';

		if(result2)
			cout << 'Y';
		else
			cout << 'N';
		cout << endl;

		if(T)
			cout << endl;
	}
	return 0;
}

void dfs(vector <vector <int> > & Graph, vector <bool> & visited, int start)
{
	visited[start] = true;

	for(auto a : Graph[start])
		if(!visited[a])
			dfs(Graph, visited, a);
	return;
}

void way_without_cat(vector < vector <int> > & Graph, vector <bool> & bad_rooms, vector <bool> & visited, int start)
{
	for(auto a : Graph[start])
		if(!visited[a] && !bad_rooms[a]){
			visited[a] = true;
			way_without_cat(Graph, bad_rooms, visited, a);
		}
	return;
}

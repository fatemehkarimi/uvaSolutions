//uva 1160
//X-Plosives

#include <iostream>
#include <vector>

using namespace std;

void dfs(vector < vector <int> > & Graph, vector <bool> & visited, int root, int & result);

int main(void)
{
	int a, b;
	while(cin >> a >> b){
		int n = max(a, b);
		int m = 1;
		vector < pair <int, int> > binding_pairs;
		binding_pairs.push_back(make_pair(a, b));

		while(true){
			cin >> a;
			if(a == -1)
				break;
			cin >> b;
			n = max(n, max(a, b));
			++m;
			binding_pairs.push_back(make_pair(a, b));
		}

		++n;
		vector < vector <int> > Graph(n);
		for(auto a : binding_pairs){
			Graph[a.first].push_back(a.second);
			Graph[a.second].push_back(a.first);
		}

		int result = 0;
		vector <bool> visited(n, false);
		for(int i = 0; i < n; ++i)
			if(!visited[i])
				dfs(Graph, visited, i, result);

		cout << m - result << endl;
	}
	return 0;
}

void dfs(vector < vector <int> > & Graph, vector <bool> & visited, int root, int & result)
{
	visited[root] = true;
	for(auto a : Graph[root])
		if(!visited[a]){
			++result;
			dfs(Graph, visited, a, result);
		}
	return;
}

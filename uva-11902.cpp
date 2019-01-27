//uva 11902
//Dominator

#include <iostream>
#include <vector>

using namespace std;

void dfs(vector < vector <bool> > & Graph, vector <bool> & visited, int start);

int main(void)
{
	int T = 0;
	cin >> T;
	int tcounter = 0;
	while(T--){
		int n = 0;
		cin >> n;

		++tcounter;

		vector < vector <bool> > Graph(n, vector <bool> (n, false));
		vector < vector <bool> > dominate(n, vector <bool> (n, false));

		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j){
				int tmp;
				cin >> tmp;
				if(tmp)
					Graph[i][j] = 1;
			}

		vector <bool> reachable(n, false);
		dfs(Graph, reachable, 0);


		for(int i = 0; i < n; ++i){
			vector <bool> tmp = Graph[i];

			for(int j = 0; j < n; ++j)
				Graph[i][j] = 0;

			vector <bool> new_reachable(n, false);
			dfs(Graph, new_reachable, 0);

			for(int j = 0; j < n; ++j)
				if(reachable[j] && !new_reachable[j])
					dominate[i][j] = 1;

			Graph[i] = tmp;
		}

		//by definition, every node dominates itself.
		for(int i = 0; i < n; ++i)
			if(reachable[i])
				dominate[i][i] = 1;

		cout << "Case " << tcounter << ":" << endl;
		for(int i = 0; i < n + 1; ++i) {
			cout << '+';
			for(int j = 1; j < 2 * n; ++j)
				cout << '-';
			cout << '+' << endl;

			if(i >= n) break;

			cout << '|';
			for(int j = 0; j < n; ++j){
				if(dominate[i][j] == 1)
					cout << 'Y';
				else
					cout << 'N';
				cout << '|';
			}
			cout << endl;
		}

	}
	return 0;
}


void dfs(vector < vector <bool> > & Graph, vector <bool> & visited, int start)
{
	visited[start] = true;
	for(int i = 0; i < Graph[start].size(); ++i)
		if(Graph[start][i] && !visited[i])
			dfs(Graph, visited, i);

	return;
}

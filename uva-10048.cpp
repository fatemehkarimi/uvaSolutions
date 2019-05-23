//uva 10048
//Audiophobia

#include <iostream>
#include <climits>
#include <vector>
#include <map>

using namespace std;

int main(void)
{
	int c, s, q;
	int tcounter = 0;
	bool first = 0;
	while(true){
		cin >> c >> s >> q;

		if(c == 0 && s == 0 && q == 0)
			break;

		++tcounter;

		if(first)
			cout << endl;
		first = 1;

		vector < vector <int> > Graph(c, vector <int> (c, INT_MAX));

		for(int i = 0; i < c; ++i)
			Graph[i][i] = 0;

		for(int i = 0; i < s; ++i){
			int u, v, val;
			cin >> u >> v >> val;
			--u;
			--v;
			Graph[u][v] = Graph[v][u] = min(Graph[u][v], val);
		}

		for(int k = 0; k < c; ++k)
			for(int i = 0; i < c; ++i)
				for(int j = 0; j < c; ++j)
					Graph[i][j] = min(Graph[i][j], max(Graph[i][k], Graph[k][j]));

		cout << "Case #" << tcounter << endl;
		for(int i = 0; i < q; ++i){
			int u, v;
			cin >> u >> v;
			--u;
			--v;
			if(Graph[u][v] != INT_MAX)
				cout << Graph[u][v] << endl;
			else
				cout << "no path" << endl;
		}
	}
	return 0;
}

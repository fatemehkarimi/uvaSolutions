//uva 10977
//Enchanted Forest

#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>

using namespace std;

int BFS(vector <vector <int> > & Graph);

int main(void)
{
	int r, c;
	while(cin >> r >> c, r){
		int m;
		cin >> m;

		vector < vector <int> > Graph(r, vector <int> (c, 0));

		for(int i = 0; i < m; ++i){
			int u, v;
			cin >> u >> v;
			--u, --v;
			Graph[u][v] = -1;
		}

		int n;
		cin >> n;
		for(int i = 0; i < n; ++i){
			int u, v, l;
			cin >> u >> v >> l;
			--u, --v;

			for(int p = u - l; p < u + l + 1; ++p)
				for(int q = v - l; q < v + l + 1; ++q)
					if(p >= 0 && p < r && q >= 0 && q < c)
						if((p - u) * (p - u) + (q - v) * (q - v) <= l * l)
							Graph[p][q] = -1;
		}

		int result = BFS(Graph);
		if(result <= 0)
			cout << "Impossible." << endl;
		else
			cout << result - 1 << endl;
	}
	return 0;
}

int BFS(vector <vector <int> > & Graph)
{
	int r = Graph.size();
	int c = Graph[0].size();

	queue < pair <int, int> > Queue;
	Queue.push(make_pair(0, 0));

	Graph[0][0] = 1;

	while(!Queue.empty()){
		pair <int, int> front = Queue.front();
		Queue.pop();
		int x = front.first;
		int y = front.second;

		int x_ns[] = {-1, 0, 1, 0};
		int y_ns[] = {0, -1, 0, 1};

		for(int i = 0; i < 4; ++i){
			int x_n = x + x_ns[i];
			int y_n = y + y_ns[i];

			if(x_n >= 0 && x_n < r && y_n >= 0 && y_n < c && Graph[x_n][y_n] == 0){
				Graph[x_n][y_n] = Graph[x][y] + 1;
				Queue.push(make_pair(x_n, y_n));
			}
		}
	}
	return Graph[r - 1][c - 1];
}

//uva 11624
//Fire!

#include <iostream>
#include <climits>
#include <string>
#include <vector>
#include <queue>

using namespace std;

void fire_extension(vector <vector <int> > & Graph, int x, int y);
int Joe_run(vector <vector <int> > & Graph, int x, int y);

int main(void)
{
	int T = 0;
	cin >> T;
	while(T--){
		int r, c;
		cin >> r >> c;

		vector <string> maze(r);
		for(int i = 0; i < r; ++i)
			cin >> maze[i];

		vector < vector <int> > Graph(r, vector <int> (c, INT_MAX));
		int xj, yj;
		for(int i = 0; i < r; ++i)
			for(int j = 0; j < c; ++j)
				if(maze[i][j] == '#')
					Graph[i][j] = INT_MIN;

		for(int i = 0; i < r; ++i)
			for(int j = 0; j < c; ++j)
				if(maze[i][j] == 'J'){
					xj = i;
					yj = j;
				}
				else if(maze[i][j] == 'F')
					fire_extension(Graph, i, j);

		int result = Joe_run(Graph, xj, yj);

		if(result == -1)
			cout << "IMPOSSIBLE" << endl;
		else
			cout << result << endl;
	}
	return 0;
}


void fire_extension(vector <vector <int> > & Graph, int x, int y)
{
	int r = Graph.size();
	int c = Graph[0].size();
	queue <pair <int, int> > Queue;

	Graph[x][y] = 1;
	Queue.push(make_pair(x, y));

	while(!Queue.empty()){
		int x_f = Queue.front().first;
		int y_f = Queue.front().second;
		Queue.pop();

		int xs[] = {-1, 0, 0, 1};
		int ys[] = {0, -1, 1, 0};

		for(int i = 0; i < 4; ++i){
			int x_n = x_f + xs[i];
			int y_n = y_f + ys[i];

			if(x_n >= 0 && x_n < r && y_n >= 0 && y_n < c && Graph[x_f][y_f] + 1 < Graph[x_n][y_n]){
				Graph[x_n][y_n] = Graph[x_f][y_f] + 1;
				Queue.push(make_pair(x_n, y_n));
			}
		}
	}
	return;
}

int Joe_run(vector <vector <int> > & Graph, int x, int y)
{
	int r = Graph.size();
	int c = Graph[0].size();
	queue <pair <int, int> > Queue;

	Graph[x][y] = -1;//means Joe has visited this home
	Queue.push(make_pair(x, y));

	while(!Queue.empty()){
		int x_f = Queue.front().first;
		int y_f = Queue.front().second;
		Queue.pop();

		int xs[] = {-1, 0, 0, 1};
		int ys[] = {0, -1, 1, 0};

		for(int i = 0; i < 4; ++i){
			int x_n = x_f + xs[i];
			int y_n = y_f + ys[i];

			if(x_n < 0 || x_n >= r || y_n < 0 || y_n >= c)
				return -Graph[x_f][y_f];
			//negative value of a cell means either it is already visited or it is a wall
			else if(Graph[x_n][y_n] > 0 && -(Graph[x_f][y_f] - 1) < Graph[x_n][y_n]){
				Graph[x_n][y_n] = Graph[x_f][y_f] - 1;
				Queue.push(make_pair(x_n, y_n));
			}
		}
	}
	return -1;
}

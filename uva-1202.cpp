//uva 1202
//Finding Nemo

#include <iostream>
#include <climits>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

#define MAZE_X 200
#define MAZE_Y 200

int Dijkstra(int maze[MAZE_X][MAZE_Y][2], int x_d, int y_d);

int main(void)
{
	int n, m;
	while(true){
		cin >> n >> m;

		if(n == -1 && m == -1)
			break;

		//0: none 1: door 2: wall
		int maze[MAZE_X][MAZE_Y][2] = {};
		for(int i = 0; i < n; ++i){
			int x, y, d, t;
			cin >> x >> y >> d >> t;
			for(int j = 0; j < t; ++j)
				if(d && y + j < MAZE_Y)
					maze[x][y + j][d] = 2;
				else if(!d && x + j < MAZE_X)
					maze[x + j][y][d] = 2;
		}

		for(int i = 0; i < m; ++i){
			int x, y, d;
			cin >> x >> y >> d;
			maze[x][y][d] = 1;
		}

		double x_nemo, y_nemo;
		cin >> x_nemo >> y_nemo;

		if(x_nemo >= 200 || y_nemo >= 200){
			cout << 0 << endl;
			continue;
		}

		int result = Dijkstra(maze, (int)floor(x_nemo), (int)floor(y_nemo));
		cout << result << endl;
	}
	return 0;
}


int Dijkstra(int maze[MAZE_X][MAZE_Y][2], int x_d, int y_d)
{
	int x_around[4] = {0, -1, 0, 1};
	int y_around[4] = {-1, 0, 1, 0};

	int min_cost[MAZE_X][MAZE_Y];
	for(int i = 0; i < MAZE_X; ++i)
		for(int j = 0; j < MAZE_Y; ++j)
			min_cost[i][j] = INT_MAX;
	min_cost[0][0] = 0;
	set < pair <int, pair <int, int> > > Heap;
	Heap.insert(make_pair(0, make_pair(0, 0)));

	while(!Heap.empty()){
		int x_f = Heap.begin()->second.first;
		int y_f = Heap.begin()->second.second;
		Heap.erase(Heap.begin());

		for(int i = 0; i < 4; ++i){
			int x_n = x_f + x_around[i];
			int y_n = y_f + y_around[i];

			if(x_n >= 0 && x_n < MAZE_X && y_n >= 0 && y_n < MAZE_Y){
				int wall_none;
				if(i < 2)
					wall_none = maze[x_f][y_f][i];
				else if(i == 2)
					wall_none = maze[x_n][y_n][0];
				else
					wall_none = maze[x_n][y_n][1];

				if(wall_none != 2 && min_cost[x_f][y_f] + wall_none < min_cost[x_n][y_n]){//not a wall
					Heap.erase(make_pair(min_cost[x_n][y_n], make_pair(x_n, y_n)));
					min_cost[x_n][y_n] = min_cost[x_f][y_f] + wall_none;
					Heap.insert(make_pair(min_cost[x_n][y_n], make_pair(x_n, y_n)));
				}
			}
		}
	}
	return min_cost[x_d][y_d] == INT_MAX ? -1 : min_cost[x_d][y_d];
}

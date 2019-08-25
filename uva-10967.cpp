//uva 10967
//The Great Escape

#include <iostream>
#include <climits>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

int get_dir(char dir)
{
	if(dir == 'N')
		return 0;
	else if(dir == 'W')
		return 1;
	else if(dir == 'S')
		return 2;
	else
		return 3;
}

int find_time(char dir, char next_dir)
{
	int curr_dir = get_dir(dir);
	return min(abs(curr_dir - next_dir), 4 - abs(curr_dir - next_dir));
}

int Dijkstra(vector <string> & maze, map <pair <int, int>, int> & doors)
{
	int m = maze.size();
	int n = maze[0].size();
	int x_next[] = {-1, 0, 1, 0};//north, west, south, east
	int y_next[] = {0, -1, 0, 1};

	vector < vector <int> > min_time(m, vector <int> (n, INT_MAX));
	set < pair <int, pair <int, int> > > Heap;

	min_time[m - 1][0] = 0;
	Heap.insert(make_pair(0, make_pair(m - 1, 0)));

	while(!Heap.empty()){
		int front_time = Heap.begin()->first;
		pair <int, int> front = Heap.begin()->second;
		Heap.erase(Heap.begin());

		if(front == make_pair(0, n - 1))
			return min_time[0][n - 1];

		for(int i = 0; i < 4; ++i){
			int x_n = front.first + x_next[i];
			int y_n = front.second + y_next[i];

			if(x_n >= 0 && x_n < m && y_n >= 0 && y_n < n && maze[x_n][y_n] != '#'){
				if(maze[x_n][y_n] != '.' && get_dir(maze[x_n][y_n]) != ((i + 2) % 4))
					continue;
				int new_time = front_time + 1;
				if(maze[front.first][front.second] != '.')
					new_time += find_time(maze[front.first][front.second], i) * doors[make_pair(front.first, front.second)];

				if(new_time < min_time[x_n][y_n]){
					Heap.erase(make_pair(min_time[x_n][y_n], make_pair(x_n, y_n)));
					min_time[x_n][y_n] = new_time;
					Heap.insert(make_pair(min_time[x_n][y_n], make_pair(x_n, y_n)));
				}
			}
		}
	}
	return -1;
}

int main(void)
{
	int T = 0;
	cin >> T;
	while(T--){
		int m, n;
		cin >> m >> n;

		vector <string> maze(m);
		map <pair <int, int>, int> doors;
		for(int i = 0; i < m; ++i){
			string tmp;
			cin >> tmp;
			maze[i] = tmp;
			for(int j = 0; j < n; ++j)
				if(maze[i][j] == 'N' || maze[i][j] == 'W' || maze[i][j] == 'S' || maze[i][j] == 'E')
					doors[make_pair(i, j)] = 0;
		}

		for(auto & a : doors)
			cin >> a.second;
		
		int result = Dijkstra(maze, doors);
		if(result == -1)
			cout << "Poor Kianoosh" << endl;
		else
			cout << result << endl;
	}
	return 0;
}

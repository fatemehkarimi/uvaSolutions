//uva 784
//Maze Exploration

#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

void BFS(vector <string> & maze, pair <int, int> start);

int main(void)
{
	int T = 0;
	cin >> T;
	getchar();
	while (T--) {
		vector <string> maze;

		pair <int, int> start = make_pair(-1, string::npos);
		string terminator;

		while (true) {
			string tmp;
			getline(cin, tmp);

			if (tmp[0] == '_'){
				terminator = tmp;
				break;
			}

			if (start.second == string::npos){
				start.second = tmp.find('*');
				++start.first;
			}

			maze.push_back(tmp);
		}

		BFS(maze, start);

		for (auto a : maze)
			cout << a << endl;

		cout << terminator << endl;

	}

	return 0;
}


void BFS(vector <string> & maze, pair <int, int> start)
{
	queue < pair <int, int> > Queue;
	Queue.push(start);
	maze[start.first][start.second] = '#';

	while (!Queue.empty()){
		pair <int, int> front = Queue.front();
		Queue.pop();

		int x = front.first;
		int y = front.second;

		if (x - 1 >= 0 && y < maze[x - 1].size() && maze[x - 1][y] == ' '){
			maze[x - 1][y] = '#';
			Queue.push(make_pair(x - 1, y));
		}

		if (x + 1 < maze.size() && y < maze[x + 1].size() && maze[x + 1][y] == ' '){
			maze[x + 1][y] = '#';
			Queue.push(make_pair(x + 1, y));
		}

		if (y + 1 < maze[x].size() && maze[x][y + 1] == ' '){
			maze[x][y + 1] = '#';
			Queue.push(make_pair(x, y + 1));
		}

		if (y - 1 >= 0 && maze[x][y - 1] == ' '){
			maze[x][y - 1] = '#';
			Queue.push(make_pair(x, y - 1));
		}
	}

	return;
}

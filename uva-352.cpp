//uva 352
//The Seasonal War

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void BFS(vector < vector <char> > & map, vector < vector <bool> > & visited, pair <int, int> start);

int main(void)
{
	int n = 0;
	int tcounter = 0;
	while (cin >> n) {
		++tcounter;

		vector < vector <char> > map(n, vector <char> (n));

		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				cin >> map[i][j];


		vector < vector <bool> > visited(n, vector <bool> (n, false));

		int eagle = 0;

		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if (map[i][j] == '1' && !visited[i][j]){
					BFS(map, visited, make_pair(i, j));
					++eagle;
				}

		cout << "Image number " << tcounter << " contains " << eagle << " war eagles." << endl;
	}
	return 0;
}

void BFS(vector < vector <char> > & map, vector < vector <bool> > & visited, pair <int, int> start)
{
	queue < pair <int, int> > Queue;
	Queue.push(start);

	int n = map.size();

	visited[start.first][start.second] = 1;

	int ini [] = {-1, -1, -1, 0, 0, 1, 1, 1};
	int inj [] = {-1, 0, 1, -1, 1, -1, 0, 1};

	while (!Queue.empty()){
		pair <int, int> front = Queue.front();
		Queue.pop();

		for (int i = 0; i < 8; ++i){
			int x = front.first + ini[i];
			int y = front.second + inj[i];

			if (x >= 0 && y >= 0 && x < n && y < n && map[x][y] == '1' && !visited[x][y]){
				visited[x][y] = 1;
				Queue.push(make_pair(x, y));
			}
		}
	}

	return;
}

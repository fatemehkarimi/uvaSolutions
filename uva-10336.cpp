//uva 10336
//Rank the Languages

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;

void BFS(vector <string> & Map, vector < vector <bool> > & visited, pair <int, int> start);

int main(void)
{
	int T = 0;
	cin >> T;
	int tcounter = 0;
	while (T--) {
		++tcounter;

		int h, w;
		cin >> h >> w;

		vector <string> Map(h);
		for (int i = 0; i < h; ++i)
			cin >> Map[i];

		vector < vector <bool> > visited(h, vector <bool> (w, false));
		map <char, int> result;

		for (int i = 0; i < h; ++i)
			for (int j = 0; j < w; ++j)
				if (!visited[i][j]){
					BFS(Map, visited, make_pair(i, j));
					result[Map[i][j]]++;
				}

		set < pair <int, char> > sorted_result;

		cout << "World #" << tcounter << endl;
		for (auto a : result)
			sorted_result.insert(make_pair(-a.second, a.first));


		for (auto a : sorted_result)
			cout << a.second << ": " << -a.first << endl;

	}

	return 0;
}


void BFS(vector <string> & Map, vector < vector <bool> > & visited, pair <int, int> start)
{
	queue < pair <int, int> > Queue;
	Queue.push(start);

	int h = Map.size();
	int w = Map[0].size();
	char c = Map[start.first][start.second];

	visited[start.first][start.second] = 1;

	int ini [] = {-1, 0, 0, 1};
	int inj [] = {0, -1, 1, 0};

	while (!Queue.empty()) {
		pair <int, int> front = Queue.front();
		Queue.pop();


		for (int i = 0; i < 4; ++i){
			int x = front.first + ini[i];
			int y = front.second + inj[i];

			if (x >= 0 && x < h && y >= 0 && y < w && !visited[x][y] && Map[x][y] == c){
				Queue.push(make_pair(x, y));
				visited[x][y] = 1;
			}
		}

	}

	return;
}

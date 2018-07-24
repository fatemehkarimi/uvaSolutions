//uva 469
//Wetlands of Florida

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <queue>

using namespace std;

int BFS(vector < string > & map, pair <int, int> start);

int main(void)
{
	int T = 0;
	cin >> T;

	getchar();
	getchar();
	while (T--) {

		vector <string> map;
		string input;

		while (true){ //reading map
			getline(cin, input);
			if (input[0] == 'L' || input[0] == 'W')
				map.push_back(input);
			else
				break;
		}

		while (true){
			stringstream stream(input);
			int x, y;
			stream >> x;
			stream >> y;

			--x;
			--y;

			int result = BFS(map, make_pair(x, y));

			cout << result << endl;


			getline(cin, input);
			if (input == "")
				break;
		}

		if (T != 0)
			cout << endl;
	}

	return 0;
}

int BFS(vector < string > & map, pair <int, int> start)
{
	int n = map.size();
	int m = map[0].size();
	int area = 0;

	vector < vector <bool> > visited(n, vector <bool> (m, false));

	queue < pair <int, int> > Queue;
	Queue.push(start);
	visited[start.first][start.second] = 1;

	int ini [] = {-1, -1, -1, 0, 0, 1, 1, 1};
	int inj [] = {-1, 0, 1, -1, 1, -1, 0, 1};

	while (!Queue.empty()) {
		pair <int, int> front = Queue.front();
		Queue.pop();

		++area;

		for (int i = 0; i < 8; ++i){
			int x = front.first + ini[i];
			int y = front.second + inj[i];

			if (x >= 0 && y >= 0 && x < n && y < m && map[x][y] == 'W' && !visited[x][y]){
				Queue.push(make_pair(x, y));
				visited[x][y] = 1;
			}
		}


	}


	return area;
}

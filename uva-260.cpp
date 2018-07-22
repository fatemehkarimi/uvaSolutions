//uva 260
//Il Gioco dell’X

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool blackWin (vector < vector <char> > & Graph);

int main(void)
{
	int n = 0;
	int tcounter = 0;
	while (1){
		cin >> n;

		if (n == 0)
			break;

		++tcounter;

		vector < vector <char> > arr(n, vector <char> (n));

		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				cin >> arr[i][j];

		bool black = blackWin(arr);

		cout << tcounter;
		if (black)
			cout << " B" << endl;
		else
			cout << " W" << endl;

	}
	return 0;
}

bool blackWin (vector < vector <char> > & Graph)
{
	int n = Graph.size();
	vector < vector <bool> > visited(n, vector <bool> (n, false));

	queue < pair<int, int> > Queue;

	for (int i = 0; i < n; ++i)
		if (Graph[0][i] == 'b'){
			Queue.push(make_pair(0, i));
			visited[0][i] = 1;
		}

	int ni [6] = {-1, -1, 0, 0, 1, 1};
	int nj[6] = {-1, 0, -1, 1, 0, 1};

	while (!Queue.empty()){
		pair <int, int> front = Queue.front();
		Queue.pop();
		visited[front.first][front.second] = 1;

		if (front.first == n - 1)
			return true;

		for (int i = 0; i < 6; ++i){
			int x = front.first + ni[i];
			int y = front.second + nj[i];

			if (x >= 0 && x < n && y >= 0 && y < n && Graph[x][y] == 'b' && !visited[x][y]){
				Queue.push(make_pair(x, y));
				visited[x][y] = true;
			}
		}
	}

	return false;
}

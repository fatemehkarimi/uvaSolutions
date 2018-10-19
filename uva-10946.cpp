//uva 10946
//You want what filled?

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set>

using namespace std;

int BFS(vector <string> & arr, int x, int y, char c);

int main(void)
{
	int m, n;
	int tcounter = 0;

	while (true){
		cin >> m >> n;

		if (!m && !n)
			break;

		++tcounter;

		vector <string> arr(m);
		for (int i = 0; i < m; ++i)
			cin >> arr[i];

		multiset <pair<int, char> > result;

		for (int i = 0; i < m; ++i)
			for (int j = 0; j < n; ++j)
				if (arr[i][j] != '.'){
					char c = arr[i][j];
					int tmp = BFS(arr, i, j, c);

					result.insert(make_pair(-tmp, c));
				}

		cout << "Problem " << tcounter << ':' << endl;
		for (auto a : result)
			cout << a.second << " " << -a.first << endl;

	}
	return 0;
}

int BFS(vector <string> & arr, int x, int y, char c)
{
	int count = 1;
	arr[x][y] = '.';

	int m = arr.size();
	int n = arr[0].size();

	queue <pair <int, int> > Queue;
	Queue.push(make_pair(x, y));

	while (!Queue.empty()){
		pair <int, int> front = Queue.front();
		Queue.pop();

		int xs[] = {-1, 0, 0, 1};
		int ys[] = {0, -1, 1, 0};

		for (int i = 0; i < 4; ++i){
			int nx = front.first + xs[i];
			int ny = front.second + ys[i];

			if (nx >= 0 && nx < m && ny >= 0 && ny < n && arr[nx][ny] == c){
				++count;
				arr[nx][ny] = '.';
				Queue.push(make_pair(nx, ny));
			}
		}
	}

	return count;
}

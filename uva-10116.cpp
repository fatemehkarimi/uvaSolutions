//uva 10116
//Robot Motion

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void)
{
	int n, m, start;
	while (true) {
		cin >> m >> n >> start;

		if (n == 0 && m == 0 && start == 0)
			break;

		vector <string> arr(m);

		for (int i = 0; i < m; ++i)
			cin >> arr[i];

		pair <int, int> current;
		current.first = 0;
		current.second = start - 1;

		int steps = 0;
		bool infiniteLoop = 0;

		vector < vector <bool> > visited(m, vector <bool> (n, false));

		while (current.first >= 0 && current.second >= 0 && current.first < m && current.second < n) {
			int x = current.first;
			int y = current.second;

			if (visited[x][y]){
				infiniteLoop = 1;
				break;
			}

			if (arr[x][y] == 'N')
				current.first -= 1;
			else if (arr[x][y] == 'S')
				current.first += 1;
			else if (arr[x][y] == 'W')
				current.second -= 1;
			else if (arr[x][y] == 'E')
				current.second += 1;

			visited[x][y] = 1;

			++steps;
		}

		if (infiniteLoop){
			int repeatLength = 0;
			pair <int, int> tmp = current;

			do {
				int x = tmp.first;
				int y = tmp.second;

			if (arr[x][y] == 'N')
				tmp.first -= 1;
			else if (arr[x][y] == 'S')
				tmp.first += 1;
			else if (arr[x][y] == 'W')
				tmp.second -= 1;
			else if (arr[x][y] == 'E')
				tmp.second += 1;

			++repeatLength;

			}while(tmp.first != current.first || tmp.second != current.second);

			cout << steps - repeatLength << " step(s) before a loop of " << repeatLength << " step(s)" << endl;
		}
		else
			cout << steps << " step(s) to exit" << endl;

	}
	return 0;
}

//uva 10305
//Ordering Tasks

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void)
{
	int m = 0, n = 0;
	while (1) {
		cin >> n >> m;

		if (n == 0 && m == 0)
			break;

		vector < vector <int> > Graph(n);
		vector <int> count(n, 0);

		for (int i = 0; i < m; ++i){
			int t1, t2;
			cin >> t1 >> t2;

			--t1;
			--t2;

			Graph[t1].push_back(t2);
			++count[t2];
		}


		queue <int> Queue;

		for (int i = 0; i < n; ++i)
			if (!count[i])
				Queue.push(i);


		vector <int> result;
		vector <bool> visited(n, false);

		while (!Queue.empty()) {
			int front = Queue.front();
			Queue.pop();

			visited[front] = 1;
			result.push_back(front);

			for (auto a : Graph[front])
				if (!visited[a]){
					--count[a];
					if (count[a] == 0)
						Queue.push(a);
				}
		}


		cout << result[0] + 1;
		for (int i = 1; i < n; ++i)
			cout << ' ' << result[i] + 1;
		cout << endl;
	}
	return 0;
}

//uva 12376
//As Long as I Learn, I Live

#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int T;
	cin >> T;
	for (int tcounter = 1; tcounter <= T; ++tcounter) {
		int n, m;
		cin >> n >> m;

		vector <int> values(n);
		for (int i = 0; i < n; ++i)
			cin >> values[i];

		vector < vector <int> > dGraph(n);

		for (int i = 0; i < m; ++i){
			int t1, t2;
			cin >> t1 >> t2;

			dGraph[t1].push_back(t2);
		}

		int units = 0;
		int curr = 0;

		while (true){
			int max = 0;
			int next = -1;
			for (auto a : dGraph[curr])
				if (max < values[a]){
					max = values[a];
					next = a;
				}

			if (next == -1)
				break;

			units += values[next];
			curr = next;
		}

		cout << "Case " << tcounter << ": " << units << ' ' << curr << endl;
	}

	return 0;
}

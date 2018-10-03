//uva 318
//Domino Effect

#include <iostream>
#include <iomanip>
#include <climits>
#include <vector>
#include <set>
#include <map>

using namespace std;

int main(void)
{
	int n, m;
	int tcounter = 0;

	while (true){
		cin >> n >> m;

		if (n == 0 && m == 0)
			break;
		++tcounter;

		vector < map <int, double> > graph(n);
		for (int i = 0; i < m; ++i){
			int u, v, t;
			cin >> u >> v >> t;

			--u;
			--v;

			graph[u].insert(make_pair(v, t));
			graph[v].insert(make_pair(u, t));
		}

		map < pair<int, int>, double> active_edge;//first parameter=edge, second=time

		double time = 0;
		int last_one = 0;
		bool is_between = 0;
		int back = 0, forth = 0;

		for (auto a : graph[0])
			active_edge.insert(make_pair(make_pair(0, a.first), a.second));

		while (!active_edge.empty()){
			double min_time = active_edge.begin()->second;

			for (auto a : active_edge){
				int x = a.first.first;
				int y = a.first.second;

				auto f1 = active_edge.find(make_pair(y, x));
				if (f1 != active_edge.end())
					min_time = min(min_time, a.second / 2);
				else
					min_time = min(min_time, a.second);
			}

			for (auto & a : active_edge){
				int x = a.first.first;
				int y = a.first.second;
				a.second -= min_time;

				auto f1 = active_edge.find(make_pair(y, x));
				if (f1 != active_edge.end())
					f1->second -= min_time;
			}

			set < pair <int, int> > removed_edge;
			for (auto & a : active_edge)
				if (a.second == 0){
					int x = a.first.first;
					int y = a.first.second;

					graph[x].erase(y);
					graph[y].erase(x);
					active_edge.erase(make_pair(x, y));
					removed_edge.insert(make_pair(x, y));
				}

			for (auto a : removed_edge){
				int x = a.first;
				int y = a.second;

				for (auto b : graph[y]){
					auto f1 = active_edge.find(make_pair(b.first, y));

					if (f1 != active_edge.end())
						active_edge.insert(make_pair(make_pair(y, b.first), f1->second));
					else
						active_edge.insert(make_pair(make_pair(y, b.first), b.second));
				}
			}

			if (active_edge.empty()){
				auto last = removed_edge.begin();
				int x = last->first;
				int y = last->second;

				auto f1 = removed_edge.find(make_pair(y, x));
				if (f1 != removed_edge.end()){
					is_between = 1;
					back = x;
					forth = y;
				}
				else
					last_one = y;
			}

			time += min_time;
		}

		cout << "System #" << tcounter << endl;
		cout << "The last domino falls after " << fixed << setprecision(1) << time << " seconds,";

		if (!is_between)
 			cout << " at key domino " << last_one + 1 << "." << endl;
		else
			cout << " between key dominoes " << min(back,forth) + 1 << " and " << max(back, forth) + 1 << "." << endl;
		cout << endl;
	}
	return 0;
}

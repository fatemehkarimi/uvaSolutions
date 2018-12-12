//uva 11228
//Transportation system

#include <iostream>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

int parent(vector <int> & ufds, int a);
void Union(vector <int> & ufds, int a, int b);
double distance(pair <int, int> x, pair <int, int> y);

int main(void)
{
	int T = 0;
	cin >> T;
	for(int tcounter = 1; tcounter <= T; ++tcounter){
		int n, r;
		cin >> n >> r;

		vector < pair <int, int> > cities(n);

		for(int i = 0; i < n; ++i){
			int x, y;
			cin >> x >> y;

			cities[i] = make_pair(x, y);
		}

		set < pair <double, pair <int, int> > > KruskalSet;
		vector <int> states(n, -1);

		for(int i = 0; i < n; ++i)
			for(int j = i + 1; j < n; ++j){
				double dis = distance(cities[i], cities[j]);

				KruskalSet.insert(make_pair(dis, make_pair(i, j)));

				if(dis <= (double)r)
					Union(states, i, j);
			}

		int n_state = 0;
		for(auto state : states)
			if(state == -1)
				++n_state;

		double roads = 0;
		double railroads = 0;

		vector <int> ufds(n, -1);

		while(!KruskalSet.empty()){
			double dis = KruskalSet.begin()->first;
			int i = KruskalSet.begin()->second.first;
			int j = KruskalSet.begin()->second.second;

			KruskalSet.erase(KruskalSet.begin());

			if(parent(ufds, i) != parent(ufds, j)){
				Union(ufds, i, j);

				if(parent(states, i) == parent(states, j))
					roads += dis;
				else
					railroads += dis;
			}
		}

		cout << "Case #" << tcounter << ": " << n_state << ' ' << round(roads) << ' ' << round(railroads) << endl;

	}

	return 0;
}

double distance(pair <int, int> x, pair <int, int> y)
{
	int tmp = (x.first - y.first) * (x.first - y.first) + (x.second - y.second) * (x.second - y.second);
	return sqrt(tmp);
}

void Union(vector <int> & ufds, int a, int b)
{
	int p1 = parent(ufds, a);
	int p2 = parent(ufds, b);

	if(p1 == p2)
		return;

	ufds[p2] = p1;

	return;
}

int parent(vector <int> & ufds, int a)
{
	int x = a;
	while(ufds[x] != -1)
		x = ufds[x];

	while(ufds[a] != -1){
		int tmp = ufds[a];
		ufds[a] = x;
		a = tmp;
	}

	return x;
}

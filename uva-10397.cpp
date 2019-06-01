//uva 10397
//Connect the Campus

#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

int findParent(vector <int> & ufds, int x);
void _union(vector <int> & ufds, int x, int y);
double distance(int x1, int y1, int x2, int y2);
double kruskal(set <pair <double, pair <int, int> > > & Edges, int n);

int main(void)
{
	int n;
	while(cin >> n){
		vector < pair <int, int> > points(n);
		for(int i = 0; i < n; ++i)
			cin >> points[i].first >> points[i].second;

		vector < vector <bool> > available_cables(n, vector <bool>(n, false));
		int m;
		cin >> m;
		for(int i = 0; i < m; ++i){
			int p1, p2;
			cin >> p1 >> p2;
			--p1, --p2;

			available_cables[p1][p2] = available_cables[p2][p1] = true;
		}

		set < pair <double, pair <int, int> > > Edges;
		for(int i = 0; i < n; ++i)
			for(int j = i + 1; j < n; ++j)
				if(!available_cables[i][j])
					Edges.insert(make_pair(distance(points[i].first, points[i].second, points[j].first, points[j].second), make_pair(i, j)));
				else
					Edges.insert(make_pair(0, make_pair(i, j)));

		double minCost = kruskal(Edges, n);
		cout << setprecision(2) << fixed << minCost << endl;
	}
	return 0;
}

double kruskal(set <pair <double, pair <int, int> > > & Edges, int n)
{
	vector <int> ufds(n, -1);
	double minCost = 0;
	while(!Edges.empty()){
		double cost = Edges.begin()->first;
		int u = Edges.begin()->second.first;
		int v = Edges.begin()->second.second;

		Edges.erase(Edges.begin());

		if(findParent(ufds, u) != findParent(ufds, v)){
			_union(ufds, u, v);
			minCost += cost;
		}
	}
	return minCost;
}
double distance(int x1, int y1, int x2, int y2)
{
	int tmp = (x1 - x2) * (x1 - x2);
	tmp += (y1 - y2) * (y1 - y2);
	return sqrt(tmp);
}

int findParent(vector <int> & ufds, int x)
{
	int root = x;
	while(ufds[root] != -1)
		root = ufds[root];

	while(ufds[x] != -1){
		int next = ufds[x];
		ufds[x] = root;
		x = next;
	}

	return root;
}

void _union(vector <int> & ufds, int x, int y)
{
	int p1 = findParent(ufds, x);
	int p2 = findParent(ufds, y);
	ufds[p2] = p1;
	return;
}

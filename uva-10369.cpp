//uva 10369
//Arctic Network

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

double distance(int x1, int x2, int y1, int y2);
void _union(vector <int> & ufds, int x, int y);
int findParent(vector <int> & ufds, int x);
void kruskal(int n_node, set < pair <double, pair <int, int> > > & Edges, vector <double> & result);

int main(void)
{
	int T = 0;
	cin >> T;
	while(T--){
		int channel, n;
		cin >> channel >> n;
		vector < pair <int, int> > points(n);
		for(int i = 0; i < n; ++i)
			cin >> points[i].first >> points[i].second;

		set < pair <double, pair <int, int> > > Edges;
		for(int i = 0; i < n; ++i)
			for(int j = i + 1; j < n; ++j){
					double dis = distance(points[i].first, points[i].second, points[j].first, points[j].second);
					Edges.insert(make_pair(dis, make_pair(i, j)));
				}

		vector < double > minEdge;
		kruskal(n, Edges, minEdge);
		sort(minEdge.begin(), minEdge.end(), greater <double>());
		if(channel - 1 >= (int)minEdge.size())
			cout << setprecision(2) << fixed << 0.00 << endl;
		else
			cout << setprecision(2) << fixed << minEdge[channel - 1] << endl;
	}
	return 0;
}

void kruskal(int n_node, set < pair <double, pair <int, int> > > & Edges, vector <double> & result)
{
	vector <int> ufds(n_node, -1);
	while(!Edges.empty()){
		pair <double, pair <int, int> > top = *Edges.begin();
		Edges.erase(Edges.begin());
		double cost = top.first;
		int u = top.second.first;
		int v = top.second.second;

		if(findParent(ufds, u) != findParent(ufds, v)){
			_union(ufds, u, v);
			result.push_back(cost);
		}
	}
	return;
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

double distance(int x1, int y1, int x2, int y2)
{
	int tmp = (x1 - x2) * (x1 - x2);
	tmp += (y1 - y2) * (y1 - y2);
	return sqrt(tmp);
}

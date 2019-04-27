//uva 12186
//Another Crisis

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int min_worker(vector <vector <int> > & Graph, int T, int root);

int main(void)
{
	int n, T;
	while(true){
		cin >> n >> T;

		if(n == 0 && T == 0)
			break;

		vector <vector <int> > Graph(n + 1);

		for(int i = 1; i <= n; ++i){
			int boss;
			cin >> boss;
			Graph[boss].push_back(i);
		}

		int min_leaves = min_worker(Graph, T, 0);
		cout << min_leaves << endl;
	}
	return 0;
}

int min_worker(vector <vector <int> > & Graph, int T, int root)
{
	vector <int> min_leaves;
	for(auto a : Graph[root])
		min_leaves.push_back(min_worker(Graph, T, a));

	if(min_leaves.empty())//when empty, then node itself is a leaf
		return 1;

	int count = ceil((double)Graph[root].size() * ((double)T / 100.0));

	sort(min_leaves.begin(), min_leaves.end());
	int min_num_leaves = 0;
	for(int i = 0; i < count; ++i)
		min_num_leaves += min_leaves[i];

	return min_num_leaves;
}

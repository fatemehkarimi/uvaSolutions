//uva 341
//Non-Stop Travel

#include <iostream>
#include <climits>
#include <vector>
#include <stack>

using namespace std;

int main(void)
{
	int n = 0;
	int tcounter = 0;

	while(true){
		cin >> n;

		if(n == 0)
			break;
		++tcounter;

		vector < vector <int> > Graph(n, vector <int> (n, INT_MAX));

		for(int i = 0; i < n; ++i){
			int c;
			cin >> c;

			for(int j = 0; j < c; ++j){
				int tmp, d;
				cin >> tmp >> d;
				--tmp;

				Graph[i][tmp] = min(Graph[i][tmp], d);
			}
		}

		int source, destination;
		cin >> source >> destination;
		--source;
		--destination;


		vector < vector < vector <int> > > backtrack(n, vector < vector <int> > (n, vector <int> (n, -1)));

		for(int k = 0; k < n; ++k)
			for(int i = 0; i < n; ++i)
				for(int j = 0; j < n; ++j){
					if(k > 0)
						backtrack[k][i][j] = backtrack[k - 1][i][j];

					if(Graph[i][k] != INT_MAX && Graph[k][j] != INT_MAX){
						if(Graph[i][j] > Graph[i][k] + Graph[k][j]){
							Graph[i][j] = Graph[i][k] + Graph[k][j];
							backtrack[k][i][j] = k;
						}
					}
				}

		vector <int> path;
		stack < pair<int, int> > Stack;
		Stack.push(make_pair(source, destination));
		stack <int> i_value;
		i_value.push(n - 1);

		while(!Stack.empty()){
			int left = Stack.top().first;
			int right = Stack.top().second;
			int i = i_value.top();
			i_value.pop();
			Stack.pop();

			if(backtrack[i][left][right] != -1){
				Stack.push(make_pair(backtrack[i][left][right], right));
				Stack.push(make_pair(left, backtrack[i][left][right]));

				i_value.push(i - 1);
				i_value.push(i - 1);
			}
			else
				path.push_back(left);
		}

		cout << "Case " << tcounter << ": Path =";
		for(auto a : path)
			cout << ' ' << a + 1;
		cout << ' ' << destination + 1;
		cout << "; " << Graph[source][destination] << " second delay" << endl;

	}
	return 0;
}

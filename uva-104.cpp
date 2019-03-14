//uva 104
//Arbitrage

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(void)
{
	int n;
	while(cin >> n){
		vector < vector <double> > arbitrage(n, vector <double> (n));
		vector < vector < vector <int> > > parent(n, vector <vector <int> > (n, vector <int> (n, -1)));

		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j){
				if(i == j)
					arbitrage[i][j] = 1.0;
				else
					cin >> arbitrage[i][j];
			}

		vector < vector <double> > profit = arbitrage;
		vector <int> path;

		for(int step = 1; step < n; ++step){
			vector < vector <double> > new_profit = profit;

			for(int k = 0; k < n; ++k)
				for(int i = 0; i < n; ++i)
					for(int j = 0; j < n; ++j)
						if(new_profit[i][j] < profit[i][k] * arbitrage[k][j]){
							new_profit[i][j] = profit[i][k] * arbitrage[k][j];
							parent[step][i][j] = k;
						}

			profit = new_profit;

			for(int p = 0; p < n; ++p)
				if(profit[p][p] > 1.01){
					int right = p;
					path.push_back(p);
					
					for(int s = step; s >= 0; --s)
						if(parent[s][p][right] != -1){
							path.push_back(parent[s][p][right]);
							right = parent[s][p][right];
						}
					path.push_back(p);
					break;
				}

			if(!path.empty())
				break;
		}

		if(!path.empty()){
			cout << path.back() + 1;
			for(int i = path.size() - 2; i >= 0; --i)
				cout << ' ' << path[i] + 1;
			cout << endl;
		}
		else
			cout << "no arbitrage sequence exists" << endl;
	}
	return 0;
}

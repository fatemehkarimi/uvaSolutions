//uva 436
//Arbitrage (II)

#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main(void)
{
	int tcounter = 0;
	while(1){
		int n, m;
		cin >> n;

		if(n == 0)
			break;
		
		++tcounter;

		map <string, int> money_code;
		vector < vector <double> > Graph(n, vector <double> (n, 0));

		for(int i = 0; i < n; ++i){
			string money;
			cin >> money;
			money_code[money] = i;
			Graph[i][i] = 1;
		}

		cin >> m;

		for(int i = 0; i < m; ++i){
			string m1, m2;
			double amount;
			cin >> m1 >> amount >> m2;

			Graph[money_code[m1]][money_code[m2]] = amount;
		}

		for(int k = 0; k < n; ++k)
			for(int i = 0; i < n; ++i)
				for(int j = 0; j < n; ++j)
					if(Graph[i][k] * Graph[k][j] > Graph[i][j])
						Graph[i][j] = Graph[i][k] * Graph[k][j];

		bool arbitrage = false;
		for(int i = 0; i < n; ++i)
			if(Graph[i][i] > 1)
				arbitrage = 1;

		cout << "Case " << tcounter << ": ";
		if(arbitrage)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}

	return 0;
}

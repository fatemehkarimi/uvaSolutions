//uva 125
//Numbering Paths

#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int n;
	int tcounter = 0;
	while(cin >> n){
		vector <vector <long long int> > n_ways(30, vector <long long int> (30, 0));
		vector <vector <bool> > is_infinity(30, vector <bool> (30, 0));
		int size = 0;

		for(int i = 0; i < n; ++i){
			int u, v;
			cin >> u >> v;

			n_ways[u][v]++;
			size = max(size, max(u, v) + 1);
		}

		for(int k = 0; k < size; ++k)
			for(int i = 0; i < size; ++i)
				for(int j = 0; j < size; ++j)
					n_ways[i][j] += (n_ways[i][k] * n_ways[k][j]);

		for(int i = 0; i < size; ++i)
			if(n_ways[i][i] != 0)
				is_infinity[i][i] = 1;

		for(int k = 0; k < size; ++k)
			for(int i = 0; i < size; ++i)
				for(int j = 0; j < size; ++j)
					if(is_infinity[k][k] && n_ways[i][k] * n_ways[k][j] != 0)
						is_infinity[i][j] = 1;

		cout << "matrix for city "<< tcounter++ << endl;

		for(int i = 0; i < size; ++i)
			for(int j = 0; j < size; ++j)
				if(is_infinity[i][j])
					n_ways[i][j] = -1;

		for(int i = 0; i < size; ++i){
			cout << n_ways[i][0];
			for(int j = 1; j < size; ++j)
				cout << ' ' << n_ways[i][j];
			cout << endl;
		}
	}
	return 0;
}

//uva 423
//MPI Maelstrom

#include <iostream>
#include <climits>
#include <vector>
#include <string>

using namespace std;

int convertToNum(string a);

int main(void)
{
	int n = 0;
	while(cin >> n){
		vector <vector <int> > Graph(n, vector <int> (n, INT_MAX));

		for(int i = 0; i < n; ++i)
			for(int j = 0; j < i; ++j){
				string t;
				cin >> t;

				if(t == "x")
					continue;

				int tt = convertToNum(t);

				Graph[i][j] = tt;
				Graph[j][i] = tt;
			}

		for(int i = 0; i < n; ++i)
			Graph[i][i] = 0;

		for(int k = 0; k < n; ++k)
			for(int i = 0; i < n; ++i)
				for(int j = 0; j < n; ++j)
					if(Graph[i][k] != INT_MAX && Graph[k][j] != INT_MAX)
						Graph[i][j] = min(Graph[i][j], Graph[i][k] + Graph[k][j]);


		int max_time = INT_MIN;
		for(auto a : Graph[0])
			max_time = max(max_time, a);

		cout << max_time << endl;
	}
	return 0;
}

int convertToNum(string a)
{
	int result = 0;
	for(int i = 0; i < a.size(); ++i){
		result *= 10;
		result += (a[i] - '0');
	}

	return result;
}

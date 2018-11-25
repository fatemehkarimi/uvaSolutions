//uva 10278
//Fire Station

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <climits>

using namespace std;

int main(void)
{
	int T = 0;
	cin >> T;
	getchar();
	getchar();

	while(T--){
		int n_f, n;
		cin >> n_f >> n;

		vector <bool> fireStations(n, false);
		vector < vector <int> > Graph(n, vector <int> (n, INT_MAX));

		for(int i = 0; i < n; ++i)
			Graph[i][i] = 0;

		for(int i = 0; i < n_f; ++i){
			int t;
			cin >> t;
			--t;

			fireStations[t] = 1;
		}

		getchar();

		while(true){
			string str;
			getline(std::cin, str);

			if(str == "")
				break;

			stringstream s(str);
			int n1, n2, d;
			s >> n1 >> n2 >> d;

			--n1, --n2;

			Graph[n1][n2] = d;
			Graph[n2][n1] = d;
		}

		//floyd-warshall
		for(int k = 0; k < n; ++k)
			for(int i = 0; i < n; ++i)
				for(int j = 0; j < n; ++j)
					if(Graph[i][k] != INT_MAX && Graph[k][j] != INT_MAX)
						if(Graph[i][j] > Graph[i][k] + Graph[k][j])
							Graph[i][j] = Graph[i][k] + Graph[k][j];


		vector <int> minDisToF(n, INT_MAX);
		int bestMaxDis = INT_MIN;

		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j)
				if(fireStations[j])
					minDisToF[i] = min(minDisToF[i], Graph[i][j]);

				bestMaxDis = max(bestMaxDis, minDisToF[i]);
		}

		int bestIntersection = 0;

		for(int j = 0; j < n; ++j)
			if(!fireStations[j]){
				int tmpMaxDis = INT_MIN;

				for(int i = 0; i < n; ++i)
					tmpMaxDis = max(tmpMaxDis, min(minDisToF[i], Graph[i][j]));

				if(tmpMaxDis < bestMaxDis){
					bestMaxDis = tmpMaxDis;
					bestIntersection = j;
				}
			}

		cout << bestIntersection + 1 << endl;
		if(T) cout << endl;
	}

	return 0;
}

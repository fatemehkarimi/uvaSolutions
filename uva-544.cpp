//uva 544
//Heavy Cargo

#include <iostream>
#include <climits>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main(void)
{
	int tcounter = 0;
	while(true){
		int n, m;
		cin >> n >> m;

		if(n == 0 && m == 0)
			break;

		++tcounter;

		map <string, int> city_code;
		map <int, string> code_city;
		vector < vector <int> > Graph(n, vector <int> (n, -1));
		int code = 0;

		for(int i = 0; i < m; ++i){
			string c1, c2;
			int val;
			cin >> c1 >> c2 >> val;

			if(city_code.find(c1) == city_code.end()){
				city_code[c1] = code;
				code_city[code] = c1;
				++code;
			}
			if(city_code.find(c2) == city_code.end()){
				city_code[c2] = code;
				code_city[code] = c2;
				++code; 
			}

			int code1 = city_code[c1];
			int code2 = city_code[c2];
			Graph[code1][code2] = val;
			Graph[code2][code1] = val;
		}

		string source, destination;
		cin >> source >> destination;

		int s_idx = city_code[source];
		int d_idx = city_code[destination];

		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j)
				for(int k = 0; k < n; ++k)
					if(Graph[i][k] != -1 && Graph[k][j] != -1)
						Graph[i][j] = max(Graph[i][j], min(Graph[i][k], Graph[k][j]));

		cout << "Scenario #" << tcounter << endl;
		cout << Graph[s_idx][d_idx] << " tons" << endl;
		cout << endl;
	}
	return 0;
}

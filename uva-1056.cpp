//uva 1056
//Degrees of Separation

#include <iostream>
#include <climits>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

int main(void)
{
	int n, m;
	int T = 0;
	while(true){
		cin >> n >> m;

		if(n == 0 && m == 0)
			break;

		++T;

		vector < vector <int> > Graph(n, vector <int> (n, INT_MAX));
		map <string, int> name_code;

		for(int i = 0; i < n; ++i)//everyone has a relation to itself
			Graph[i][i] = true;

		for(int i = 0; i < m; ++i){
			string name1, name2;
			cin >> name1 >> name2;

			int code1, code2;

			auto f1 = name_code.find(name1);
			if(f1 == name_code.end()){
				name_code[name1] = --n;
				code1 = n;
			}
			else
				code1 = f1->second;

			auto f2 = name_code.find(name2);
			if(f2 == name_code.end()){
				name_code[name2] = --n;
				code2 = n;
			}
			else
				code2 = f2->second;

			Graph[code1][code2] = true;
			Graph[code2][code1] = true;
		}

		n = Graph.size();
		for(int k = 0; k < n; ++k)
			for(int i = 0; i < n; ++i)
				for(int j = 0; j < n; ++j)
					if(Graph[i][k] != INT_MAX && Graph[k][j] != INT_MAX)
						Graph[i][j] = min(Graph[i][j], Graph[i][k] + Graph[k][j]);

		int max_degree = INT_MIN;
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j)
				max_degree = max(max_degree, Graph[i][j]);

		cout << "Network " << T << ": ";
		if(max_degree != INT_MAX)
			cout << max_degree << endl;
		else
			cout <<  "DISCONNECTED" << endl;
		cout << endl;
	}
	return 0;
}

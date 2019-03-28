//uva 869
//Airline Comparison

#include <iostream>
#include <vector>

using namespace std;

void floyd_warshall(vector <vector <bool> > & Graph);

int main(void)
{
	int T = 0;
	cin >> T;
	while(T--){
		vector < vector <bool> > airline1(26, vector <bool> (26, false));
		vector < vector <bool> > airline2(26, vector <bool> (26, false));

		int n;
		cin >> n;

		for(int i = 0; i < n; ++i){
			char city1, city2;
			cin >> city1 >> city2;

			airline1[city1 - 'A'][city2 - 'A'] = true;
		}

		cin >> n;

		for(int i = 0; i < n; ++i){
			char city1, city2;
			cin >> city1 >> city2;

			airline2[city1 - 'A'][city2 - 'A'] = true;
		}

		floyd_warshall(airline1);
		floyd_warshall(airline2);

		bool equal = true;

		for(int i = 0; i < 26; ++i)
			for(int j = 0; j < 26; ++j)
				if(airline1[i][j] != airline2[i][j])
					equal = false;


		if(equal)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;

		if(T)
			cout << endl;
	}
	return 0;
}

void floyd_warshall(vector <vector <bool> > & Graph)
{
	int n = Graph.size();
	for(int k = 0; k < n; ++k)
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j)
				if(Graph[i][k] && Graph[k][j])
					Graph[i][j] = true;
	return;
}

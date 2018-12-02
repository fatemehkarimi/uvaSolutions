//uva 10171
//Meeting Prof. Miguel ...

#include <iostream>
#include <climits>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main(void)
{
	int n = 0;
	while(true){
		cin >> n;

		if(n == 0)
			break;

		map <char, map <char, int> > YGraph;
		map <char, map <char, int> > MGraph;

		for(char i = 'A'; i <= 'Z'; ++i)
			for(char j = 'A'; j <= 'Z'; ++j){
				YGraph[i][j] = INT_MAX;
				MGraph[i][j] = INT_MAX;
			}

		for(int i = 0; i < n; ++i){
			char state, direct, n1, n2;
			int cost;
			cin >> state >> direct >> n1 >> n2 >> cost;

			if(state == 'Y'){
				YGraph[n1][n2] = cost;

				if(direct == 'B')
					YGraph[n2][n1] = cost;
			}
			else {
				MGraph[n1][n2] = cost;

				if(direct == 'B')
					MGraph[n2][n1] = cost;
			}
		}

		char sourceY, sourceM;
		cin >> sourceY >> sourceM;

		for(char i = 'A'; i <= 'Z'; ++i){
			YGraph[i][i] = 0;
			MGraph[i][i] = 0;
		}

		for(char k = 'A'; k <= 'Z'; ++k)
			for(char i = 'A'; i <= 'Z'; ++i)
				for(char j = 'A'; j <= 'Z'; ++j){
					if(YGraph[i][k] != INT_MAX && YGraph[k][j] != INT_MAX)
						YGraph[i][j] = min(YGraph[i][j], YGraph[i][k] + YGraph[k][j]);

					if(MGraph[i][k] != INT_MAX && MGraph[k][j] != INT_MAX)
						MGraph[i][j] = min(MGraph[i][j], MGraph[i][k] + MGraph[k][j]);
				}

		int minCost = INT_MAX;
		set <char> destination;

		for(char i = 'A'; i <= 'Z'; ++i)
			if(YGraph[sourceY][i] != INT_MAX && MGraph[sourceM][i] != INT_MAX){
				if(YGraph[sourceY][i] + MGraph[sourceM][i] < minCost){
					minCost = YGraph[sourceY][i] + MGraph[sourceM][i];

					destination.clear();
					destination.insert(i);
				}
				else if(YGraph[sourceY][i] + MGraph[sourceM][i] == minCost)
					destination.insert(i);
			}


		if(destination.empty())
			cout << "You will never meet." << endl;
		else{
			cout << minCost;
			for(auto a : destination)
				cout << ' ' << a;
			cout << endl;
		}
	}
	return 0;
}


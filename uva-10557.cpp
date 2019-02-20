//uva 10557
//XYZZY

#include <iostream>
#include <climits>
#include <vector>
#include <set>

using namespace std;

int main(void)
{
	int n = 0;
	while(true){
		cin >> n;

		if(n == -1) break;

		vector <int> energy_level(n);
		vector < vector <int> > Graph(n);

		for(int i = 0; i < n; ++i){
			cin >> energy_level[i];

			int m = 0;
			cin >> m;
			for(int j = 0; j < m; ++j){
				int node;
				cin >> node;
				--node;
				Graph[i].push_back(node);
			}
		}

		vector <int> energy(n, INT_MAX);
		energy[0] = -100;

		for(int i = 0; i < n - 1; ++i)
			for(int j = 0; j < n; ++j)
				for(auto node : Graph[j])
					if(energy[j] != INT_MAX){
						energy[node] = min(energy[node], energy[j] - energy_level[node]);
						if(energy[node] >= 0)
							energy[node] = INT_MAX;
					}

		for(int i = 0; i < n - 1; ++i)
			for(int j = 0; j < n; ++j)
				for(auto node : Graph[j])
					if(energy[j] == INT_MIN || (energy[j] != INT_MAX  && energy[node] != INT_MAX && energy[j] - energy_level[node] < energy[node]))
						energy[node] = INT_MIN;


		if(energy[n - 1] < 0)
			cout << "winnable" << endl;
		else
			cout << "hopeless" << endl;
	}
	return 0;
}

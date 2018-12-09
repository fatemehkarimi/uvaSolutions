//uva 10980
//Lowest Price in Town

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <sstream>
#include <climits>
#include <vector>
#include <string>
#include <map>

using namespace std;

void readK(vector <int> & k);

int main(void)
{
	double unit_price;
	int n;
	int tcounter = 0;

	while(cin >> unit_price >> n){
		++tcounter;

		vector  <pair <int, double> > available_price;
		available_price.push_back(make_pair(1, unit_price));

		for(int i = 0; i < n; ++i){
			int count;
			double price;
			cin >> count >> price;

			available_price.push_back(make_pair(count, price));
		}

		getchar();

		vector <int> k;
		readK(k);

		int c = *max_element(k.begin(), k.end());
		c *= c;

		int r = available_price.size() + 1;
		vector <vector <double> > arr(r, vector <double> (c, INT_MAX));

		for(int i = 0; i < r; ++i)
			arr[i][0] = 0;

		for(int i = 1 ; i < r; ++i)
			for(int j = 0; j < c; ++j){
				arr[i][j] = min(arr[i][j], arr[i - 1][j]);

				int count = available_price[i - 1].first;
				double price = available_price[i - 1].second;

				if(j + count < c)
					arr[i][j + count] = min(arr[i - 1][j + count], arr[i][j] + price);
			}

		cout << "Case " << tcounter << ":" << endl;

		for(auto K : k){
			double min_price = arr[r - 1][K];
			for(int j = K; j < c; ++j)
				if(arr[r - 1][j] < min_price)
					min_price = arr[r - 1][j];

			cout << "Buy " << K << " for $" << fixed << setprecision(2) << min_price << endl;
		}

	}

	return 0;
}

void readK(vector <int> & k)
{
	string input;
	getline(cin, input);
	stringstream stream(input);

	int x;

	while(stream >> x)
		k.push_back(x);

	return;
}


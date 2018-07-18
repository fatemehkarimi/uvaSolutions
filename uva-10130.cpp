//uva 10130
//SuperSale

#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;

int max(int a, int b);

int main(void)
{
	int T = 0;
	cin >> T;

	while (T--) {
		int n = 0;
		cin >> n;

		vector < pair <int, int> > objects;
		for (int i = 0; i < n; ++i){
			int p, w;
			cin >> p >> w;

			objects.push_back(make_pair(p, w));
		}


		int people;
		cin >> people;

		vector <int> weights(people);
		for (int i = 0; i < people; ++i)
			cin >> weights[i];

		int maxWeight = *max_element(weights.begin(), weights.end());
		vector < vector <int> > arr(objects.size() + 1, vector <int> (maxWeight + 1));

		for (int j = 1; j < maxWeight + 1; ++j)
			for (int i = 1; i < objects.size() + 1; ++i)
				if (j - objects[i - 1].second >= 0){
					int price = objects[i - 1].first;
					int wei = objects[i - 1].second;

					arr[i][j] = max(arr[i - 1][j], arr[i - 1][j - wei] + price);
				}
				else
					arr[i][j] = arr[i - 1][j];




		int totalValue = 0;

		for (auto a : weights)
			totalValue += arr[objects.size()][a];


		cout << totalValue << endl;

	}
	
	return 0;
}

int max(int a, int b)
{
	return a > b ? a : b;
}

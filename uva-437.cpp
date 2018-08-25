//uva 437
//The Tower of Babylon

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int maxHeight(vector < pair < pair <int, int>, int> > & bricks);

bool compare(pair < pair<int, int>, int> a, pair < pair<int, int>, int> b)
{
	if (a.first.first * a.first.second < b.first.first * b.first.second)
		return true;
	return false;
}

int main(void)
{
	int n = 0;
	int tcounter = 0;
	while (true) {
		cin >> n;

		if (n == 0)
			break;
		++tcounter;

		vector < pair < pair <int, int> , int> > bricks;

		for (int i = 0; i < n; ++i) {
			int x, y, z;
			cin >> x >> y >> z;

			vector <int> tmp;
			tmp.push_back(x);
			tmp.push_back(y);
			tmp.push_back(z);

			sort(tmp.begin(), tmp.end());

			bricks.push_back(make_pair(make_pair(tmp[0], tmp[1]), tmp[2]));
			bricks.push_back(make_pair(make_pair(tmp[0], tmp[2]), tmp[1]));
			bricks.push_back(make_pair(make_pair(tmp[1], tmp[2]), tmp[0]));
		}

		auto ip = std::unique(bricks.begin(), bricks.end());
		bricks.resize(std::distance(bricks.begin(), ip));

		sort(bricks.begin(), bricks.end(), compare);

		cout << "Case " << tcounter << ": maximum height = " << maxHeight(bricks) << endl;

	}
	return 0;
}

int maxHeight(vector < pair < pair <int, int>, int> > & bricks)
{
	vector <int> heights(bricks.size(), 0);

	for (int i = 0; i < bricks.size(); ++i){
		int x = bricks[i].first.first;
		int y = bricks[i].first.second;
		int z = bricks[i].second;

		heights[i] = z;

		for (int j = 0; j < i; ++j){
			int x1 = bricks[j].first.first;
			int y1 = bricks[j].first.second;
			int z1 = bricks[j].second;

			if ((x1 < x && y1 < y) || (x1 < y && y1 < x))
				heights[i] = max(heights[i], heights[j] + z);
		}
	}

	return *max_element(heights.begin(), heights.end());
}

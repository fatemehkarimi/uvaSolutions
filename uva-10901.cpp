//uva 10901
//Ferry Loading III

#include <iostream>
#include <climits>
#include <string>
#include <queue>
#include <map>

using namespace std;

int main(void)
{
	int T = 0;
	cin >> T;

	while (T--) {
		int n, t, m;
		cin >> n >> t >> m;

		queue < pair <int, int> > left;
		queue < pair <int, int> > right;

		for (int i = 0; i < m; ++i){
			int tmp;
			string pos;

			cin >> tmp >> pos;

			if (pos == "left")
				left.push(make_pair(tmp, i));//tmp = departure time, i = car code
			else
				right.push(make_pair(tmp, i));
		}

		map <int, int> result;//key = car code, value = arrival time

		int curr_time = 0;
		bool position = 0;//0 indicates left, 1 indicates right

		while (!left.empty() || !right.empty()) {
			bool ferryEmpty = 1;

			if (position){
				int counter = 0;
				while (!right.empty() && counter < n && right.front().first <= curr_time){
					pair <int, int> tmp = right.front();
					right.pop();
					result[tmp.second] = curr_time + t;
					ferryEmpty = 0;
					++counter;
				}
			}
			else {
				int counter = 0;
				while (!left.empty() && counter < n && left.front().first <= curr_time){
					pair <int, int> tmp = left.front();
					left.pop();
					result[tmp.second] = curr_time + t;
					ferryEmpty = 0;
					++counter;
				}
			}

			if (!ferryEmpty) {
				curr_time += t;
				position = !position;
			}
			else {
				pair <int, int> carR, carL;
				
				if (!right.empty())
					carR = right.front();
				else
					carR = make_pair(INT_MAX, INT_MAX);

				if (!left.empty())
					carL = left.front();
				else
					carL = make_pair(INT_MAX, INT_MAX);

				if (carR.first < carL.first){
					if (position) 
						curr_time = max(curr_time, carR.first);
					else {
						curr_time = max(curr_time, carR.first);
						curr_time += t;
						position = 1;
					}
				}
				else if (carR.first > carL.first){
					if (!position)
						curr_time = max(curr_time, carL.first);
					else{
						curr_time = max(curr_time, carL.first);
						curr_time += t;
						position = 0;
					}
				}
				else
					curr_time = max(curr_time, carR.first);

			}
		}

		for (auto a : result)
			cout << a.second << endl;

		if (T != 0)
			cout << endl;

	}

	return 0;
}

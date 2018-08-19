//uva 10465
//Homer Simpson

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main(void)
{
	int m, n, t;
	while (cin >> m >> n >> t) {
		vector <int> maxNum(t + 1, 0);
		vector <int> wasteTime(t + 1, 0);

		maxNum[0] = 0;
		wasteTime[0] = 0;

		for (int i = 1; i <= t; ++i){
			if (i - m >= 0){
				maxNum[i] = maxNum[i - m] + 1;
				wasteTime[i] = wasteTime[i - m];
			}
			else
				wasteTime[i] = i;
			if (i - n >= 0){
				if (wasteTime[i - n] < wasteTime[i]){
					maxNum[i] = maxNum[i - n] + 1;
					wasteTime[i] = wasteTime[i - n];
				}
				else if (wasteTime[i - n] == wasteTime[i] && maxNum[i - n] + 1 > maxNum[i]){
					maxNum[i] = maxNum[i - n] + 1;
					wasteTime[i] = wasteTime[i - n];
				}
			}
		}



		cout << maxNum[t];
		if (wasteTime[t] != 0)
			cout << ' ' << wasteTime[t];
		cout << endl;
	}

	return 0;
}

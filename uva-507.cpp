//uva 507
//Jill Rides Again

#include <iostream>
#include <climits>
#include <vector>

using namespace std;

pair <int, int> kadane(vector <int> & niceness);

int main(void)
{
	int T = 0;
	cin >> T;

	int tcounter = 0;

	while(T--) {
		++tcounter;

		int stop = 0;
		cin >> stop;

		vector <int> niceness(stop - 1);
		for (int i = 0; i < stop - 1; ++i)
			cin >> niceness[i];

		pair <int, int> result = kadane(niceness);

		if (result.first != -1 && result.second != -1)
			cout << "The nicest part of route " << tcounter << " is between stops " << result.first + 1 << " and " << result.second + 2 << endl;
		else 
			cout << "Route " << tcounter << " has no nice parts" << endl;


	}
	return 0;
}


pair <int, int> kadane(vector <int> & niceness)
{
	int maximum_so_far = INT_MIN;
	int sum_so_far = 0;

	pair <int, int> interval = make_pair(0, 0);

	int tmp_begin = 0;

	for (int i = 0; i < niceness.size(); ++i){
		sum_so_far += niceness[i];

		if (sum_so_far > maximum_so_far){
			maximum_so_far = sum_so_far;
			interval.first = tmp_begin;
			interval.second = i;
		}

		if (sum_so_far == maximum_so_far && interval.first == tmp_begin)
			interval.second = i;
		else if (sum_so_far == maximum_so_far && i - tmp_begin > interval.second - interval.first)
			interval = make_pair(tmp_begin, i);

		if (sum_so_far < 0){
			sum_so_far = 0;
			tmp_begin = i + 1;
		}
	}

	if (maximum_so_far < 0)
		interval = make_pair(-1, -1);

	return interval;
}

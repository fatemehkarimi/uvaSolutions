//uva 10534
//Wavio Sequence

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector <int> LIS(vector <int> & nums);

int main(void)
{
	int n = 0;
	while (cin >> n) {
		vector <int> nums(n);

		for (int i = 0; i < n; ++i) {
			int t;
			cin >> t;

			nums[i] = t;
		}

		vector <int> lis = LIS(nums);

		std::reverse(nums.begin(), nums.end());
		vector <int> rlis = LIS(nums);

		std::reverse(rlis.begin(), rlis.end());

		int max = 0;
		for (int i = 0; i < n; ++i)
			if (min(lis[i], rlis[i]) > min(lis[max], rlis[max]))
				max = i;

		cout << min(lis[max], rlis[max]) * 2 - 1 << endl;
	}

	return 0;
}

int locate(vector <int> & arr, int origin, int end, int num)
{
	while (end - origin > 1) {
		int middle = origin + (end - origin) / 2;

		if (num <= arr[middle])
			end = middle;
		else
			origin = middle;
	}

	return end;
}

vector <int> LIS(vector <int> & nums)
{
	vector <int> arr(nums.size());
	vector <int> result(nums.size());

	arr[0] = nums[0];
	result[0] = 1;
	int length = 1;

	for (int i = 1; i < nums.size(); ++i)
		if (nums[i] <= arr[0]){
			arr[0] = nums[i];
			result[i] = 1;
		}
		else if (nums[i] > arr[length - 1]){
			arr[length++] = nums[i];
			result[i] = length;
		}
		else{
			int pos = locate(arr, -1, length - 1, nums[i]);
			arr[pos] = nums[i];
			result[i] = pos + 1;
		}

	return result;
}

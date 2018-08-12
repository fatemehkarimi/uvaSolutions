//uva 481
//What Goes Up

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

stack <int> LIS(vector <int> & num);

int main(void)
{
	vector <int> num;
	int data;
	while (cin >> data)
		num.push_back(data);

	stack <int> result = LIS(num);

	cout << result.size() << endl << "-" << endl;

	while (!result.empty()){
		cout << num[result.top()] << endl;
		result.pop();
	}

	return 0;
}

int getIndex(vector <int> & num, vector <int> & tail, int left, int right, int key)
{
	while (right - left > 1){
		int middle = left + (right - left) / 2;

		if (num[tail[middle]] >= key)
			right = middle;
		else
			left = middle;
	}

	return right;
}

stack <int> LIS(vector <int> & num)
{
	vector <int> tail(num.size());
	vector <int> prev(num.size(), -1);

	stack <int> result;
	if (num.size() == 0)
		return result;
	
	tail[0] = 0;
	int length = 1;

	for (unsigned int i = 1; i < num.size(); ++i)
		if (num[i] < num[tail[0]])
			tail[0] = i;
		else if (num[i] > num[tail[length - 1]]){
			prev[i] = tail[length - 1];
			tail[length++] = i;
		}
		else{
			int pos = getIndex(num, tail, -1, length - 1, num[i]);
			prev[i] = (pos != 0 ? tail[pos - 1] : -1);
			tail[pos] = i;
		}

	for (int i = tail[length - 1]; i >= 0; i = prev[i]) 
		result.push(i);

	return result;
}

//uva 108
//Maximum Sum

#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int n = 0;
	cin >> n;

	vector <vector <int> > arr(n, vector <int> (n, 0));

	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j){
			cin >> arr[i][j];

			if(i - 1 >= 0)
				arr[i][j] += arr[i - 1][j];
			if(j - 1 >= 0)
				arr[i][j] += arr[i][j - 1];
			if(i - 1 >= 0 && j - 1 >= 0)
				arr[i][j] -= arr[i - 1][j - 1];
		}

		int max_sum = 0;

		for(int r1 = 0; r1 < n; ++r1)
			for(int r2 = r1; r2 < n; ++r2)
				for(int c1 = 0; c1 < n; ++c1)
					for(int c2 = c1; c2 < n; ++c2){
						int tmp_sum = arr[r2][c2];

						if(r1 - 1 >= 0)
							tmp_sum -= arr[r1 - 1][c2];

						if(c1 - 1 >= 0)
							tmp_sum -= arr[r2][c1 - 1];

						if(r1 - 1 >= 0 && c1 - 1 >= 0)
							tmp_sum += arr[r1 - 1][c1 - 1];

						max_sum = max(max_sum, tmp_sum);
					}

	cout << max_sum << endl;

	return 0;
}

//uva 722
//Lakes

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int DFS(vector <string> & arr, int x, int y);

int main(void)
{
	int t = 0;
	cin >> t;
	while (t--) {
		int x, y;

		cin >> x >> y;
		--x;
		--y;
		getchar();
		vector <string> arr;//water=0, land=1

		while (true){
			string input;
			getline(std::cin, input);

			if(input == "")
				break;

			arr.push_back(input);
		}

		cout << DFS(arr, x, y) << endl;

		if (t)
			cout << endl;
	}

	return 0;
}

int DFS(vector <string> & arr, int x, int y)
{
	int m = arr.size();
	int n = arr[0].size();

	int count = 1;
	arr[x][y] = '1';

	int xs[] = {-1, 0, 0, 1};
	int ys[] = {0, -1, 1, 0};


	for (int i = 0; i < 4; ++i){
		int nx = x + xs[i];
		int ny = y + ys[i];

		if (nx >= 0 && nx < m && ny >= 0 && ny < n && arr[nx][ny] == '0')
			count += DFS(arr, nx, ny);
	}

	return count;
}

//uva 11450
//Wedding Shopping

#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int T = 0;
	cin >> T;

	while (T--){
		int M = 0, C = 0;
		cin >> M >> C;

		vector < vector <int> > objects(C);
		for (int i = 0; i < C; ++i){
			int k = 0;
			cin >> k;

			for (int j = 0; j < k; ++j){
				int x;
				cin >> x;

				objects[i].push_back(x);
			}
		}


		vector < vector <int> > arr(C + 1, vector <int> (M + 1));

		for (int i = 0; i <= C; ++i)
			arr[i][0] = -1;
		for (int j = 0; j <= M; ++j)
			arr[0][j] = 0;


		for (int i = 1; i <= C; ++i)
			for (int j = 1; j <= M; ++j){
				arr[i][j] = -1;
				for (int k = 0; k < objects[i - 1].size(); ++k){
					int value = objects[i - 1][k];

					if (j - value >= 0 && arr[i - 1][j - value] >= 0)
						if (value + arr[i - 1][j - value] > arr[i][j])
							arr[i][j] = value + arr[i - 1][j - value];
				}
			}

		if (arr[C][M] == -1)
			cout << "no solution" << endl;
		else
			cout << arr[C][M] << endl;

	}

	return 0;
}

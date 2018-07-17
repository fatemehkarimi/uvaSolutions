//uva 111
//History Grading

#include <iostream>
#include <vector>

using namespace std;


int LCS(vector <int> & a, vector <int> & b);
int find(vector <int> & num, int a);
int max(int a, int b);


int main(void)
{
	int n = 0;
	vector <int> scores;
	vector <int> correctOrder;

	while(true) {
		char c = ' ';
		bool end = 0;


		while (true) {
			int t = 0;

			if (scanf("%d%c", &t, &c) == EOF){
				end = 1;
				break;
			}
			scores.push_back(t);
			if (c == '\n')
				break;
		}

		if (scores.size() == 1){
			n = scores[0];
			correctOrder.clear();

			for (int i = 0; i < n; ++i){
				int t;
				cin >> t;
				correctOrder.push_back(t);
			}
			getchar();//removing \n
		}
		else if (scores.size() == n){
			vector <int> correctOrderRank(n);
			vector <int> scoresRank(n);

			for (int i = 0; i < n; ++i){
				correctOrderRank[correctOrder[i] - 1] = i + 1;
				scoresRank[scores[i] - 1] = i + 1;
			}

			int result = LCS(correctOrderRank, scoresRank);
			cout << result << endl;
		}
		scores.clear();

		if (end)
			break;
	}
	return 0;
}


int LCS(vector <int> & a, vector <int> & b)
{

	int m = a.size() + 1;
	int n = b.size() + 1;
	vector < vector <int> > arr(m, vector <int> (n));

	for(int i = 1; i < m; ++i)
		for (int j = 1; j < n; ++j)
			if (a[i - 1] == b[j - 1])
				arr[i][j] = arr[i - 1][j - 1] + 1;
			else
				arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);


	return arr[m - 1][n - 1];

}

int max(int a, int b)
{
	return a > b ? a : b;
}


int find(vector <int> & num, int a)
{
	for (int i = 0; i < num.size(); ++i)
		if (num[i] == a)
			return i;

	return -1;
}

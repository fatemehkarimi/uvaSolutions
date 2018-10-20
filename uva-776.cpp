//uva 776
//Monkeys in a Regular Forest

#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int digits(int a);
void DFS(vector <vector <char> > & forest, vector <vector <int> > & neighbors, int x, int y, char type, int code);

int main(void)
{
	bool con = 1;
	while (con){
		vector <vector <char> > forest;
		bool done = 0;

		while (!done){
			vector <char> row;

			while (true){
				char c = getchar();

				if (c == ' ');
				else if (c == '\n')
					break;
				else if (c == '%'){
					done = 1;
					getchar();//removing '\n' after %
					break;
				}
				else if (c == EOF){
					done = 1;
					con = 0;
					break;
				}
				else
					row.push_back(c);
			}

			if (!row.empty())
				forest.push_back(row);
		}

		int m = forest.size();
		int n = forest[0].size();

		vector <vector <int> > neighbors(m, vector <int> (n, 0));

		int code = 1;
		for (int i = 0; i < m; ++i)
			for (int j = 0; j < n; ++j)
				if (neighbors[i][j] == 0){
					char type = forest[i][j];
					DFS(forest, neighbors, i, j, type, code);
					++code;
				}

		vector <int> max_in_col(n);
		for (int j = 0; j < n; ++j)
			for (int i = 0; i < m; ++i)
				max_in_col[j] = max(max_in_col[j], neighbors[i][j]);

		for (auto a : neighbors){
			cout << right << setw(digits(max_in_col[0])) << a[0];
			for (int i = 1; i < n; ++i)
				cout << right << setw(digits(max_in_col[i]) + 1) << a[i];
			cout << endl;
		}


		cout << "%" << endl;
	}
	return 0;
}

void DFS(vector <vector <char> > & forest, vector <vector <int> > & neighbors, int x, int y, char type, int code)
{
	int m = forest.size();
	int n = forest[0].size();

	neighbors[x][y] = code;
	int xs[] = {-1, -1, -1, 0, 0, 1, 1, 1};
	int ys[] = {-1, 0, 1, -1, 1, -1, 0, 1};

	for (int i = 0; i < 8; ++i){
		int nx = x + xs[i];
		int ny = y + ys[i];

		if (nx >= 0 && nx < m && ny >= 0 && ny < n && forest[nx][ny] == type && neighbors[nx][ny] == 0)
			DFS(forest, neighbors, nx, ny, type, code);
	}

	return;
}

int digits(int a)
{
	int result = 1;
	while (a / 10){
		++result;
		a /= 10;
	}

	return result;
}

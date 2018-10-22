//uva 782
//Contour Painting

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void DFS_star(vector <string> & contour, int x, int y);
void DFS_bound(vector <string> & contour, int x, int y, char bound_c);

int main(void)
{
	int t;
	cin >> t;
	getchar();

	while (t--) {
		vector <string> contour;
		string seperate_line;

		int max_l = 0;

		while(true){
			string input;
			getline(std::cin, input);

			if (input[0] == '_'){
				seperate_line = input;
				break;
			}

			input = input + ' ';
			contour.push_back(input);
			max_l = max(max_l, (int)input.size());
		}

		for (int i = 0; i < contour.size(); ++i)
			contour[i] = contour[i] + std::string(max_l - contour[i].size(), ' ');

		for (int i = 0; i < contour.size(); ++i){
			bool BRK = 0;

			for (int j = 0; j < contour[i].size(); ++j)
				if (contour[i][j] == '*'){
					DFS_star(contour, i, j);
					BRK = 1;
					break;
				}

			if (BRK)
				break;
		}

		char bound_c;
		for (int i = 0; i < contour.size(); ++i){
			bool BRK = 0;
			for (int j = 0; j < max_l; ++j)
				if (contour[i][j] != '*' && contour[i][j] != ' ' && contour[i][j] != '_'){
					bound_c = contour[i][j];
					BRK = 1;
					break;
				}

				if (BRK)
					break;
		}

		for (int i = 0; i < contour.size(); ++i)
			for (int j = 0; j < max_l; ++j)
				if (contour[i][j] == bound_c)
					DFS_bound(contour, i, j, bound_c);


		for (auto a : contour){
			int last = a.size() - 1;
			while (a[last] == ' ' || a[last] == '*')
				--last;

			for (int i = 0; i <= last; ++i)
				if (a[i] == '_')
					cout << bound_c;
				else if (a[i] == '*')
					cout << ' ';
				else
					cout << a[i];

			cout << endl;
		}

		cout << seperate_line << endl;
	}

	return 0;
}

void DFS_star(vector <string> & contour, int x, int y)
{
	contour[x][y] = '*';

	int xs[] = {-1, 0, 0, 1};
	int ys[] = {0, -1, 1, 0};

	for (int i = 0; i < 4; ++i){
		int nx = x + xs[i];
		int ny = y + ys[i];

		if (nx >= 0 && nx < contour.size() && ny >= 0 && ny < contour[nx].size() && contour[nx][ny] == ' ')
			DFS_star(contour, nx, ny);
	}
	return;
}

void DFS_bound(vector <string> & contour, int x, int y, char bound_c)
{
	contour[x][y] = '_';

	int xs[] = {-1, -1, -1, 0, 0, 1, 1, 1};
	int ys[] = {-1, 0, 1, -1, 1, -1, 0, 1};

	for (int i = 0; i < 8; ++i){
		int nx = x + xs[i];
		int ny = y + ys[i];

		if (nx >= 0 && nx < contour.size() && ny >= 0 && ny < contour[nx].size())
			if (contour[nx][ny] == bound_c)
				DFS_bound(contour, nx, ny, bound_c);
	}

	int xd[] = {-1, 0, 0, 1};
	int yd[] = {0, -1, 1, 0};

	for (int i = 0; i < 4; ++i){
		int nx = x + xd[i];
		int ny = y + yd[i];

		if (nx >= 0 && nx < contour.size() && ny >= 0 && ny < contour[nx].size() && contour[nx][ny] == '*')
			contour[nx][ny] = '#';
	}

	return;
}

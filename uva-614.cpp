//uva 614
//Mapping the Route

#include <iostream>
#include <vector>
#include <map>
#include <iomanip>

using namespace std;

void dfs(vector <vector <int> > & arr, map < pair <int, int>, vector <bool> > & walls,
		 map <pair <int, int> , pair <int, int> > & path, int x_s, int y_s, int x_g, int y_g);

int main(void)
{
	int m, n, x_s, y_s, x_g, y_g;
	int tcounter = 0;
	while(true){
		cin >> m >> n >> x_s >> y_s >> x_g >> y_g;
		if(m == 0 && n == 0) break;

		++tcounter;

		--x_s, --y_s;
		--x_g, --y_g;

		map < pair <int, int>, vector <bool> > walls;
		map < pair <int, int>, pair <int, int> > path;

		for(int i = 0; i < m; ++i)
			for(int j = 0; j < n; ++j)
				walls[make_pair(i, j)] = {1, 1, 1, 1};


		for(int i = 0; i < m; ++i)
			for(int j = 0; j < n; ++j){
				pair <int, int> cell = make_pair(i, j);
				int value;
				cin >> value;

				if(value == 1){
					walls[cell][2] = 0;//east is not valid
					if(j + 1 < n)
						walls[make_pair(i, j + 1)][0] = 0;
				}
				else if(value == 2){
					walls[cell][3] = 0;//south is not valid
					if(i + 1 < m)
						walls[make_pair(i + 1, j)][1] = 0;
				}
				else if(value == 3){
					walls[cell][2] = 0;
					walls[cell][3] = 0;
					if(j + 1 < n)
						walls[make_pair(i, j + 1)][0] = 0;
					if(i + 1 < m)
						walls[make_pair(i + 1, j)][1] = 0;
				}
				path[cell] = make_pair(-1, -1);
			}


		vector < vector <int> > array(m, vector <int>(n, 0));
		dfs(array, walls, path, x_s, y_s, x_g, y_g);

		int len = 2;


		if(array[x_g][y_g] == 1)
			while(x_g != -1 && y_g != -1){
				array[x_g][y_g] = len++;
				pair <int, int> tmp = path[make_pair(x_g, y_g)];
				x_g = tmp.first;
				y_g = tmp.second;
			}

		cout << "Maze " << tcounter << endl << endl;
		//Printing the Maze
		for(int i = 0; i < n; ++i)
			cout << "+---";
		cout << "+" << endl;

		for(int i = 0; i < m; ++i){
			cout << "|";
			for(int j = 0; j < n; ++j){
				if(array[i][j] == 1)
					cout << "???";
				else if(array[i][j] == 0)
					cout << "   ";
				else
					cout << setw(3) << len - array[i][j];
				
				if(j != n - 1 && walls[make_pair(i, j)][2] == 0)
					cout << "|";
				else if(j != n - 1)
					cout << ' ';
			}
			cout << "|" << endl;

			if(i == m - 1) break;

			for(int j = 0; j < n; ++j)
				if(walls[make_pair(i, j)][3] == 0)
					cout << "+---";
				else
					cout << "+   ";
			cout << "+" << endl;
		}

		for(int i = 0; i < n; ++i)
			cout << "+---";
		cout << "+" << endl;

		cout << endl << endl;
	}
	return 0;
}

void dfs(vector <vector <int> > & arr, map < pair <int, int>, vector <bool> > & walls,
		 map <pair <int, int> , pair <int, int> > & path, int x_s, int y_s, int x_g, int y_g)
{
	int m = arr.size();
	int n = arr[0].size();

	arr[x_s][y_s] = 1;

	int xs[4] = {0, -1, 0, 1};
	int ys[4] = {-1, 0, 1, 0};

	for(int i = 0; i < 4; ++i){

		int nx = x_s + xs[i];
		int ny = y_s + ys[i];

		if(nx >= 0 && nx < m && ny >= 0 && ny < n){
			if(arr[x_g][y_g] == 1) return;//goal has been reached

			if(walls[make_pair(x_s, y_s)][i] && arr[nx][ny] == 0){
				path[make_pair(nx, ny)] = make_pair(x_s, y_s);
				dfs(arr, walls, path, nx, ny, x_g, y_g);
			}
		}
	}

	return;
}

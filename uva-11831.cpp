//uva 11831
//Sticker Collector Robots

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void)
{
	int m, n, s;
	while (true){
		cin >> m >> n >> s;

		if (m == 0 && n == 0 && s == 0)
			break;

		int x, y;
		int direct;//north=0, east=1, south=2, west=3

		vector <string> maze;
		for (int i = 0; i < m; ++i){
			string tmp;
			cin >> tmp;

			for (int j = 0; j < tmp.size(); ++j)
				if (tmp[j] == 'N'){
					x = i;
					y = j;
					direct = 0;
				}
				else if (tmp[j] == 'L'){
					x = i;
					y = j;
					direct = 1;
				}
				else if (tmp[j] == 'S'){
					x = i;
					y = j;
					direct = 2;
				}
				else if (tmp[j] == 'O'){
					x = i;
					y = j;
					direct = 3;
				}

			maze.push_back(tmp);
		}

		string instruct;
		cin >> instruct;

		int sticker = 0;

		for (int i = 0; i < s; ++i)
			if (instruct[i] == 'D')
				direct = (direct + 1) % 4;
			else if (instruct[i] == 'E')
				direct = (direct - 1 + 4) % 4;
			else{
				int xp = x;
				int yp = y;

				if (direct == 0)
					xp -= 1;
				else if (direct == 1)
					yp += 1;
				else if (direct == 2)
					xp += 1;
				else
					yp -= 1;

				if (xp >= 0 && xp < m && yp >= 0 && yp < n && maze[xp][yp] != '#'){
					x = xp;
					y = yp;
					if (maze[x][y] == '*'){
						++sticker;
						maze[x][y] = '.';
					}
				}
			}

		cout << sticker << endl;
	}
		return 0;
}

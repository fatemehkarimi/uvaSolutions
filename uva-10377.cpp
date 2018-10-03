//uva 10377
//Maze Traversal

#include <iostream>
#include <vector>

using namespace std;

char rotateR(char d);
char rotateL(char d);

int main(void)
{
	int T = 0;
	cin >> T;

	while (T--) {
		int n, m;

		cin >> n >> m;
		getchar();
		vector < string > maze;
		for (int i = 0; i < n; ++i){
			string tmp;
			getline(std::cin, tmp);
			maze.push_back(tmp);
		}

		int x, y;
		char direct = 'N';

		cin >> x >> y;//assumming bounds are given from zero if not, decrease them by one
		--x;
		--y;

		bool finished = 0;
		while(!finished){
			string move;
			cin >> move;

			for (auto a : move)
				switch(a){
					case 'R':
						direct = rotateR(direct);
						break;
					case 'L':
						direct = rotateL(direct);
						break;
					case 'F':{
						int xp = x;
						int yp = y;

						if (direct == 'N')
							xp -= 1;
						if (direct == 'E')
							yp += 1;
						if (direct == 'S')
							xp += 1;
						if (direct == 'W')
							yp -= 1;

						if (xp >= 0 && yp >= 0 && xp < n && yp < m)
							if (maze[xp][yp] == ' '){
								x = xp;
								y = yp;
							}
						break;
					}
					case 'Q':
						finished = 1;
						break;
					default:
						break;
				}
		}

		cout << x + 1 << ' ' << y + 1 << ' ' << direct << endl;
		if (T)
			cout << endl;
	}

	return 0;
}

char rotateR(char d)
{
	if (d == 'N')
		return 'E';
	if (d == 'E')
		return 'S';
	if (d == 'S')
		return 'W';
	else
		return 'N';
}

char rotateL(char d)
{
	if (d == 'N')
		return 'W';
	if (d == 'W')
		return 'S';
	if (d == 'S')
		return 'E';
	else
		return 'N';
}

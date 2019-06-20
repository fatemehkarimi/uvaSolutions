//uva 11352
//Crazy King

#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int BFS(vector < vector <bool> > & Graph, int xA, int yA, int xB, int yB);

int main(void)
{
	int T = 0;
	cin >> T;
	while(T--){
		int m, n;
		cin >> m >> n;

		vector <string> board(m);
		for(int i = 0; i < m; ++i){
			string tmp;
			cin >> tmp;
			board[i] = tmp;
		}

		int xA, yA;
		int xB, yB;

		vector < vector <bool> > Graph(m, vector <bool> (n, true));

		//convert board to graph
		int horse_x[] = {-2, -2, -1, -1, 0, 1, 1, 2, 2};
		int horse_y[] = {-1, 1, -2, 2, 0, -2, 2, -1, 1};
		int size = sizeof(horse_x) / sizeof(int);

		for(int i = 0; i < m; ++i)
			for(int j = 0; j < n; ++j)
				if(board[i][j] == 'Z')
					for(int k = 0; k < size; ++k){
						int x1 = i + horse_x[k];
						int y1 = j + horse_y[k];

						if(x1 >= 0 && x1 < m && y1 >= 0 && y1 < n)
							Graph[x1][y1] = 0;
					}
				else if(board[i][j] == 'A'){
					xA = i;
					yA = j;
				}
				else if(board[i][j] == 'B'){
					xB = i;
					yB = j;
				}
		Graph[xA][yA] = Graph[xB][yB] = 1;//moving to A and B is always possible

		int result = BFS(Graph, xA, yA, xB, yB);
		if(result == -1)
			cout << "King Peter, you can't go now!" << endl;
		else
			cout << "Minimal possible length of a trip is " << result << endl;
	}
	return 0;
}

int BFS(vector < vector <bool> > & Graph, int xA, int yA, int xB, int yB)
{
	int m = Graph.size();
	int n = Graph[0].size();
	queue < pair <int, pair <int, int> > > Queue;
	Queue.push(make_pair(0, make_pair(xA, yA)));

	int king_x[] = {-1, -1, -1, 0, 0, 1, 1, 1};
	int king_y[] = {-1, 0, 1, -1, 1, -1, 0, 1};
	int size = sizeof(king_x) / sizeof(int);

	while(!Queue.empty()){
		int l = Queue.front().first;
		int x = Queue.front().second.first;
		int y = Queue.front().second.second;
		Queue.pop();

		if(xB == x && yB == y)
			return l;

		for(int i = 0; i < size; ++i){
			int x1 = x + king_x[i];
			int y1 = y + king_y[i];

			if(x1 >= 0 && x1 < m && y1 >= 0 && y1 < n && Graph[x1][y1]){
				Graph[x1][y1] = 0;
				Queue.push(make_pair(l + 1, make_pair(x1, y1)));
			}
		}
	}
	return -1;
}

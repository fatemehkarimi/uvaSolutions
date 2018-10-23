//uva 852
//Deciding victory in Go

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void DFS(vector <string> & board, bool visited[9][9], int x, int y, char c);

int main(void)
{
    int T;
    cin >> T;
    while (T--) {
        vector <string> board(9);

        for (int i = 0; i < 9; ++i)
            cin >> board[i];

        bool visitedX[9][9] = {};
        bool visitedO[9][9] = {};

        for (int i = 0; i < 9; ++i)
            for (int j = 0; j < 9; ++j)
                if (board[i][j] == 'X' && !visitedX[i][j])
                    DFS(board, visitedX, i, j, board[i][j]);

        for (int i = 0; i < 9; ++i)
            for (int j = 0; j < 9; ++j)
                if (board[i][j] == 'O' && !visitedO[i][j])
                    DFS(board, visitedO, i, j, board[i][j]);

        int black = 0, white = 0;

        for(int i = 0; i < 9; ++i)
            for (int j = 0; j < 9; ++j)
                if (board[i][j] == 'X')
                    ++black;
                else if (board[i][j] == 'O')
                    ++white;
                else{
                    if (visitedX[i][j] && !visitedO[i][j])
                        ++black;
                    else if (visitedO[i][j] && !visitedX[i][j])
                        ++white;
                }

        cout << "Black " << black << " White " << white << endl;
    }

    return 0;
}

void DFS(vector <string> & board, bool visited[9][9], int x, int y, char c)
{
    visited[x][y] = 1;

    int xs[] = {-1, 0, 0, 1};
    int ys[] = {0, -1, 1, 0};

    for (int i = 0; i < 4; ++i){
        int nx = x + xs[i];
        int ny = y + ys[i];

        if (nx >= 0 && nx < 9 && ny >= 0 && ny < 9)
            if (board[nx][ny] == '.' && !visited[nx][ny])
                DFS(board, visited, nx, ny, c);
    }

    return;
}

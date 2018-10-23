//uva 11561 
//Getting Gold

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void DFS(vector <string> & arr, vector <vector <bool> > & visited, int x, int y);

int main(void)
{
    int w, h;
    while (cin >> w >> h){
        vector <string> arr(h);

        int x, y;

        for (int i = 0; i < h; ++i){
            cin >> arr[i];
            for (int j = 0; j < w; ++j)
                if (arr[i][j] == 'P'){
                    x = i;
                    y = j;
                    break;
                }
        }

        vector <vector <bool> > visited(h, vector <bool> (w, false));
        DFS(arr, visited, x, y);

        int gold = 0;

        for (int i = 0; i < h; ++i)
            for (int j = 0; j < w; ++j)
                if(arr[i][j] == 'G' && visited[i][j])
                    ++gold;

        cout << gold << endl;
    }

    return 0;
}

void DFS(vector <string> & arr, vector <vector <bool> > & visited, int x, int y)
{
    visited[x][y] = 1;

    int h = arr.size();
    int w = arr[0].size();

    int xs[] = {-1, 0, 0, 1};
    int ys[] = {0, -1, 1, 0};

    bool feelTrap = 0;

    for (int i = 0; i < 4; ++i){
        int nx = x + xs[i];
        int ny = y + ys[i];

        if (nx >= 0 && nx < h && ny >= 0 && ny < w)
            if (arr[nx][ny] == 'T'){
                feelTrap = 1;
                break;
            }
    }

    if (feelTrap)
        return;

    for (int i = 0; i < 4; ++i){
        int nx = x + xs[i];
        int ny = y + ys[i];

        if (nx >= 0 && nx < h && ny >= 0 && ny < w)
            if (!visited[nx][ny] && arr[nx][ny] != '#')
                DFS(arr, visited, nx, ny);
    }    

    return;
}

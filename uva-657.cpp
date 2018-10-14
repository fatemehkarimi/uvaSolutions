//uva 657
//The die is cast

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>

using namespace std;

int BFS(vector <string> & arr, int x, int y);
void DFS(vector <string> & arr, int x, int y);

int main(void)
{
    int w, h;
    int tcounter = 0;
    while (true) {
        cin >> w >> h;

        if (w == 0 && h == 0)
            break;

        ++tcounter;

        vector <string> arr(h);
        for (int i = 0; i < h; ++i)
            cin >> arr[i];

        vector <int> result;

        for (int i = 0; i < h; ++i)
            for (int j = 0; j < w; ++j)
                if (arr[i][j] == '*')
                    result.push_back(BFS(arr, i, j));

        for (int i = 0; i < h; ++i)
            for (int j = 0; j < w; ++j)
                if (arr[i][j] == 'X'){
                    DFS(arr, i, j);
                    result.push_back(1);
                }

        sort(result.begin(), result.end());

        cout << "Throw " << tcounter << endl;

        cout << result[0];
        for (int i = 1; i < result.size(); ++i)
            cout << ' ' << result[i];

        cout << endl << endl;

    }
    return 0;
}

int BFS(vector <string> & arr, int x, int y)
{
    queue <pair <int, int> > Queue;
    Queue.push(make_pair(x, y));
    arr[x][y] = '.';

    int h = arr.size();
    int w = arr[0].size();

    int xs[] = {-1, 0, 0, 1};
    int ys[] = {0, -1, 1, 0};

    int count = 0;

    while (!Queue.empty()){
        int tx = Queue.front().first;
        int ty = Queue.front().second;
        Queue.pop();

        for (int i = 0; i < 4; ++i){
            int nx = tx + xs[i];
            int ny = ty + ys[i];

            if (nx >= 0 && nx < h && ny >= 0 && ny < w){
                if (arr[nx][ny] == '*'){
                    arr[nx][ny] = '.';
                    Queue.push(make_pair(nx, ny));
                }
                else if (arr[nx][ny] == 'X'){
                    ++count;
                    DFS(arr, nx, ny);
                    Queue.push(make_pair(nx, ny));
                }
            }
        }
    }

    return count;
}

void DFS(vector <string> & arr, int x, int y)
{
    arr[x][y] = '*';

    int h = arr.size();
    int w = arr[0].size();

    int xs[] = {-1, 0, 0, 1};
    int ys[] = {0, -1, 1, 0};

    for(int i = 0; i < 4; ++i){
        int nx = x + xs[i];
        int ny = y + ys[i];

        if (nx >= 0 && nx < h && ny >= 0 && ny < w)
            if (arr[nx][ny] == 'X')
                DFS(arr, nx, ny);
    }

    return;
}

//uva 10653
//Bombs! NO they are Mines!!

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int BFS(vector <vector <bool> > & arr, int xs, int ys, int xd, int yd);

int main(void)
{
    int r, c;
    while (true){
        cin >> r >> c;

        if (r == 0 && c == 0)
            break;

        vector < vector <bool> > arr(r, vector <bool> (c, true));
        int n;
        cin >> n;

        for (int i = 0; i < n; ++i){
            int row, count;
            cin >> row >> count;

            for (int j = 0; j < count; ++j){
                int t;
                cin >> t;

                arr[row][t] = false;
            }
        }

        int xs, ys, xd, yd;
        cin >> xs >> ys >> xd >> yd;

        cout << BFS(arr, xs, ys, xd, yd) << endl;

    }
    return 0;
}

int BFS(vector <vector <bool> > & arr, int xs, int ys, int xd, int yd)
{
    int r = arr.size();
    int c = arr[0].size();

    vector <vector <int> > visited(r, vector<int> (c, -1));

    queue < pair <int, int> > Queue;
    Queue.push(make_pair(xs, ys));
    visited[xs][ys] = 0;

    int xx[] = {-1, 0, 0, 1};
    int yy[] = {0, -1, 1, 0};

    while (!Queue.empty()){
        pair <int, int> front = Queue.front();
        Queue.pop();

        for (int i = 0; i < 4; ++i){
            int nx = front.first + xx[i];
            int ny = front.second + yy[i];

            if (nx >= 0 && nx < r && ny >= 0 && ny < c && arr[nx][ny] && visited[nx][ny] == -1){
                visited[nx][ny] = visited[front.first][front.second] + 1;
                Queue.push(make_pair(nx, ny));
            }
        }
    }

    return visited[xd][yd];
}

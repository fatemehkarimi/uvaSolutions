//uva 11906
//Knight in War Grid

#include <iostream>
#include <climits>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int main(void)
{
    int T = 0, tcounter = 0;
    cin >> T;

    while (T--) {
        ++tcounter;

        int row, col, m, n;
        cin >> row >> col >> m >> n;

        vector < vector <int> > arr(row, vector <int> (col, -1));
        int N;
        cin >> N;

        for (int i = 0; i < N; ++i){
            int x, y;
            cin >> x >> y;

            arr[x][y] = INT_MIN;//Water
        }

        int x_move[] = {-1, -1, 1, 1};
        int y_move[] = {-1, 1, -1, 1};

        queue < pair <int, int> > Queue;
        Queue.push(make_pair(0, 0));
        arr[0][0] = 0;

        while (!Queue.empty()) {
            pair <int, int> front = Queue.front();
            Queue.pop();

            set < pair<int, int> > connectedSq;

            for (int i = 0; i < 4; ++i) {
                int new_x1 = front.first + x_move[i] * m;
                int new_y1 = front.second + y_move[i] * n;

                int new_x2 = front.first + x_move[i] * n;
                int new_y2 = front.second + y_move[i] * m;

                if (new_x1 >= 0 && new_x1 < row && new_y1 >= 0 && new_y1 < col
                    && arr[new_x1][new_y1] != INT_MIN)
                    connectedSq.insert(make_pair(new_x1, new_y1));

                if (new_x2 >= 0 && new_x2 < row && new_y2 >= 0 && new_y2 < col
                    && arr[new_x2][new_y2] != INT_MIN)
                    connectedSq.insert(make_pair(new_x2, new_y2));
            }

            for (auto a : connectedSq){
                if (arr[a.first][a.second] == -1){
                    Queue.push(a);
                    arr[a.first][a.second] = 0;
                }

                ++arr[a.first][a.second];
            }
        }


        int odd = 0, even = 0;
        for (int i = 0; i < row; ++i)
            for (int j = 0; j < col; ++j)
                if (arr[i][j] >= 0){
                    if (arr[i][j] % 2)
                        ++odd;
                    else
                        ++even;
                }

        cout << "Case " << tcounter << ": " << even << ' ' << odd << endl;

    }
    return 0;
}

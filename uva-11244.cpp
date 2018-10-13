//uva 11244
//Counting Stars

#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int BFS(vector <string> & sky, int x, int y);

int main(void)
{
    int r, c;
    while (true) {
        cin >> r >> c;

        if (r == 0 && c == 0)
            break;

        vector <string> sky(r);
        for (int i = 0; i < r; ++i)
            cin >> sky[i];

        int n_star = 0;
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                if (sky[i][j] == '*'){
                    int count = BFS(sky, i, j);
                    if (count == 1)
                        ++n_star;
                }

        cout << n_star << endl;
    }
    return 0;
}

int BFS(vector <string> & sky, int x, int y)
{
    int xs[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int ys[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    int count = 1;

    int r = sky.size();
    int c = sky[0].size();

    queue < pair <int, int> > Queue;
    sky[x][y] = '.';
    Queue.push(make_pair(x, y));

    while (!Queue.empty()) {
        pair <int, int> front = Queue.front();
        Queue.pop();

        for (int i = 0; i < 8; ++i){
            int x1 = front.first + xs[i];
            int y1 = front.second + ys[i];

            if (x1 >= 0 && x1 < r && y1 >= 0 && y1 < c)
                if (sky[x1][y1] == '*'){
                    Queue.push(make_pair(x1, y1));
                    sky[x1][y1] = '.';
                    ++count;
                }
        }
    }

    return count;
}

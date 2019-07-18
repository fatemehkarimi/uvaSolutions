//uva 11101
//Mall Mania

#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <deque>

using namespace std;

int BFS(vector <vector <int> > & malls, int x_start, int y_start);

int main(void)
{
    while(true){
        int m, n;
        cin >> m;

        if(m == 0)
            break;
        int size = 0;
        vector < pair <int, int> > mall1(m);
        for(int i = 0; i < m; ++i){
            cin >> mall1[i].first >> mall1[i].second;
            size = max(size, max(mall1[i].first, mall1[i].second));
        }

        cin >> n;
        vector < pair <int, int> > mall2(n);
        for(int i = 0; i < n; ++i){
            cin >> mall2[i].first >> mall2[i].second;
            size = max(size, max(mall2[i].first, mall2[i].second));
        }
        vector < vector <int> > malls(size + 1, vector <int>(size + 1, 0));

        for(int i = 0; i < m; ++i)
            malls[size - mall1[i].second][mall1[i].first] = 1;
        for(int i = 0; i < n; ++i)
            malls[size - mall2[i].second][mall2[i].first] = 2;

        int result = BFS(malls, size - mall1[0].second, mall1[0].first);
        cout << result << endl;
    }
    return 0;
}


int BFS(vector <vector <int> > & malls, int x_start, int y_start)
{
    int size = malls.size();
    int x_dir[] = {-1, 0, 1, 0};
    int y_dir[] = {0, -1, 0, 1};

    vector <vector <int> > visited(size, vector <int>(size, false));
    deque <pair <int, pair <int, int> > > Deque;

    Deque.push_back(make_pair(0, make_pair(x_start, y_start)));
    visited[x_start][y_start] = 1;

    while(!Deque.empty()){
        int level = Deque.front().first;
        int x = Deque.front().second.first;
        int y = Deque.front().second.second;
        Deque.pop_front();

        for(int i = 0; i < 4; ++i){
            int x_next = x + x_dir[i];
            int y_next = y + y_dir[i];

            if(x_next >= 0 && x_next < size && y_next >= 0 && y_next < size && !visited[x_next][y_next]){
                visited[x_next][y_next] = true;
                if(malls[x_next][y_next] == 1)
                    Deque.push_front(make_pair(0, make_pair(x_next, y_next)));
                else if(malls[x_next][y_next] == 2)
                    return level + 1;
                else
                    Deque.push_back(make_pair(level + 1, make_pair(x_next, y_next)));
            }
        }

    }
    return -1;
}


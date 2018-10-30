//uva 929
//Number Maze

#include <iostream>
#include <climits>
#include <vector>
#include <set>

using namespace std;

int Dijkstra(vector < vector <int> > & arr);

int main(void)
{
    int T = 0;
    cin >> T;
    while(T--){
        int n, m;
        cin >> n >> m;

        vector <vector <int> > arr(n, vector <int> (m));
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                cin >> arr[i][j];

        int result = Dijkstra(arr);
        cout << result << endl;
    }

    return 0;
}

int Dijkstra(vector < vector <int> > & arr)
{
    int n = arr.size();
    int m = arr[0].size();

    int xs[] = {-1, 0, 0, 1};
    int ys[] = {0, -1, 1, 0};

    vector <vector <int> > minWay(n, vector <int> (m, INT_MAX));
    minWay[0][0] = arr[0][0];

    set < pair<int, pair <int, int> > > visitedNodes;
    visitedNodes.insert(make_pair(arr[0][0], make_pair(0, 0)));

    while(!visitedNodes.empty()){
        pair <int, pair <int, int> > node = *visitedNodes.begin();
        visitedNodes.erase(node);

        int x = node.second.first;
        int y = node.second.second;
        int value = node.first;

        for(int i = 0; i < 4; ++i){
            int nx = x + xs[i];
            int ny = y + ys[i];

            if(nx >= 0 && nx < n && ny >= 0 && ny < m)
                if(value + arr[nx][ny] < minWay[nx][ny]){
                    if (visitedNodes.find(make_pair(minWay[nx][ny], make_pair(nx, ny))) != visitedNodes.end())
                        visitedNodes.erase(make_pair(minWay[nx][ny], make_pair(nx, ny)));

                    visitedNodes.insert(make_pair(value + arr[nx][ny], make_pair(nx, ny)));
                    minWay[nx][ny] = value + arr[nx][ny];
                }
        }
    }

    return minWay[n - 1][m - 1];
}

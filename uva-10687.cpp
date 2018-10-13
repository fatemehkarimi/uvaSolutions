//uva 10687
//Monitoring the Amazon

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

bool DFS(vector <vector <int> > & Graph, int start);
void DFS(vector <vector <int> > & Graph, vector <bool> & visited, int start);

int main(void)
{
    int n = 0;
    while (true) {
        cin >> n;

        if (n == 0)
            break;

        vector <pair <int, int> > num(n);

        for (int i = 0; i < n; ++i)
            cin >> num[i].first >> num[i].second;

        pair <int, int> start = num[0];

        sort(num.begin(), num.end());

        vector <vector <int> > Graph(n);

        for (int i = 0; i < n; ++i){
            set < pair<double, int> > dis;

            for (int j = 0; j < n; ++j)
                if (i != j){
                    double tmp = (num[i].first - num[j].first) * (num[i].first - num[j].first)
                    + (num[i].second - num[j].second) * (num[i].second - num[j].second);
                    tmp = sqrt(tmp);

                    dis.insert(make_pair(tmp, j));
                }

            auto a = dis.begin();
            Graph[i].push_back(a->second);
            ++a;
            Graph[i].push_back(a->second);
        }

        int s_index = 0;
        for (int i = 0; i < n; ++i)
            if (num[i] == start){
                s_index = i;
                break;
            }

        bool result = DFS(Graph, s_index);
        if (result)
            cout << "All stations are reachable." << endl;
        else
            cout << "There are stations that are unreachable." << endl;
    }

    return 0;
}


bool DFS(vector <vector <int> > & Graph, int start)
{
    int n = Graph.size();
    vector <bool> visited(n, 0);

    DFS(Graph, visited, start);
    bool result = 1;

    for (auto a : visited)
        result &= a;

    return result;
}

void DFS(vector <vector <int> > & Graph, vector <bool> & visited, int start)
{
    visited[start] = 1;
    for (auto a : Graph[start])
        if (!visited[a])
            DFS(Graph, visited, a);

    return;
}

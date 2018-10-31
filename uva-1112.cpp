//uva 1112
//Mice and Maze

#include <iostream>
#include <climits>
#include <vector>
#include <set>
#include <map>

using namespace std;

void Dijkstra(vector <map <int, int> > & Graph, vector <int> & minDis, int start);

int main(void)
{
    int T = 0;
    cin >> T;
    while(T--){
        int n, end, time;
        cin >> n >> end >> time;

        --end;

        int m;
        cin >> m;

        vector < map <int, int> > GraphT(n);

        for(int i = 0; i < m; ++i){
            int a, b, t;
            cin >> a >> b >> t;

            --a, --b;
            GraphT[b].insert(make_pair(a, t));
        }
        vector <int> minDis(n, INT_MAX);
        Dijkstra(GraphT, minDis, end);

        int count = 0;
        for(auto a : minDis)
            if (a <= time)
                ++count;

        cout << count << endl;
        if (T) cout << endl;
    }

    return 0;
}

void Dijkstra(vector <map <int, int> > & Graph, vector <int> & minDis, int start)
{
    minDis[start] = 0;
    set <pair <int, int> > unvisitedNode;
    unvisitedNode.insert(make_pair(0, start));

    while(!unvisitedNode.empty()){
        pair <int, int> top = *unvisitedNode.begin();
        unvisitedNode.erase(top);

        int node = top.second;
        int value = top.first;

        for(auto a : Graph[node]){
            if(value + a.second < minDis[a.first]){
                minDis[a.first] = value + a.second;
                unvisitedNode.insert(make_pair(minDis[a.first], a.first));
            }
        }
    }

    return;
}

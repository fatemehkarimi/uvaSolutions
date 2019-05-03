//uva 1174
//IP-TV

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

int Prim(map <string, vector < pair <string, int> > > & Graph);

int main(void)
{
    int T = 0;
    cin >> T;
    while(T--){
        int n, m;
        cin >> n >> m;

        map <string, vector < pair <string, int> > > Graph;
        for(int i = 0; i < m; ++i){
            string city1, city2;
            int cost;
            cin >> city1 >> city2 >> cost;

            Graph[city1].push_back(make_pair(city2, cost));
            Graph[city2].push_back(make_pair(city1, cost));
        }

        cout << Prim(Graph) << endl;
        if(T)
            cout << endl;
    }
    return 0;
}

int Prim(map <string, vector < pair <string, int> > > & Graph)
{
    map <string, bool> visited;
    for(auto a : Graph)
        visited[a.first] = false;

    int minCost = 0;
    set < pair <int, pair <string, string> > > Heap;
    string root = Graph.begin()->first;
    for(unsigned int i = 0; i < Graph[root].size(); ++i)
        Heap.insert(make_pair(Graph[root][i].second, make_pair(root, Graph[root][i].first)));
    visited[root] = true;

    while(!Heap.empty()){
        pair <int, pair <string, string> > minEdge = *Heap.begin();
        Heap.erase(Heap.begin());

        root = minEdge.second.second;

        if(!visited[root]){
            minCost += minEdge.first;
            visited[root] = true;
            for(unsigned int i = 0; i < Graph[root].size(); ++i)
                Heap.insert(make_pair(Graph[root][i].second, make_pair(root, Graph[root][i].first)));
        }
    }

    return minCost;
}

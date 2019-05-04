//uva 11733
//Airports

#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

pair <int, int> findMinCost(vector < map <int, int> > & Graph, int airport_c);

int main(void)
{
    int T = 0;
    int tcounter = 0;
    cin >> T;
    while(T--){
        ++tcounter;
        int n, m, airport_c;
        cin >> n >> m >> airport_c;

        vector < map <int, int> > Graph(n);
        for(int i = 0; i < m; ++i){
            int u, v, cost;
            cin >> u >> v >> cost;
            --u;
            --v;

            if(Graph[u].find(v) == Graph[u].end())
                Graph[u][v] = Graph[v][u] = cost;
            else
                Graph[u][v] = Graph[v][u] = min(Graph[u][v], cost);
        }

        pair <int, int> result = findMinCost(Graph, airport_c);
        cout << "Case #" << tcounter << ": " << result.first << ' ' << result.second << endl;
    }
    return 0;
}

pair <int, int> findMinCost(vector < map <int, int> > & Graph, int airport_c)
{
    int n = Graph.size();
    int minCost = 0;
    int count_airport = 0;
    vector <bool> visited(n, false);

    for(int i = 0; i < n; ++i){
        if(visited[i])
            continue;

        int root = i;
        set < pair <int, pair <int, int> > > Heap;
        visited[root] = true;
        ++count_airport;
        minCost += airport_c;
        for(auto a : Graph[root])
            Heap.insert(make_pair(a.second, make_pair(root, a.first)));

        while(!Heap.empty()){
            pair <int, pair <int, int> > edge = *Heap.begin();
            Heap.erase(Heap.begin());

            root = edge.second.second;
            if(!visited[root]){
                visited[root] = true;
                if(edge.first < airport_c)
                    minCost += edge.first;
                else{
                    minCost += airport_c;
                    ++count_airport;
                }
                for(auto a : Graph[root])
                    Heap.insert(make_pair(a.second, make_pair(root, a.first)));
            }
        }
    }

    return make_pair(minCost, count_airport);
}

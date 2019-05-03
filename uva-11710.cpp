//uva 11710
//Expensive subway

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

int Prim(map <string, map <string, int> > & Graph, string source);

int main(void)
{
    while(true){
        int s, c;
        cin >> s >> c;

        if(s == 0 && c == 0)
            break;

        map <string, map <string, int> > Graph;
        for(int i = 0; i < s; ++i){
            string station;
            cin >> station;
            map <string, int > edges;
            Graph[station] = edges;
        }

        for(int i = 0; i < c; ++i){
            string station1, station2;
            int cost;
            cin >> station1 >> station2 >> cost;
            Graph[station1].insert(make_pair(station2, cost));
            Graph[station2].insert(make_pair(station1, cost));
        }

        string source;
        cin >> source;

        int minCost = Prim(Graph, source);
        if(minCost == -1)
            cout << "Impossible" << endl;
        else
            cout << minCost << endl;
    }
    return 0;
}

int Prim(map <string, map <string, int> > & Graph, string source)
{
    map <string, bool> visited;
    for(auto a : Graph)
        visited[a.first] = false;

    int minCost = 0;
    set < pair <int, pair <string, string> > > Heap;
    for(auto edge : Graph[source])
        Heap.insert(make_pair(edge.second, make_pair(source, edge.first)));
    visited[source] = true;

    while(!Heap.empty()){
        pair <int, pair <string, string> > Edge = *Heap.begin();
        Heap.erase(Heap.begin());
        source = Edge.second.second;

        if(!visited[source]){
            visited[source] = true;
            minCost += Edge.first;
            for(auto edge : Graph[source])
                Heap.insert(make_pair(edge.second, make_pair(source, edge.first)));
        }
    }

    for(auto a : visited)//check if all stations are visited or not
        if(!a.second)
            return -1;

    return minCost;
}

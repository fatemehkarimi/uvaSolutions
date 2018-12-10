//uva 10147
//Highways

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <map>

using namespace std;

double dis(pair <int, int> a, pair <int, int> b);
void DFS(vector < vector <int> > & Graph, vector <int> & visited, int start, int code);
void Union(vector <int> & ufds, int a, int b);
int parent(vector <int> & ufds, int a);

int main(void)
{
    int T = 0;
    cin >> T;
    while(T--){
        int n;
        cin >> n;

        vector <pair <int, int> > cities(n);

        for(int i = 0; i < n; ++i)
            cin >> cities[i].first >> cities[i].second;

        int e;
        cin >> e;

        vector <vector <int> > Graph(n);

        for(int i = 0; i < e; ++i){
            int u, v;
            cin >> u >> v;

            --u, --v;

            Graph[u].push_back(v);
            Graph[v].push_back(u);
        }

        vector <int> connected_components(n, -1);
        int region = 0;

        for(int i = 0; i < n; ++i)
            if(connected_components[i] == -1)
                DFS(Graph, connected_components, i, region++);

        set < pair <double, pair <int, int> > > kruskalSet;
        map < pair <double, pair <int, int> >, pair <int, int> > realEdges;//inter component edges to inter node edges

        for(int i = 0; i < n; ++i)
            for(int j = i + 1; j < n; ++j){
                int u = connected_components[i];
                int v = connected_components[j];
                if(u != v){
                    double dst = dis(cities[i], cities[j]);
                    kruskalSet.insert(make_pair(dst, make_pair(u, v)));
                    realEdges[make_pair(dst, make_pair(u, v))] = make_pair(i, j);
                }
            }

        vector <pair <int, int> > added_highways;
        vector <int> ufds(region);
        for(int i = 0; i < region; ++i)
            ufds[i] = i;

        bool no_new_highway = 1;

        while(!kruskalSet.empty()){//connected_component is used as the set for kruskal algorithm
            auto edge = *kruskalSet.begin();
            int u = edge.second.first;
            int v = edge.second.second;

            kruskalSet.erase(kruskalSet.begin());

            if(parent(ufds, u) != parent(ufds, v)){
                Union(ufds, u, v);

                no_new_highway = 0;
                added_highways.push_back(realEdges[edge]);

            }
        }

        if(no_new_highway)
            cout << "No new highways need" << endl;
        else
            for(auto edge : added_highways)
                cout << edge.first + 1 << ' ' << edge.second + 1 << endl;

        if(T) cout << endl;
    }

    return 0;
}

void Union(vector <int> & ufds, int a, int b)
{
    int p1 = parent(ufds, a);
    int p2 = parent(ufds, b);

    ufds[p2] = p1;

    return;
}

int parent(vector <int> & ufds, int a)
{
    int x = a;
    while(x != ufds[x])
        x = ufds[x];

    while(a != ufds[a]){
        int tmp = ufds[a];
        ufds[a] = x;
        a = tmp;
    }

    return x;
}

double dis(pair <int, int> a, pair <int, int> b)
{
    int tmp = (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
    return sqrt(tmp);
}

void DFS(vector < vector <int> > & Graph, vector <int> & visited, int start, int code)
{
    visited[start] = code;

    for(auto a : Graph[start])
        if(visited[a] == -1)
            DFS(Graph, visited, a, code);

    return;
}

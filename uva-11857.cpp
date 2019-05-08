//uva 11857
//Driving Range

#include <iostream>
#include <climits>
#include <vector>
#include <set>

using namespace std;

int kruskal(set < pair <int, pair <int, int> > > & Edges, int n);
int findParent(vector <int> & ufds, int x);
void _union(vector <int> & ufds, int x, int y);

int main(void)
{
    int n, m;
    while(true){
        cin >> n >> m;

        if(n == 0 && m == 0)
            break;

        set < pair <int, pair <int, int> > > Edges;
        for(int i = 0; i < m; ++i){
            int u, v, cost;
            cin >> u >> v >> cost;
            Edges.insert(make_pair(cost, make_pair(u, v)));
        }

        int minEdge = kruskal(Edges, n);
        if(minEdge != -1)
            cout << minEdge << endl;
        else
            cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}

int kruskal(set < pair <int, pair <int, int> > > & Edges, int n)
{
    vector <int> ufds(n, -1);
    int minCostEdge = -1;
    while(!Edges.empty()){
        int cost = Edges.begin()->first;
        int u = Edges.begin()->second.first;
        int v = Edges.begin()->second.second;
        Edges.erase(Edges.begin());

        if(findParent(ufds, u) != findParent(ufds, v)){
            _union(ufds, u, v);
            minCostEdge = max(minCostEdge, cost);
        }
    }

    bool root_found = 0;
    
    for(auto a : ufds)
        if(a == -1 && !root_found)//one root is noly allowed
            root_found = 1;
        else if(a == -1 && root_found)
            return -1;

    return minCostEdge;
}

int findParent(vector <int> & ufds, int x)
{
    int root = x;
    while(ufds[root] != -1)
        root = ufds[root];
    while(ufds[x] != -1){
        int tmp = ufds[x];
        ufds[x] = root;
        x = tmp;
    }
    return root;
}

void _union(vector <int> & ufds, int x, int y)
{
    int p1 = findParent(ufds, x);
    int p2 = findParent(ufds, y);
    ufds[p2] = p1;
    return;
}

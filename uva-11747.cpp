//uva 11747
//Heavy Cycle Edges

#include <iostream>
#include <vector>
#include <set>

using namespace std;

void _union(vector <int> & ufds, int x, int y);
int findParent(vector <int> & ufds, int x);
void kruskal(set <pair <int, pair <int, int> > > & Edges, set <int> & removedEdges, int n_nodes);

int main(void)
{
    int n, m;
    while(true){
        cin >> n >> m;
        if(n == 0 && m == 0)
            break;

        set <pair <int, pair <int, int> > > edges;
        for(int i = 0; i < m; ++i){
            int u, v, cost;
            cin >> u >> v >> cost;
            edges.insert(make_pair(cost, make_pair(u, v)));
        }

        set <int> removedEdges;
        kruskal(edges, removedEdges, n);

        //printing result
        if(removedEdges.empty())
            cout << "forest" << endl;
        else{
            auto a = removedEdges.begin();
            cout << *a;
            ++a;
            for(; a != removedEdges.end(); ++a)
                cout << ' ' << *a;
            cout << endl;
        }
    }
    return 0;
}

void kruskal(set <pair <int, pair <int, int> > > & Edges, set <int> & removedEdges, int n_nodes)
{
    vector <int> ufds(n_nodes, -1);
    while(!Edges.empty()){
        int value = Edges.begin()->first;
        int u = Edges.begin()->second.first;
        int v = Edges.begin()->second.second;
        Edges.erase(Edges.begin());

        if(findParent(ufds, u) != findParent(ufds, v))
            _union(ufds, u, v);
        else
            removedEdges.insert(value);
    }
    return;
}

int findParent(vector <int> & ufds, int x)
{
    int root = x;
    while(ufds[root] != -1)
        root = ufds[root];

    while(ufds[x] != -1){
        int tmp = x;
        x = ufds[x];
        ufds[tmp] = root;
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

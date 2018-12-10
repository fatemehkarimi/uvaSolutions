//uva 908
//Re-connecting Computer Sites

#include <iostream>
#include <vector>
#include <set>

using namespace std;

int parent(vector <int> & ufds, int a);
void Union(vector <int> & ufds, int a, int b);

int main(void)
{
    int n = 0;
    bool first = 1;
    while(cin >> n){
        if(!first)
            cout << endl;
        first = 0;

        int preCost = 0;

        for(int i = 1; i < n; ++i){
            int x, y, cost;
            cin >> x >> y >> cost;

            preCost += cost;
        }

        set < pair <int, pair <int, int> > > kruskalSet;

        int k = 0;
        cin >> k;

        for(int i = 0; i < k; ++i){
            int u, v, cost;
            cin >> u >> v >> cost;

            kruskalSet.insert(make_pair(cost, make_pair(u, v)));
        }

        int m = 0;
        cin >> m;

        for(int i = 0; i < m; ++i){
            int u, v, cost;
            cin >> u >> v >> cost;

            kruskalSet.insert(make_pair(cost, make_pair(u, v)));
        }

        int size = kruskalSet.size();
        vector <int> ufds(size, -1);
        int newCost = 0;

        while(!kruskalSet.empty()){
            int cost = kruskalSet.begin()->first;
            int u = kruskalSet.begin()->second.first;
            int v = kruskalSet.begin()->second.second;

            kruskalSet.erase(kruskalSet.begin());

            if(parent(ufds, u) != parent(ufds, v)){
                Union(ufds, u, v);
                newCost += cost;
            }
        }

        cout << preCost << endl;
        cout << newCost << endl;
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
    while(ufds[x] != -1)
        x = ufds[x];

    while(ufds[a] != -1){
        int tmp = ufds[a];
        ufds[a] = x;
        a = tmp;
    }

    return x;
}

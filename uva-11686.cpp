//uva 11686
//Pick up sticks

#include <iostream>
#include <vector>
#include <set>

using namespace std;

bool topologicalSort(vector < vector <int> > & Graph, vector <int> & incommingEdge, vector <int> & order);

int main(void)
{
    int n, m;
    while(true){
        cin >> n >> m;

        if(n == 0 && m == 0) break;

        vector < vector <int> > Graph(n);
        vector <int> incommingEdge(n, 0);

        for(int i = 0; i < m; ++i){
            int u, v;
            cin >> u >> v;
            --u, --v;

            Graph[u].push_back(v);
            ++incommingEdge[v];
        }

        vector <int> order;
        bool result = topologicalSort(Graph, incommingEdge, order);
        if(result == false)
            cout << "IMPOSSIBLE" << endl;
        else
            for (auto a : order)
                cout << a + 1 << endl;

    }
    return 0;
}

bool topologicalSort(vector < vector <int> > & Graph, vector <int> & incommingEdge, vector <int> & order)
{
    int n = Graph.size();
    set < pair <int, int> > Heap;
    bool possible = 1;

    for(int i = 0; i < n; ++i)
        Heap.insert(make_pair(incommingEdge[i], i));

    while(!Heap.empty()){
        pair <int, int> front = *Heap.begin();
        Heap.erase(front);

        if(front.first != 0){
            possible = 0;
            break;
        }

        order.push_back(front.second);

        for(auto a : Graph[front.second]){
            Heap.erase(make_pair(incommingEdge[a], a));
            --incommingEdge[a];
            Heap.insert(make_pair(incommingEdge[a], a));
        }
    }

    if(!possible) return false; 
    return true;
}

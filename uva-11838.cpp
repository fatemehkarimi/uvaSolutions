//uva 11838
//Come and Go

#include <iostream>
#include <vector>
#include <stack>
#include <set>

using namespace std;

void dfs(vector < set <int> > & Graph, vector <int> & ids, vector <int> & low_link, vector <bool> & onStack, stack <int> & Stack, int start, int & count);

int main(void)
{
    int n, m;
    while(true){
        cin >> n >> m;

        if(n == 0 && m == 0)
            break;

        vector < set <int> > Graph(n);

        for(int i = 0; i < m; ++i){
            int v, w, p;
            cin >> v >> w >> p;

            --v, --w;

            Graph[v].insert(w);

            if(p == 2)
                Graph[w].insert(v);
        }
        
        //Tarjan algorithm
        vector <int> ids(n, -1);
        vector <int> low_link(n, 0);
        vector <bool> onStack(n, false);
        stack <int> Stack;

        int count_component = 0;
        for(int i = 0; i < n; ++i)
            if(ids[i] == -1)
                dfs(Graph, ids, low_link, onStack, Stack, i, count_component);

        cout << (count_component == 1 ? 1 : 0) << endl;
    }
    return 0;
}

void dfs(vector < set <int> > & Graph, vector <int> & ids, vector <int> & low_link, vector <bool> & onStack, stack <int> & Stack, int start, int & count)
{
    static int id = 0;

    Stack.push(start);
    onStack[start] = true;
    ids[start] = low_link[start] = id++;

    for(auto node : Graph[start]){
        if(ids[node] == -1)
            dfs(Graph, ids, low_link, onStack, Stack, node, count);
        if(onStack[node])
            low_link[start] = min(low_link[start], low_link[node]);
    }

    if(ids[start]  == low_link[start]){
        while(true){
            int node = Stack.top();
            Stack.pop();
            onStack[node] = false;
            low_link[node] = low_link[start];

            if(node == start)
                break;
        }
        ++count;
    }
    return;
}

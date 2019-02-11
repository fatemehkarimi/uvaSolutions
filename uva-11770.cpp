//uva 11770
//Lighting Away

#include <iostream>
#include <vector>
#include <stack>
#include <set>

using namespace std;

void dfs(vector < set <int> > & Graph, int start, vector <int> & visited, stack <int> & Stack);
void find_component(vector < set <int> > & Graph, int start, vector <int> & visited);

int main(void)
{
    int T = 0;
    cin >> T;
    int tcounter = 0;

    while(T--){
        int n, m;
        cin >> n >> m;

        vector < set <int> > Graph(n);
        vector < set <int> > TGraph(n);

        ++tcounter;

        for(int i = 0; i < m; ++i){
            int u, v;
            cin >> u >> v;

            --u, --v;

            Graph[u].insert(v);
            TGraph[v].insert(u);
        }

        stack <int> order;
        vector <int> visited(n, false);
        for(int i = 0; i < n; ++i)
            if(!visited[i])
                dfs(Graph, i, visited, order);

        for(int & a : visited)
            a = 0;

        int num_components = 0;
        while(!order.empty()){
            int top = order.top();
            order.pop();

            if(!visited[top]){
                find_component(Graph, top, visited);
                ++num_components;
            }

        }

        cout << "Case " << tcounter << ": " << num_components << endl;
    }
    return 0;
}

void dfs(vector < set <int> > & Graph, int start, vector <int> & visited, stack <int> & Stack)
{
    visited[start] = true;
    for(auto a : Graph[start])
        if(!visited[a])
            dfs(Graph, a, visited, Stack);

    Stack.push(start);
    return;
}

void find_component(vector < set <int> > & Graph, int start, vector <int> & visited)
{
    visited[start] = true;
    for(auto a : Graph[start])
        if(!visited[a])
            find_component(Graph, a, visited);

    return;
}

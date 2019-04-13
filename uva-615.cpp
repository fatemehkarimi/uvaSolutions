//uva 615
//Is It A Tree?

#include <iostream>
#include <vector>
#include <map>

using namespace std;

void dfs(map <int, vector <int> > & Tree, int root, map <int, bool> & visited);

int main(void)
{
    int tcounter = 0;
    while(true){
        int u, v;
        map <int, vector <int> > Tree;
        map <int, int> incomming_edge;
        bool terminate = false;

        while(true){
            cin >> u >> v;

            if(u == 0 && v == 0)
                break;

            if(u < 0 && v < 0){
                terminate = true;
                break;
            }

            if(incomming_edge.find(u) == incomming_edge.end())
                incomming_edge[u] = 0;

            Tree[u].push_back(v);
            incomming_edge[v]++;
        }

        if(terminate)
            break;
        ++tcounter;

        int root = -1;
        bool is_tree = true;

        for(auto a : incomming_edge)
            if(a.second == 0 && root == -1)
                root = a.first;
            else if(a.second == 0 && root != -1){
                is_tree = false;
                break;
            }
            else if(a.second != 1){
                is_tree = false;
                break;
            }

        map <int, bool> visited;
        for(auto a : incomming_edge)
            visited[a.first] = false;

        dfs(Tree, root, visited);

        for(auto a : visited)
            if(a.second == false){
                is_tree = false;
                break;
            }

        cout << "Case " << tcounter;
        if(is_tree)
            cout << " is a tree." << endl;
        else
            cout << " is not a tree." << endl;

    }
    return 0;
}

void dfs(map <int, vector <int> > & Tree, int root, map <int, bool> & visited)
{
    visited[root] = true;
    for(auto a : Tree[root])
        if(!visited[a])
            dfs(Tree, a, visited);
    return;
}

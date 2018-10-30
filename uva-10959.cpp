//uva 10959
//The Party, Part I

#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <queue>

using namespace std;

void BFS(vector <set <int> > & Graph, vector <int> & level);

int main(void)
{
    int T = 0;
    cin >> T;
    while(T--){
        int p, d;
        cin >> p >> d;
        
        vector < set <int> > Graph(p);

        for(int i = 0; i < d; ++i){
            int a, b;
            cin >> a >> b;

            Graph[a].insert(b);
            Graph[b].insert(a);
        }

        vector <int> level(p, INT_MAX);
        BFS(Graph, level);

        for(int i = 1; i < p; ++i)
            cout << level[i] << endl;

        if(T) cout << endl;
    }
    return 0;
}

void BFS(vector <set <int> > & Graph, vector <int> & level)
{
    vector <bool> visited(Graph.size(), false);
    queue <int> Queue;
    Queue.push(0);
    visited[0] = 1;
    level[0] = 0;

    while(!Queue.empty()){
        int front = Queue.front();
        Queue.pop();

        for(auto a : Graph[front])
            if (!visited[a]){
                Queue.push(a);
                visited[a] = 1;
                level[a] = min(level[a], level[front] + 1);
            }
    }
    return;
}

//uva 1148
//The mysterious X network

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void BFS(vector < vector <int> > & Graph, vector <int> & levels, int s);

int main(void)
{
    int T = 0;
    cin >> T;
    while(T--) {
        int n = 0;
        cin >> n;

        vector <vector <int> > Graph(n);
        for(int i = 0; i < n; ++i){
            int s, c;
            cin >> s >> c;

            for(int j = 0; j < c; ++j){
                int tmp;
                cin >> tmp;
                Graph[s].push_back(tmp);
            }
        }

        int s, d;
        cin >> s >> d;

        vector <int> levels(n);
        BFS(Graph, levels, s);

        cout << s << ' ' << d << ' ' << levels[d] - 1 << endl;
        if(T) cout << endl;
    }
    return 0;
}

void BFS(vector < vector <int> > & Graph, vector <int> & levels, int s)
{
    vector <bool> visited(Graph.size(), false);
    visited[s] = 1;

    queue <int> Queue;
    Queue.push(s);
    levels[s] = 0;

    while(!Queue.empty()){
        int front = Queue.front();
        Queue.pop();

        for (auto a : Graph[front])
            if(!visited[a]){
                visited[a] = 1;
                Queue.push(a);
                levels[a] = levels[front] + 1;
            }
    }

    return;
}

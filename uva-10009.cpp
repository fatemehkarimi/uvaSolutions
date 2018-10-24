//uva 10009
//All Roads Lead Where?

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

string BFS(map <char, vector <char> > & Graph, char c1, char c2);

int main(void)
{
    int T = 0;
    cin >> T;
    while(T--) {
        int m, q;//number of edges, number of queries
        cin >> m >> q;

        map <char, vector <char> > Graph;
        for (int i = 0; i < m; ++i){
            string t1, t2;
            cin >> t1 >> t2;

            Graph[t1[0]].push_back(t2[0]);
            Graph[t2[0]].push_back(t1[0]);
        }

        while (q--){
            string c1, c2;
            cin >> c1 >> c2;

            string result = BFS(Graph, c1[0], c2[0]);
            cout << result << endl;
        }

        if (T)
            cout << endl;
    }
    return 0;
}

string BFS(map <char, vector <char> > & Graph, char c1, char c2)
{
    map <char, char> parent;
    map <char, bool> visited;
    queue <char> Queue;

    Queue.push(c1);
    visited[c1] = 1;
    parent[c1] = ' ';

    while (!Queue.empty()){
        char front = Queue.front();
        Queue.pop();

        for(auto a : Graph[front])
            if (!visited[a]){
                visited[a] = 1;
                Queue.push(a);
                parent[a] = front;
            }
    }

    string result;
    do {
        result = c2 + result;
        c2 = parent[c2];
    }while (c2 != ' ');

    return result;
}

//uva 383
//Shipping Routes

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>

using namespace std;

int BFS(map <string, vector <string> > & Graph, string s, string d);

int main(void)
{
    int T = 0;
    cin >> T;
    cout << "SHIPPING ROUTES OUTPUT" << endl;

    for (int tcounter = 1; tcounter <= T; ++tcounter){
        int m, n, p;
        cin >> m >> n >> p;

        map <string, vector <string> > Graph;
        for (int i = 0; i < m; ++i){
            string input;
            cin >> input;
            vector <string> tmp;

            Graph.insert(make_pair(input, tmp));
        }

        for (int i = 0; i < n; ++i){
            string t1, t2;
            cin >> t1 >> t2;

            Graph[t1].push_back(t2);
            Graph[t2].push_back(t1);
        }

        cout << endl << "DATA SET  " << tcounter << endl << endl;
        for (int i = 0; i < p; ++i){
            int l;
            string s, d;
            cin >> l >> s >> d;

            int leg = BFS(Graph, s, d);
            if (leg == -1)
                cout << "NO SHIPMENT POSSIBLE" << endl;
            else
                cout << '$' << l * leg * 100 << endl;
        }
    }

    cout << endl << "END OF OUTPUT" << endl;
    return 0;
}


int BFS(map <string, vector <string> > & Graph, string s, string d)
{
    map <string, int> visited;
    for (auto a : Graph)
        visited[a.first] = -1;

    queue <string> Queue;
    Queue.push(s);
    visited[s] = 0;

    while(!Queue.empty()){
        string front = Queue.front();
        Queue.pop();

        for (auto a : Graph[front])
            if (visited[a] == -1){
                visited[a] = visited[front] + 1;
                Queue.push(a);
            }
    }

    return visited[d];
}

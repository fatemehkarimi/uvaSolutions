//uva 627
//The Net

#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

vector <int> BFS(vector <vector <int> > & Graph, int s, int d);

int main(void)
{
    int n;
    while(cin >> n){
        vector <vector <int> > Graph(n);

        for(int i = 0; i < n; ++i){
            string input;
            cin >> input;

            int root = 0;
            int index = 0;
            for(index = 0; input[index] != '-'; ++index)
                root = root * 10 + (input[index] - '0');

            for (++index; index < input.size(); ++index){
                int num = 0;
                while(index < input.size() && input[index] != ','){
                    num = num * 10 + input[index] - '0';
                    ++index;
                }

                if (num != 0)
                    Graph[root - 1].push_back(num - 1);
            }
        }

        int q;
        cin >> q;
        cout << "-----" << endl;
        for(int i = 0; i < q; ++i){
            int s, d;
            cin >> s >> d;
            --s;
            --d;

            vector <int> result = BFS(Graph, s, d);

            if (result.empty())
                cout << "connection impossible" << endl;
            else{
                cout << result[result.size() - 1] + 1;
                for (int j = result.size() - 2; j >= 0; --j)
                    cout << ' ' << result[j] + 1;

                cout << endl;
            }
        }
    }
    return 0;
}

vector <int> BFS(vector <vector <int> > & Graph, int s, int d)
{
    vector <bool> visited(Graph.size(), false);
    vector <int> parent(Graph.size(), 1000);

    queue <int> Queue;
    Queue.push(s);
    visited[s] = 1;

    while(!Queue.empty()){
        int front = Queue.front();
        Queue.pop();

        for(auto a : Graph[front])
            if (!visited[a]){
                visited[a] = 1;
                parent[a] = min(parent[a], front);
                Queue.push(a);
            }
    }

    vector <int> result;
    if (parent[d] == 1000)
        return result;

    while(d != 1000){
        result.push_back(d);
        d = parent[d];
    }

    return result;
}

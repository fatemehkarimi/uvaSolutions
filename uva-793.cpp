//uva 793
//Network Connections

#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <queue>

using namespace std;

bool BFS(vector < vector <int> > & Graph, int start, int goal);

int main(void)
{
    int T = 0;
    cin >> T;

    while (T--) {
        int n_node = 0;
        cin >> n_node;

        getchar();
        string input;
        int True = 0, False = 0;
        vector < vector <int> > Graph(n_node);

        while (true){
            getline(cin, input);

            if (input == "")
                break;

            char order;
            int comp1, comp2;
            stringstream stream(input);
            stream >> order >> comp1 >> comp2;

            --comp1;
            --comp2;


            if (order == 'c'){
                if (find(Graph[comp1].begin(), Graph[comp1].end(), comp2) == Graph[comp1].end()){
                    Graph[comp1].push_back(comp2);
                    Graph[comp2].push_back(comp1);
                }
            }
            else if (order == 'q'){
                if (BFS(Graph, comp1, comp2))
                    ++True;
                else
                    ++False;
            }
        }

        cout << True << "," << False << endl;
        if (T)
            cout << endl;
    }
    return 0;
}

bool BFS(vector < vector <int> > & Graph, int start, int goal)
{
    queue <int> Queue;
    vector <bool> visited(Graph.size(), false);

    Queue.push(start);
    visited[start] = true;

    while (!Queue.empty()){
        int front = Queue.front();
        Queue.pop();

        for (auto a : Graph[front])
            if (!visited[a]){
                visited[a] = true;
                Queue.push(a);
            }

        if (visited[goal])
            return true;
    }

    return false;
}

//uva 10308
//Roads in the North

#include <iostream>
#include <string>
#include <sstream>
#include <queue>
#include <map>

using namespace std;

void bfs(map <int, vector <pair <int, int> > > & Graph, map <int, int> & costs, int root);

int main(void)
{
    string input;
    while(getline(std::cin, input)){
        map <int, vector <pair <int, int> > > Graph;

        while(true){
            int u, v, value;
            stringstream stream(input);
            stream >> u >> v >> value;

            Graph[u].push_back(make_pair(v, value));
            Graph[v].push_back(make_pair(u, value));

            getline(std::cin, input);
            if(input == "")
                break;
        }

        int root = Graph.begin()->first;
        map <int, int> costs;
        bfs(Graph, costs, root);

        int node_with_max_cost = root;
        for(auto a : costs)
            if(costs[node_with_max_cost] < a.second)
                node_with_max_cost = a.first;

        bfs(Graph, costs, node_with_max_cost);
        int farthest_cost = costs[root];
        for(auto a : costs)
            farthest_cost = max(farthest_cost, a.second);

        cout << farthest_cost << endl;
    }
    return 0;
}

void bfs(map <int, vector <pair <int, int> > > & Graph, map <int, int> & costs, int root)
{
    map <int, bool> visited;
    queue <int> Queue;
    Queue.push(root);
    costs[root] = 0;
    visited[root] = true;

    while(!Queue.empty()){
        int top = Queue.front();
        Queue.pop();

        for(auto a : Graph[top])
            if(!visited[a.first]){
                visited[a.first] = true;
                costs[a.first] = costs[top] + a.second;
                Queue.push(a.first);
            }
    }

    return;
}

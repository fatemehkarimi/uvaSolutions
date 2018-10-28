//uva 762
//We Ship Cheap

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>

using namespace std;

vector <pair <string, string> > BFS(map <string, vector <string> > & Graph, string s, string d);

int main(void)
{
    int n = 0;
    bool first = 1;

    while(cin >> n){
        if(first)
            first = 0;
        else
            cout << endl;

        map <string, vector <string> > Graph;

        for (int i = 0; i < n; ++i){
            string a, b;
            cin >> a >> b;

            Graph[a].push_back(b);
            Graph[b].push_back(a);
        }

        string s, d;
        cin >> s >> d;

        vector <pair<string, string> > result = BFS(Graph, s, d);
        if(result.size() == 0)
            cout << "No route" << endl;
        else
            for(auto a = result.rbegin(); a != result.rend(); ++a)
                cout << a->first << ' ' << a->second << endl;

    }
    return 0;
}

vector <pair <string, string> > BFS(map <string, vector <string> > & Graph, string s, string d)
{
    map <string, string> parent;
    map <string, bool> visited;

    for(auto a : Graph){
        parent.insert(make_pair(a.first, ""));
        visited.insert(make_pair(a.first, 0));
    }

    queue <string> Queue;
    Queue.push(s);
    visited[s] = 1;

    while(!Queue.empty()){
        string front = Queue.front();
        Queue.pop();

        for(auto a : Graph[front])
            if(!visited[a]){
                visited[a] = 1;
                Queue.push(a);
                parent[a] = front;
            }
    }

    vector < pair<string, string> > result;
    if(parent[d] == "")
        return result;

    while(d != ""){
        string par = parent[d];
        if(par != "")
            result.push_back(make_pair(par, d));
        d = par;
    }
    return result;
}

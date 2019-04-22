//uva 10459
//The Tree Root

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <set>

using namespace std;

int bfs(vector <vector <int> > & Tree, vector <int> & visited, vector <int> & pre, int root);

int main(void)
{
    int n = 0;
    while(cin >> n){
        vector <vector <int> > Tree(n);
        set <int> best_root;
        set <int> worst_root;

        for(int i = 0; i < n; ++i){
            int count = 0;
            cin >> count;

            for(int j = 0; j < count; ++j){
                int v;
                cin >> v;
                Tree[i].push_back(v - 1);
            }
        }

        int root = 0;
        vector <int> visited(n, 0);
        vector <int> pre(n, -1);
        int max_level = bfs(Tree, visited, pre, root);

        int farthest = 0;//next root in the BFS
        for(int i = 0; i < n; ++i)
            if(visited[i] == max_level){
                farthest = i;
                break;
            }

        std::fill(visited.begin(), visited.end(), 0);
        std::fill(pre.begin(), pre.end(), -1);
        max_level = bfs(Tree, visited, pre, farthest);

        farthest = 0;
        for(int i = 0; i < n; ++i)//finding farthest node in the second BFS
            if(visited[i] == max_level){
                farthest = i;
                break;
            }

        stack <int> path;
        while(farthest != -1){
            path.push(farthest);
            farthest = pre[farthest];
        }

        int index = 0;
        int path_size = path.size();

        while(!path.empty()){
            if(path_size % 2 && index == (path_size / 2))//middle nodes are the best roots
                best_root.insert(path.top());
            else if(path_size % 2 == 0 && (index == path_size / 2 || index == path_size / 2 - 1))
                best_root.insert(path.top());

            ++index;
            path.pop();
        }

        for(auto root : best_root){
            std::fill(visited.begin(), visited.end(), 0);
            max_level = bfs(Tree, visited, pre, root);
            for(int i = 0; i < n; ++i)
                if(visited[i] == max_level)
                    worst_root.insert(i);
        }

        cout << "Best Roots  :";
        for(auto a : best_root)
            cout << ' ' << a + 1;
        cout << endl;

        cout << "Worst Roots :";
        for(auto a : worst_root)
            cout << ' ' << a + 1;
        cout << endl;
    }
    return 0;
}

int bfs(vector <vector <int> > & Tree, vector <int> & visited, vector <int> & pre, int root)
{
    queue <int> Queue;
    int level = 1;
    visited[root] = 1;
    Queue.push(root);
    while(!Queue.empty()){
        int front = Queue.front();
        Queue.pop();

        for(auto a : Tree[front])
            if(!visited[a]){
                visited[a] = visited[front] + 1;
                level = max(visited[a], level);
                pre[a] = front;
                Queue.push(a);
            }
    }
    return level;
}


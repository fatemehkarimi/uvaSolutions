//uva 331
//Mapping the Swaps

#include <iostream>
#include <climits>
#include <vector>
#include <queue>

using namespace std;

void BFS(vector <vector <int> > & Graph, vector <int> & level);

int main(void)
{
    int n = 0;
    int tcounter = 0;
    while(true){
        cin >> n;

        if(n == 0)
            break;

        ++tcounter;

        vector <int> num(n);
        for(int i = 0; i < n; ++i)
            cin >> num[i];

        if(n == 1){
            cout << "There are 0 swap maps for input data set " << tcounter << '.' << endl;
            continue;
        }

        vector <vector <int> > Graph;
        vector < vector <int> > states;
        states.push_back(num);

        for(int i = 0; i < states.size(); ++i){
            vector <int> edge_i;
            for(int j = 0; j < n - 1; ++j){
                if(states[i][j] > states[i][j + 1]){
                    vector <int> new_state = states[i];
                    new_state[j] = states[i][j + 1];
                    new_state[j + 1] = states[i][j];

                    states.push_back(new_state);
                    edge_i.push_back(states.size() - 1);
                }

                Graph.push_back(edge_i);
            }
        }
        
        vector <int> level(states.size(), INT_MAX);
        BFS(Graph, level);
        int min_set_size = INT_MAX;
        int n_min_set = 0;

        for(int i = 0; i < states.size(); ++i){
            bool sorted = true;
            for(int j = 0; j < n - 1; ++j)
                if(states[i][j] > states[i][j + 1])
                    sorted = false;

                if(sorted){
                    if(level[i] == min_set_size)
                        ++n_min_set;
                    else if (level[i] < min_set_size){
                        min_set_size = level[i];
                        n_min_set = 1;
                    }
                }
        }
 
        if(min_set_size == 0)//array is currently sorted
            n_min_set = 0;

        cout << "There are " << n_min_set << " swap maps for input data set " << tcounter << "." << endl;
    }

    return 0;
}

void BFS(vector <vector <int> > & Graph, vector <int> & level)
{
    int n = Graph.size();
    vector <bool> visited(n, false);
    queue <int> Queue;
    Queue.push(0);
    visited[0] = 1;
    level[0] = 0;


    while(!Queue.empty()){
        int front = Queue.front();
        Queue.pop();

        for(auto a : Graph[front])
            if(!visited[a]){
                visited[a] = true;
                level[a] = level[front] + 1;
                Queue.push(a);
            }
    }

    return;
}

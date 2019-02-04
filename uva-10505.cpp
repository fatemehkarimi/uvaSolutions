//uva 10505
//Montesco vs Capuleto

#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int max_possible_people(vector < set <int> > & Graph, vector <bool> & visited, int start);

int main(void)
{
    int T = 0;
    cin >> T;
    while(T--){
        int n = 0;
        cin >> n;

        vector < set <int> > Graph(n);

        for(int i = 0; i < n; ++i){
            int nn;
            cin >> nn;

            for(int j = 0; j < nn; ++j){
                int tmp;
                cin >> tmp;
                --tmp;
                if(tmp >= n) continue;//invalid input

                Graph[i].insert(tmp);
                Graph[tmp].insert(i);
            }
        }

        int numOfPeople = 0;
        vector <bool> visited(n, false);
        for(int i = 0; i < n; ++i)
            if(!visited[i]){
                numOfPeople += max_possible_people(Graph, visited, i);
            }

        cout << numOfPeople << endl;
    }
    return 0;
}


int max_possible_people(vector < set <int> > & Graph, vector <bool> & visited, int start)
{
    bool bipartite = 0;
    int n = Graph.size();
    int count0 = 0, count1 = 0;
    vector <bool> colored(n, false);

    queue <int> Queue;
    visited[start] = 1;
    Queue.push(start);
    ++count0;//starting node has color 0

    while(!Queue.empty()){
        int front = Queue.front();
        Queue.pop();

        for(auto a : Graph[front])
            if(visited[a] && colored[a] == colored[front])
                bipartite = 1;
            else if(!visited[a]){
                visited[a] = 1;
                colored[a] = !colored[front];
                colored[a] == 1 ? ++count1 : ++count0;
                Queue.push(a);
            }

    }

    if(bipartite) return 0;
    return max(count0, count1);
}

//uva 388
//Galactic Import

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <climits>
#include <cmath>

using namespace std;

void BFS(map <char, vector <char> > & Graph, map <char, int> & levels);

int main(void)
{
    int n;
    while(cin >> n){
        map <char, vector <char> > Graph;//* indicates earth
        map <char, double> values;

        for(int i = 0; i < n; ++i){
            char p;
            cin >> p;
            double value;
            cin >> value;

            values[p] = value;

            string ways;
            cin >> ways;

            for(auto a : ways){
                Graph[p].push_back(a);

                if(a == '*')
                    Graph[a].push_back(p);
            }
        }

        double max_profit = 0;
        char max_planet;

        map <char, int> levels;
        BFS(Graph, levels);

        for(auto a : levels){
            double profit = values[a.first];
            if (a.second >= 1)
                profit = (double)values[a.first] - (double)values[a.first] * (.05) * (1 - pow(.05, a.second - 1)) / (.95);

            if (profit > max_profit){
                max_profit = profit;
                max_planet = a.first;
            }
        }

        cout << "Import from " << max_planet << endl;
    }

    return 0;
}

void BFS(map <char, vector <char> > & Graph, map <char, int> & levels)
{
    map <char, bool> visited;
    queue <char> Queue;

    visited['*'] = 1;
    Queue.push('*');
    levels['*'] = 0;

    while(!Queue.empty()){
        char front = Queue.front();
        Queue.pop();

        for(auto a : Graph[front])
            if(!visited[a]){
                visited[a] = 1;
                Queue.push(a);
                levels[a] = levels[front] + 1;
            }
    }

    return;
}

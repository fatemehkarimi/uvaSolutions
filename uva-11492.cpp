//uva 11492
//Babel

#include <iostream>
#include <climits>
#include <string>
#include <map>
#include <set>

using namespace std;

int Dijkstra(map <string, map <string, map <char, int> > > & Graph, string source, string destination);

int main(void)
{
    int m;
    while(cin >> m, m){
        string source, destination;
        cin >> source >> destination;

        map <string, map <string, map <char, int> > > Graph;
        for(int i = 0; i < m; ++i){
            string lan1, lan2, word;
            cin >> lan1 >> lan2 >> word;
            if(Graph[lan1][lan2].find(word[0]) == Graph[lan1][lan2].end()){
                Graph[lan1][lan2].insert(make_pair(word[0], word.size()));
                Graph[lan2][lan1].insert(make_pair(word[0], word.size()));
            }
            else
                Graph[lan1][lan2][word[0]] = Graph[lan2][lan1][word[0]] = min(Graph[lan1][lan2][word[0]], (int)word.size());
        }

        int result = Dijkstra(Graph, source, destination);
        if(result == INT_MAX)
            cout << "impossivel" << endl;
        else
            cout << result << endl;
    }
    return 0;
}

int Dijkstra(map <string, map <string, map <char, int> > > & Graph, string source, string destination)
{
    map <string, map <char, int> > min_cost;
    set < pair < pair <int, char> , string> > Heap;

    for(auto a : Graph)
        for(auto b : a.second)
            for(auto c : b.second)
            min_cost[a.first][c.first] = INT_MAX;

    for(auto a : Graph[source])
        for(auto b : a.second){
            min_cost[a.first][b.first] = b.second;
            Heap.insert(make_pair(make_pair(b.second, b.first), a.first));
        }

    while(!Heap.empty()){
        int cost = Heap.begin()->first.first;
        char word_start1 = Heap.begin()->first.second;
        string lan1 = Heap.begin()->second;

        Heap.erase(Heap.begin());

        for(auto neighbor : Graph[lan1]){
            string lan2 = neighbor.first;
            for(auto word : neighbor.second){
                char word_start2 = word.first;
                int word_len = word.second;

                if(word_start1 != word_start2 && cost + word_len < min_cost[lan2][word_start2]){
                    Heap.erase(make_pair(make_pair(min_cost[lan2][word_start2], word_start2), lan2));
                    min_cost[lan2][word_start2] = cost + word_len;
                    Heap.insert(make_pair(make_pair(min_cost[lan2][word_start2], word_start2), lan2));
                }
            }
        }
    }
    
    if(min_cost.find(destination) == min_cost.end())
        return INT_MAX;
    int result = INT_MAX;
    for(auto a : min_cost[destination])
        result = min(result, a.second);
    return result;
}

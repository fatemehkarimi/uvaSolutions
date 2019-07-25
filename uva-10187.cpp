//uva 10187
//From Dusk till Dawn

#include <iostream>
#include <climits>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

int Dijkstra(map <string, multimap <string, pair <int, int> > > & Graph, string source, string destination);
int diff_to_6_oclock(int hour)
{
    if(hour >= 18 && hour < 24)
        return 24 - hour + 6;
    else
        return 6 - hour;
}

int main(void)
{
    int T, tcounter = 0;
    cin >> T;
    while(T--){
        ++tcounter;

        int n;
        cin >> n;
        map <string, multimap <string, pair <int, int> > > Graph;//city_name, departure, arrival

        for(int i = 0; i < n; ++i){
            string city1, city2;
            int departure, hour;
            cin >> city1 >> city2 >> departure >> hour;
            if(Graph.find(city1) == Graph.end()){
                multimap <string, pair <int, int> > edges;
                Graph[city1] = edges;
            }
            if(Graph.find(city2) == Graph.end()){
                multimap <string, pair <int, int> > edges;
                Graph[city2] = edges;
            }
            departure %= 24; //moving on scale [0-24)
            if(hour > 12)//can't travel longer than 12 hours
                continue;
            int arrival = (departure + hour) % 24;
            if((departure >= 18 || departure <= 6) && (arrival >= 18 || arrival <= 6))
                Graph[city1].insert(make_pair(city2, make_pair(departure, arrival)));
        }

        string source, destination;
        cin >> source >> destination;
        int result = Dijkstra(Graph, source, destination);

        cout << "Test Case " << tcounter << "." << endl;
        if(result == INT_MAX)
            cout << "There is no route Vladimir can take." << endl;
        else
            cout << "Vladimir needs " << result << " litre(s) of blood." << endl;
    }
    return 0;
}

int Dijkstra(map <string, multimap <string, pair <int, int> > > & Graph, string source, string destination)
{
    set < pair < pair <int, int>, string> > Heap;
    map <string, int> min_blood;

    for(auto a : Graph)
        min_blood[a.first] = INT_MAX;

    min_blood[source] = 0;
    Heap.insert(make_pair(make_pair(0, 18), source));

    while(!Heap.empty()){
        int blood_curr_city = Heap.begin()->first.first;
        int arrival_curr_city = Heap.begin()->first.second;
        string curr_city = Heap.begin()->second;
        Heap.erase(Heap.begin());

        for(auto neighbor : Graph[curr_city]){
            string neighbor_city = neighbor.first;
            int neighbor_departure = neighbor.second.first;
            int neighbor_arrival = neighbor.second.second;
            int blood_neighbor = blood_curr_city;
            if(diff_to_6_oclock(arrival_curr_city) < diff_to_6_oclock(neighbor_departure))
                ++blood_neighbor;

            if(blood_neighbor <= min_blood[neighbor_city]){
                Heap.erase(make_pair(make_pair(min_blood[neighbor_city], neighbor_arrival), neighbor_city));
                min_blood[neighbor_city] = blood_neighbor;
                Heap.insert(make_pair(make_pair(min_blood[neighbor_city], neighbor_arrival), neighbor_city));
            }
        }
    }

    if(min_blood.find(destination) != min_blood.end())
        return min_blood[destination];
    else
        return INT_MAX;
}


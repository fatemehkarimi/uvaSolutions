//uva 11792
//Krochanska is Here!


#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

void BFS(vector <set <int> > & Graph, vector <int> & level, int root);

int main(void)
{
    int T;
    cin >> T;
    while(T--){
        int n, s;
        cin >> n >> s;

        vector <set <int> > station_map(n);
        vector <vector <int> > is_important(n);
        vector <int> important_stations;

        for(int i = 0; i < s; ++i){
            int station;
            vector <int> line;
            while(cin >> station, station){
                --station;
                if(is_important[station].empty() || is_important[station].back() != i)
                    is_important[station].push_back(i);
                line.push_back(station);
            }

            for(int j = 0; j < (int)line.size() - 1; ++j){
                station_map[line[j]].insert(line[j + 1]);
                station_map[line[j + 1]].insert(line[j]);
            }
        }

        for(int i = 0; i < n; ++i)
            if(is_important[i].size() >= 2)
                important_stations.push_back(i);

        int result_station = 0;
        double min_avg = n;

        for(auto root : important_stations){
            vector <int> level(n, 0);
            BFS(station_map, level, root);

            double avg = 0;
            for(auto a : important_stations)
                avg += level[a];
            avg /= important_stations.size();

            if(avg < min_avg){
                result_station = root;
                min_avg = avg;
            }
        }
        cout << "Krochanska is in: " << result_station + 1 << endl;
    }
    return 0;
}


void BFS(vector <set <int> > & Graph, vector <int> & level, int root)
{
    int n = Graph.size();
    vector <bool> visited(n, false);
    queue <int> Queue;
    Queue.push(root);
    visited[root] = true;
    level[root] = 0;

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

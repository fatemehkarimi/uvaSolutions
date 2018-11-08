//uva 10389
//Subway

#include <iostream>
#include <string>
#include <map>
#include <iomanip>
#include <vector>
#include <sstream>
#include <climits>
#include <set>
#include <cmath>

using namespace std;

double Dijkstra(vector <vector <pair <int, double> > > & Graph);
double distance(int x1, int y1, int x2, int y2);

int main(void)
{
    int T = 0;
    cin >> T;
    while(T--){
        int xs, ys, xd, yd;
        cin >> xs >> ys >> xd >> yd;

        vector <vector <pair <int, double> > > Graph(2);
        map <pair <int, int>, int> nodes;
        map <int, pair<int, int> > code_nodes;

        nodes[make_pair(xs, ys)] = 0;
        code_nodes[0] = make_pair(xs, ys);

        nodes[make_pair(xd, yd)] = 1;
        code_nodes[1] = make_pair(xd, yd);

        int code = 2;

        getchar();
        while(true){
            string input;
            getline(std::cin, input);

            if(input == "")
                break;

            vector <int> line;
            stringstream str(input);

            while(true){
                int x, y;
                str >> x >> y;

                if (x == -1 && y == -1)
                    break;

                if(nodes.find(make_pair(x, y)) != nodes.end()){
                    line.push_back(nodes[make_pair(x, y)]);
                    continue; 
                }

                nodes[make_pair(x, y)] = code;
                code_nodes[code] = make_pair(x, y);
                vector < pair <int, double> > empty_node;
                Graph.push_back(empty_node);
                line.push_back(code++);
            }

            for(int i = 0; i < line.size() - 1; ++i){
                int xi = code_nodes[line[i]].first;
                int yi = code_nodes[line[i]].second;

                int xj = code_nodes[line[i + 1]].first;
                int yj = code_nodes[line[i + 1]].second;

                double d = distance(xi, yi, xj, yj);
                Graph[line[i]].push_back(make_pair(line[i + 1], d));
                Graph[line[i + 1]].push_back(make_pair(line[i], d));
            }
        }

        for(int i = 0; i < Graph.size(); ++i)
            for(int j = i + 1; j < Graph.size(); ++j){
                bool previously_inserted = 0;

                for(auto a : Graph[i])
                    if(a.first == j){
                        previously_inserted = 1;
                        break;
                    }

                    if(previously_inserted)
                        continue;

                    pair <int, int> n1 = code_nodes[i];
                    pair <int, int> n2 = code_nodes[j];

                    double d = distance(n1.first, n1.second, n2.first, n2.second) * 4;
                    Graph[i].push_back(make_pair(j, d));
                    Graph[j].push_back(make_pair(i, d));
                }

        //end creating Graph

        double result = Dijkstra(Graph);
        cout << fixed << setprecision(0) << result / 2000.0 * 3.0 << endl;

        if(T) cout << endl;
    }

    return 0;
}

double Dijkstra(vector <vector <pair <int, double> > > & Graph)//s=0, d=1
{
    set <pair <double, int> > unvisited;
    vector <double> dis(Graph.size(), INT_MAX);
    unvisited.insert(make_pair(0, 0));
    dis[0] = 0;

    for(int i = 1; i < Graph.size(); ++i)
        unvisited.insert(make_pair(INT_MAX, i));

    while(!unvisited.empty()){
        double value = unvisited.begin()->first;
        int node = unvisited.begin()->second;

        unvisited.erase(unvisited.begin());

        for(auto a : Graph[node]){
            auto f = unvisited.find(make_pair(dis[a.first], a.first));

            if(value + a.second < dis[a.first]){
                unvisited.erase(f);
                dis[a.first] = value + a.second;
                unvisited.insert(make_pair(dis[a.first], a.first));
            }
        }
    }

    return dis[1];
}

double distance(int x1, int y1, int x2, int y2)
{
    long long int tmp = (long long int)(x1 - x2) * (x1 - x2) + (long long int)(y1 - y2) * (y1 - y2);
    return sqrt(tmp);
}


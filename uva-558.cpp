//uva 558
//Wormholes

#include <iostream>
#include <climits>
#include <vector>
#include <map>

using namespace std;

int main(void)
{
    int T = 0;
    cin >> T;
    while(T--){
        int n, m;
        cin >> n >> m;

        vector < map <int, int> > Graph(n);

        for(int i = 0; i < m; ++i){
            int u, v, t;
            cin >> u >> v >> t;

            Graph[u].insert(make_pair(v, t));
        }

        vector <int> distance(n, INT_MAX);
        distance[0] = 0;

        bool changed = false;
        for(int i = 0; i <= n; ++i){
            changed = 0;

            for(int j = 0; j < n; ++j)
                for(auto k : Graph[j])
                    if(distance[j] != INT_MAX && distance[j] + k.second < distance[k.first]){
                        changed = 1;
                        distance[k.first] = distance[j] + k.second;
                    }
        }

        if (changed)
            cout << "possible" << endl;
        else
            cout << "not possible" << endl;
    }
    return 0;
}

//uva 567
//Risk

#include <iostream>
#include <iomanip>
#include <vector>
#include <climits>

using namespace std;

vector < vector <int> > Floyd_Warshall(vector < vector <int> > & Graph);

int main(void)
{
    int tcounter = 0;
    int n = 0;
    while (cin >> n) {
        ++tcounter;
        vector < vector <int> > Graph(20, vector <int> (20, 100));//100 is considered as infinity in this problem

        for (int i = 0; i < 19; ++i){
            for (int j = 1; j <= n; ++j){
                int t1;
                cin >> t1;
                --t1;

                Graph[i][t1] = 1;
                Graph[t1][i] = 1;
            }

            cin >> n;
        }

        cout << "Test Set #" << tcounter << endl;
        vector < vector <int> > minimumDistance = Floyd_Warshall(Graph);

        int query = n; //last cin n is equal to query

        for (int i = 0; i < query; ++i){
            int source, distination;
            cin >> source >> distination;

            --source;
            --distination;

            cout << setw(2) << source + 1 << " to " << setw(2) << distination + 1 << ": " << minimumDistance[source][distination] << endl;
        }

        cout << endl;
    }
    return 0;
}

vector < vector <int> > Floyd_Warshall(vector < vector <int> > & Graph)
{
    vector < vector <int> > result = Graph;
    int size = Graph.size();

    for (int k = 0; k < size; ++k)
        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
                result[i][j] = min(result[i][j], result[i][k] + result[k][j]);

    return result;
}

//uva 821
//Page Hopping

#include <iostream>
#include <iomanip>
#include <climits>
#include <vector>
#include <map>

using namespace std;

vector <vector <int> > Floyd_Warshall(vector <vector <int> > & Graph, int size);

int main(void)
{
    int p1, p2;
    int tcounter = 0;
    while (true){
        cin >> p1 >> p2;

        if (p1 == 0 && p2 == 0)
            break;
        ++tcounter;

        vector < vector <int> > Graph(100, vector <int> (100, INT_MAX));
        map <int, int> nodeCode;

        for (int i = 0; i < 101; ++i)
            nodeCode[i] = -1;

        int lastcode = 0;
        nodeCode[p1] = lastcode++;
        nodeCode[p2] = lastcode++;

        Graph[nodeCode[p1]][nodeCode[p2]] = 1;

        while (true) {
            cin >> p1 >> p2;

            if (p1 == 0 && p2 == 0)
                break;

            int code1 = nodeCode[p1];
            int code2 = nodeCode[p2];

            if (code1 == -1){
                nodeCode[p1] = lastcode++;
                code1 = nodeCode[p1];
            }
            if (code2 == -1){
                nodeCode[p2] = lastcode++;
                code2 = nodeCode[p2];
            }


            Graph[code1][code2] = 1;
        }

        for (int i = 0; i < lastcode; ++i)
            Graph[i][i] = 0;

        vector < vector <int> > result = Floyd_Warshall(Graph, lastcode);


        double averageClick = 0;
        for (int i = 0; i < lastcode; ++i)
            for (int j = 0; j < lastcode; ++j)
                if (result[i][j] != INT_MAX)
                averageClick += result[i][j];


        cout << "Case " << tcounter << ": average length between pages = ";
        cout << fixed << setprecision(3) << averageClick / ((lastcode - 1) * lastcode) << " clicks" << endl;

    }
    return 0;
}

vector <vector <int> > Floyd_Warshall(vector <vector <int> > & Graph, int size)
{
    vector < vector <int> > result(size, vector <int> (size, 0));
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            result[i][j] = Graph[i][j];


    for (int k = 0; k < size; ++k)
        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
                if (result[i][k] != INT_MAX && result[k][j] != INT_MAX)
                    result[i][j] = min(result[i][j], result[i][k] + result[k][j]);

    return result;
}

//uva 10034
//Freckles

#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

int parent(vector <int> & ufds, int a);
void Union(vector <int> & ufds, int a, int b);
double distant(pair <double, double> a, pair <double, double> b);

int main(void)
{
    int T = 0;
    cin >> T;
    while(T--){
        int n = 0;
        cin >> n;

        vector <pair <double, double> > freckles(n);

        for(int i = 0; i < n; ++i){
            double x, y;
            cin >> x >> y;
            freckles[i] = make_pair(x, y);
        }

        set < pair <double, pair <int, int> > > kruskalSet;

        for(int i = 0; i < n; ++i)
            for(int j = i + 1; j < n; ++j){
                double dis = distant(freckles[i], freckles[j]);
                kruskalSet.insert(make_pair(dis, make_pair(i, j)));
            }

        vector <int> ufds(n, -1);
        double minimum_ink = 0;

        while(!kruskalSet.empty()){
            double value = kruskalSet.begin()->first;
            int u = kruskalSet.begin()->second.first;
            int v = kruskalSet.begin()->second.second;

            kruskalSet.erase(kruskalSet.begin());

            if(parent(ufds, u) != parent(ufds, v)){
                Union(ufds, u, v);
                minimum_ink += value;
            }
        }

        cout << setprecision(2) << fixed << minimum_ink << endl;
        if(T) cout << endl;

    }
    return 0;
}

double distant(pair <double, double> a, pair <double, double> b)
{
    double tmp = (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
    return sqrt(tmp);
}

void Union(vector <int> & ufds, int a, int b)
{
    int p1 = parent(ufds, a);
    int p2 = parent(ufds, b);

    ufds[p2] = p1;
}

int parent(vector <int> & ufds, int a)
{
    int x = a;

    while (ufds[x] != -1)
        x = ufds[x];

    while(ufds[a] != -1){
        int tmp = ufds[a];
        ufds[a] = x;
        a = tmp;
    }

    return x;
}

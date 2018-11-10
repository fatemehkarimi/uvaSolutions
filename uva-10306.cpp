//uva 10306
//e-Coins

#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

int main(void)
{
    int T = 0;
    cin >> T;
    while(T--){
        int m, s;
        cin >> m >> s;

        vector <int> xs;
        vector <int> ys;

        for(int i = 0; i < m; ++i){
            int x, y;
            cin >> x >> y;

            xs.push_back(x);
            ys.push_back(y);
        }

        vector <vector <int> > arr(s + 1, vector <int> (s + 1, INT_MAX));

        for(int k = 0; k < m; ++k){
            if (xs[k] < s + 1 && ys[k] < s + 1)
                arr[xs[k]][ys[k]] = 1;

            for(int i = 0; i < s + 1; ++i)
                for(int j = 0; j < s + 1; ++j)
                    if(arr[i][j] != INT_MAX && i + xs[k] < s + 1 && j + ys[k] < s + 1)
                        arr[i + xs[k]][j + ys[k]] = min(arr[i][j] + 1, arr[i + xs[k]][j + ys[k]]);
        }

        int numberOfCoins = INT_MAX;

        for(int i = 0; i < s + 1; ++i){
            double tmp = sqrt(s * s - i * i);

            if(tmp - (int)tmp == 0)
                numberOfCoins = min(numberOfCoins, arr[i][tmp]);
        }

        if(numberOfCoins == INT_MAX)
            cout << "not possible" << endl;
        else
            cout << numberOfCoins << endl;

    }
    return 0;
}

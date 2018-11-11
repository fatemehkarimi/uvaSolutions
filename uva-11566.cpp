//uva 11566
//Let’s Yum Cha!

#include <iostream>
#include <iomanip>
#include <vector>
#include <climits>

using namespace std;

int main(void)
{
    int n, x, T, k;
    while(true){
        cin >> n >> x >> T >> k;

        if(n == 0 && x == 0 && T == 0 && k == 0)
            break;

        ++n;

        vector <int> dim_price;
        vector <int> dim_joy;

        for(int i = 0; i < k; ++i){
            int p, joy = 0;
            cin >> p;

            dim_price.push_back(p);//we can have at most 2 dim of each type
            dim_price.push_back(p);

            for(int j = 0; j < n; ++j){
                int t;
                cin >> t;
                joy += t;
            }

            dim_joy.push_back(joy);
            dim_joy.push_back(joy);
        }


        int order_limit = min(2 * n, (int)dim_price.size()) + 1;
        int max_money = 10.0 * ((double)n * (double)x) / 11.0 - (double)(n * T);

        vector <vector <int> > arr(order_limit, vector <int> (max_money + 1, INT_MIN));

        for(int i = 0; i < order_limit; ++i)
            arr[i][0] = 0;

        for(int i = 0; i < max_money + 1; ++i)
            arr[0][i] = 0;

        for(int p = 0; p < dim_price.size(); ++p){
            vector <vector <int> > new_arr = arr;

            for(int i = 0; i < order_limit; ++i)
                for(int j = 0; j < max_money + 1; ++j)
                    if(arr[i][j] != INT_MIN && i + 1 < order_limit && j + dim_price[p] <= max_money)
                        new_arr[i + 1][j + dim_price[p]] = max(arr[i + 1][j + dim_price[p]], arr[i][j] + dim_joy[p]);

            arr = new_arr;
        }

        int max_joy = 0;
        for(auto a : arr)
            for(auto b : a)
                if(b > max_joy)
                    max_joy = b;

        cout << fixed << setprecision(2) << (double)max_joy / (double)n << endl;
    }
    return 0;
}

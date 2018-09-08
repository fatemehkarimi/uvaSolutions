//uva 11517
//Exact Change

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main(void)
{
    int T = 0;
    cin >> T;

    while (T--) {
        int cost = 0;
        cin >> cost;

        int n = 0;
        cin >> n;

        vector <int> coins(n);
        int coin_sum = 0;
        for (int i = 0; i < n; ++i){
            cin >> coins[i];
            coin_sum += coins[i];
        }

        vector < vector <int> > arr(n + 1, vector <int> (coin_sum + 1, INT_MAX));

        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= coin_sum; ++j)
                if (j - coins[i - 1] == 0)
                    arr[i][j] = 1;
                else if (j - coins[i - 1] > 0 && arr[i - 1][j - coins[i - 1]] != INT_MAX)
                    arr[i][j] = min(arr[i - 1][j], arr[i - 1][j - coins[i - 1]] + 1);
                else
                    arr[i][j] = arr[i - 1][j];

        int paid = 0;
        int count = 0;
        for (int i = cost; i <= coin_sum; ++i)
            if (arr[n][i] != INT_MAX){
                paid = i;
                count = arr[n][i];
                break;
            }

        cout << paid << ' ' << count << endl;
    }

    return 0;
}

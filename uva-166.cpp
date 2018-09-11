//uva 166
//Making Change

#include <iostream>
#include <climits>
#include <vector>
#include <cstdio>
#include <iomanip>

using namespace std;

int main(void)
{
    int coins[6] = {1, 2, 4, 10, 20, 40};//unit is cent
    int count[6];

    vector <int> sChange(101, INT_MAX);//for salesman
    sChange[0] = 0;

    for (int i = 0; i < 6; ++i)//for salesman
        for (int j = 1; j <= 100; ++j)
            if (j - coins[i] >= 0 && sChange[j - coins[i]] != INT_MAX)
                sChange[j] = min(sChange[j], sChange[j - coins[i]] + 1);

    while (1){
        cin >> count[0] >> count[1] >> count[2] >> count[3] >> count[4] >> count[5];
        if (!(count[0] | count[1] | count[2] | count[3] | count[4] | count[5]))
            break;

        int money = 0;
        int cent = 0;
        scanf("%d.%d", &money, &cent);
        money = money * 100 + cent;
        money /= 5;

        vector <int> allCoins;
        int sum = 0;

        for (int i = 0; i < 6; ++i)
            for (int j = 0; j < count[i]; ++j){
                sum += coins[i];
                allCoins.push_back(coins[i]);
            }

        vector < vector <int> > cChange(allCoins.size() + 1, vector <int> (sum + 1, INT_MAX));//for us

        for (int i = 0; i <= allCoins.size(); ++i)
            cChange[i][0] = 0;

        for (int i = 1; i <= allCoins.size(); ++i){//for us
            for (int j = 1; j <= sum; ++j)
                if (j - allCoins[i - 1] >= 0 && cChange[i - 1][j - allCoins[i - 1]] != INT_MAX)
                    cChange[i][j] = min(cChange[i - 1][j], cChange[i - 1][j - allCoins[i - 1]] + 1);
                else
                    cChange[i][j] = cChange[i - 1][j];

            for (int j = 1; j < sum; ++j)
                for (int k = j + 1; k <= sum; ++k)
                    if (cChange[i][k] != INT_MAX && sChange[k - j] != INT_MAX)
                        cChange[i][j] = min(cChange[i][j], cChange[i][k] + sChange[k - j]);
        }

        cout << right << setw(3) << cChange[allCoins.size()][money] << endl;
    }

    return 0;
}

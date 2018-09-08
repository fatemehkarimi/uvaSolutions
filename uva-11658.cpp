//uva 11658
//Best Coalitions

#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <cstdio>

using namespace std;

int main(void)
{
    int n, x;

    while (true) {
        cin >> n >> x;

        if (n == 0 && x == 0)
            break;

        --x;

        vector <int> precent(n);
        for (int i = 0; i < n; ++i){
            int tmp1, tmp2;
            scanf("%d.%d", &tmp1, &tmp2);
            getchar();

            precent[i] = tmp1 * 100 + tmp2;
        }
        //swap precent[0] && precent[x]
        int tmp = precent[0];
        precent[0] = precent[x];
        precent[x] = tmp;


        vector < vector <double> > arr (n, vector <double> (10001, -1));
        arr[0][precent[0]] = (precent[0] > 5000 ? 100 : 0);

        for (int i = 1; i < n; ++i)
            for (int j = 0; j <= 10000; ++j)
                if (arr[i - 1][j] >= 0){
                    arr[i][j] = arr[i - 1][j];

                    int tmp = j + precent[i];
                    double profit = (tmp > 5000 ? ((double)precent[0]) / ((double)tmp) : 0);
                    profit *= 100;

                    arr[i][tmp] = max(arr[i - 1][tmp], profit);
                }

        double maxProfit = 0;
        for (int i = 5001; i <= 10000; ++i)
            if (arr[n - 1][i] > maxProfit)
                maxProfit = arr[n - 1][i];

        cout << fixed << setprecision(2) << maxProfit << endl;

    }
    return 0;
}

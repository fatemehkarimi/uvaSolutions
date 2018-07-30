//uva 562
//Dividing coins

#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int T = 0;
    cin >> T;

    while (T--) {
        int m = 0;

        cin >> m;

        if (m == 0){
            cout << 0 << endl;
            continue;
        }

        vector <int> num(m);
        int total_sum = 0;

        for (int i = 0; i < m; ++i){
            cin >> num[i];
            total_sum += num[i];
        }


        vector < vector <bool> > arr(m, vector <bool> (total_sum + 1, false));

        arr[0][num[0]] = 1;

        for (int i = 1; i < m; ++i){
            arr[i][num[i]] = 1;

            for (int j = 1; j <= total_sum; ++j)
                if (arr[i - 1][j]){
                    arr[i][j] = 1;
                    arr[i][j + num[i]] = 1;
                }
        }


        int min_diff = total_sum;

        for (int i = 1; i <= total_sum; ++i)
            if (m - 2 >= 0 && arr[m - 1][i] && arr[m - 2][total_sum - i])
                if (abs(total_sum - 2 * i) < min_diff)
                    min_diff = abs(total_sum - 2 * i);


        cout << min_diff << endl;

    }

    return 0;
}

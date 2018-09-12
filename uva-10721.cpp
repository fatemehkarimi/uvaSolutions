//uva 10721
//Bar Codes

#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int n, m, k;
    while (cin >> k >> n >> m) {
        vector < vector <long long int> > arr(n + 1, vector <long long int> (k + 1, 0));

        arr[0][0] = 1;

        for (int j = 1; j < k + 1; ++j)
            for (int i = 1; i < n + 1; ++i)
                for (int x = 1; x <= m; ++x)
                    if (j - x >= 0)
                        arr[i][j] += arr[i - 1][j - x];

        cout << arr[n][k] << endl;
    }
    return 0;
}

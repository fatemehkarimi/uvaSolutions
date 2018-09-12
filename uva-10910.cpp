//uva 10910
//Marks Distribution

#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int T = 0;
    cin >> T;
    while(T--) {
        int n, t, p;
        cin >> n >> t >> p;

        vector < vector <int> > arr(n + 1, vector <int> (t + 1, 0));

        arr[0][0] = 1;

        for (int i = 1; i < n + 1; ++i)
            for (int j = p; j < t + 1; ++j)
                for (int k = p; k < t + 1; ++k)
                    if (j - k >= 0)
                        arr[i][j] += arr[i - 1][j - k];

        cout << arr[n][t] << endl;
    }
    return 0;
}

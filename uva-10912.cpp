//uva 10912
//Simple Minded Hashing

#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int l, s;
    int tcounter = 0;
    while (1) {
        cin >> l >> s;

        if (l == 0 && s == 0)
            break;

        ++tcounter;

        l = min(l, 26);

        vector < vector <int> > arr(l + 1, vector <int> (s + 1, 0));
        arr[0][0] = 1;

        for (int k = 1; k <= 26; ++k){
            vector < vector <int> > arr_tmp(l + 1, vector <int> (s + 1, 0));
            arr_tmp[0][0] = 1;

            for (int i = 1; i < l + 1; ++i)
                for (int j = 1; j < s + 1; ++j)
                    if (j - k >= 0)
                        arr_tmp[i][j] = arr[i][j] + arr[i - 1][j - k];
                    else
                        arr_tmp[i][j] = arr[i][j];

                arr = arr_tmp;
            }

        cout << "Case " << tcounter << ": " << arr[l][s] << endl;
    }
    return 0;
}

//uva 10036
//Divisibility


#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int T = 0;
    cin >> T;

    while (T--) {

        int n = 0, k = 0;
        cin >> n >> k;

        vector <bool> rem(k);

        int num;
        cin >> num;

        rem[abs(num % k)] = 1;

        for (int i = 1; i < n; ++i){
            cin >> num;
            num = abs(num % k);

            vector <bool> _rem_tmp(k, 0);

            for (int i = 0; i < k; ++i)
                if (rem[i]){
                    _rem_tmp[(i + num) % k] = 1;
                    _rem_tmp[abs((i - num) % k)] = 1;
                }

                rem = _rem_tmp;

        }

        if (rem[0])
            cout << "Divisible" << endl;
        else
            cout << "Not divisible" << endl;
    }
    return 0;
}

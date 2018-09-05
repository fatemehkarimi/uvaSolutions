//uva 10616
//Divisible Group Sums

#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int n, q;
    int tcounter = 0;

    while (true) {
        cin >> n >> q;

        if (n == 0 && q == 0)
            break;
        ++tcounter;

        vector <int> num(n);
        for (int i = 0; i < n; ++i)
            cin >> num[i];

        cout << "SET " << tcounter << ":" << endl;

        int qcounter = 0;
        while (q--) {
            int d, m;
            cin >> d >> m;
            ++qcounter;

            vector < vector <int> > arr(m, vector <int> (d, 0));
            vector < vector <int> > tmp_arr(m, vector <int> (d, 0));


            for (int i = 0; i < n; ++i){
                for(int k = 0; k < m - 1; ++k)
                    for (int j = 0; j < d; ++j){
                        int rem = ((num[i] + j) % d + d) % d;//to avoid negative remainder
                        tmp_arr[k + 1][rem] += arr[k][j];
                    }

                ++tmp_arr[0][((num[i] % d) + d) % d];
                arr = tmp_arr;
            }

            cout << "QUERY " << qcounter << ": " << arr[m - 1][0] << endl;
        }
    }
    return 0;
}

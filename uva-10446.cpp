//uva 10446
//The Marriage Interview ;-)

#include <iostream>

using namespace std;


int main(void)
{
    int tcounter = 0;
    unsigned long long int arr[61][61];

    for (int i = 0; i < 61; ++i)
        for (int j = 0; j < 61; ++j)
            arr[i][j] = 1;


    for (int j = 2; j < 61; ++j)
        for (int i = 0; i < 61; ++i)
            for (int k = 1; k <= i; ++k)
                if (j >= k)
                    arr[i][j] += (arr[i][j - k]);
                else if (j < k)
                    arr[i][j] += arr[i][0];

    while (1){
        int a, b;
        cin >> a >> b;
        if (a > 60 || b > 60)
            break;

        ++tcounter;
        if (a >= 0)
            cout << "Case " << tcounter << ": " << arr[b][a] << endl;
        else
            cout << "Case " << tcounter << ": " << 1 << endl;
    }

    return 0;
}

//uva 11407
//Squares

#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

#define CONST 10001

using namespace std;

int main(void)
{
    int T = 0;
    cin >> T;

    int arr[CONST];
    arr[1] = 1;
    arr[0] = 0;

    for (int i = 2; i < CONST; ++i){
        int limit = floor(sqrt(i));
        arr[i] = INT_MAX;

        for (int j = 1; j <= limit; ++j)
            arr[i] = min(arr[i], arr[i - j * j] + 1);
    }

    while (T--) {
        int n = 0;
        cin >> n;

        cout << arr[n] << endl;
    }

    return 0;
}


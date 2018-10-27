//uva 11456
//Trainsorting

#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int T = 0;
    cin >> T;
    while(T--){
        int n = 0;
        cin >> n;

        vector <int> num(n);
        for(int i = 0; i < n; ++i)
            cin >> num[i];

        vector <int> LIS(n, 1);
        vector <int> LDS(n, 1);

        for(int i = n - 1; i >= 0; --i)
            for(int j = i + 1; j < n; ++j)
                if (num[i] > num[j])
                    LIS[i] = max(LIS[i], LIS[j] + 1);

        for(int i = n - 1; i >= 0; --i)
            for(int j = i + 1; j < n; ++j)
                if(num[i] < num[j])
                    LDS[i] = max(LDS[i], LDS[j] + 1);

        int result = 0;
        for(int i = 0; i < n; ++i)
            result = max(result, LIS[i] + LDS[i] - 1);

        cout << result << endl;
    }
    return 0;
}

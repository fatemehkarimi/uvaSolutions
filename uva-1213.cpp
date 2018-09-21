//uva 1213
//Sum of Different Primes

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool isPrime(int a);

int main(void)
{
    vector <int> primes;
    for (int i = 1; i <= 1120; ++i)
        if (isPrime(i))
            primes.push_back(i);

    int n , k;
    while(1) {
        cin >> n >> k;

        if (n == 0 && k == 0)
            break;

        vector <int> nums;
        for (auto a : primes)
            if (a > n)
                break;
            else
                nums.push_back(a);

        vector < vector <int> > arr(nums.size() + 1, vector <int> (n + 1, 0));
        for (int i = 0; i < nums.size() + 1; ++i)
            arr[i][0] = 1;

        for (int x = 1; x <= k; ++x){
            vector < vector <int> > tmp(nums.size() + 1, vector <int> (n + 1, 0));            

            for (int i = 1; i <= nums.size(); ++i)
                for (int j = 1; j <= n; ++j)
                    if (j - nums[i - 1] >= 0)
                        tmp[i][j] = tmp[i - 1][j] + arr[i - 1][j - nums[i - 1]];
                    else
                        tmp[i][j] = tmp[i - 1][j];

                arr = tmp;
        }

        cout << arr[nums.size()][n] << endl;

    }
    return 0;
}

bool isPrime(int a)
{
    if (a == 1)
        return false;
    else if (a == 2)
        return true;

    int limit = sqrt(a);
    for (int i = 2; i <= limit; ++i)
        if (a % i == 0)
            return false;

    return true;
}

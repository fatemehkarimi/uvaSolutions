//uva 11136
//Hoax or what

#include <iostream>
#include <set>

using namespace std;

int main(void)
{
    int n = 0;
    while (true) {
        cin >> n;

        if (n == 0)
            break;

        multiset <int> num;

        long long int totalPrice = 0;


        for (int i = 0; i < n; ++i){
            int k = 0;
            cin >> k;

            for (int j = 0; j < k; ++j){
                int t;
                cin >> t;

                num.insert(t);
            }

            int smallest = *num.begin();
            num.erase(num.begin());

            int biggest = *num.rbegin();
            num.erase(--num.end());

            totalPrice += (biggest - smallest);

        }

        cout << totalPrice << endl;
    }

    return 0;
}

//uva 482
//Permutation Arrays

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main(void)
{
    int T = 0;
    cin >> T;
    getchar();
    getchar();

    while (T--){
        string input;
        getline(cin, input);

        vector <int> index;

        stringstream stream1(input);

        while (true) {
            int x;
            stream1 >> x;

            --x;

            if (!stream1)
                break;

            index.push_back(x);
        }

        vector <string> nums;
        getline(cin, input);

        stringstream stream2(input);
        while (true) {
            string x;
            stream2 >> x;

            if (!stream2)
                break;

            nums.push_back(x);
        }

        vector <string> result(index.size());

        for (int i = 0; i < index.size(); ++i)
            result[index[i]] = nums[i];

        for (auto a : result)
            cout << a << endl;


        if (T){
            getchar();
            cout << endl;
        }
    }

    return 0;
}

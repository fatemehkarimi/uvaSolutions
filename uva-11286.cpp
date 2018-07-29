//uva 11286 Conformity

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main(void)
{
    int n = 0;
    while (true) {
        cin >> n;

        if (n == 0)
            break;

        map < vector <int>, int> course;

        for (int i = 0; i < n; ++i){
            vector <int> tmp;
            for (int j = 0; j < 5; ++j){
                int t;
                cin >> t;

                tmp.push_back(t);
            }

            sort(tmp.begin(), tmp.end());
            ++course[tmp];

        }

        int max_value = -1;

        for (auto a : course)
            if (a.second > max_value)
                max_value = a.second;

        int frosh = 0;
        for (auto a : course)
            if (a.second == max_value)
                frosh += a.second;


        cout << frosh << endl;

    }
    return 0;
}

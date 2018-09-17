//uva 10086
//Test the Rods

#include <iostream>
#include <vector>
#include <climits>
#include <iomanip>
#include <stack>

using namespace std;

int main(void)
{
    int t1, t2;
    while  (true) {
        cin >> t1 >> t2;

        if (t1 == 0 && t2 == 0)
            break;

        int n;
        cin >> n;//number of sites

        vector < vector <int> > pA(n);
        vector < vector <int> > pB(n);
        for (int i = 0; i < n; ++i){
            int x;
            cin >> x;

            for (int j = 0; j < x; ++j){
                int tmp;
                cin >> tmp;
                pA[i].push_back(tmp);
            }
            for (int j = 0; j < x; ++j){
                int tmp;
                cin >> tmp;
                pB[i].push_back(tmp);
            }
        }

        vector < vector <int> > arr(n, vector <int> (t1 + 1, INT_MAX));
        vector < vector <int> > used(n, vector <int> (t1 + 1, -1));

        for (int i = 0; i < t1 + 1; ++i){
            if (i > pA[0].size())
                break;

            int value = 0;
            if (i == 0)
                value = pB[0].back();
            else if (i == pA[0].size())
                value = pA[0].back();
            else
                value = pA[0][i - 1] + pB[0][pA[0].size() - i - 1];
            arr[0][i] = value;
        }

        for (int i = 1; i < n; ++i)
            for (int j = 0; j < t1 + 1; ++j)
                if (arr[i - 1][j] != INT_MAX)
                    for (int k = 0; k < t1 - j + 1; ++k){
                        if (k > pA[i].size())
                            break;

                        int value = arr[i - 1][j];
                        if (k == 0)
                            value += pB[i].back();
                        else if (k == pA[i].size())
                            value += pA[i].back();
                        else
                            value += pA[i][k - 1] + pB[i][pA[i].size() - k - 1];

                        if (arr[i][j + k] > value){
                            arr[i][j + k] = value;
                            used[i][j + k] = k;
                        }

                    }

        cout << arr[n - 1][t1] << endl;
        stack <int> Stack;
        int x = n - 1;
        int y = t1;
        while (x > 0){
            Stack.push(used[x][y]);
            y -= used[x][y];
            x -= 1;
        }
        Stack.push(y);

        cout << Stack.top();
        Stack.pop();
        while(!Stack.empty()){
            cout << ' ' << Stack.top();
            Stack.pop();
        }

        cout << endl;
    }
    return 0;
}

//uva 10400
//Game Show Math

#include <iostream>
#include <climits>
#include <vector>
#include <stack>

using namespace std;

int main(void)
{
    int T = 0;
    cin >> T;

    while (T--) {
        int n, target;
        cin >> n;
        vector <int> num(n);

        for (int i = 0; i < n; ++i)
            cin >> num[i];

        cin >> target;

        vector < vector <bool> > arr(n, vector <bool> (64001, 0));

        arr[0][num[0] + 32000] = 1;

        for (int i = 1; i < n; ++i)
            for (int j = 0; j < 64001; ++j)
                if (arr[i - 1][j]){
                    int n_value = j + num[i];
                    if (n_value >= 0  && n_value < 64001)
                        arr[i][n_value] = 1;

                    n_value = j - num[i];
                    if (n_value >= 0 && n_value < 64001)
                        arr[i][n_value] = 1;

                    n_value = (j - 32000) * num[i] + 32000;
                    if (n_value >= 0 && n_value < 64001)
                        arr[i][n_value] = 1;

                    n_value = ((j - 32000) % num[i] == 0 ? (j - 32000) / num[i] + 32000 : INT_MIN);
                    if (n_value >= 0 && n_value < 64001)
                        arr[i][n_value] = 1;
                }


        if (target + 32000 >= 0 && target + 32000 < 64001 && arr[n - 1][target + 32000]){
            stack <char> Stack;

            int start = target + 32000;
            for (int i = n - 1; i > 0; --i){
                int val = start - num[i];
                if (val >= 0 && val < 64001 && arr[i - 1][val]){
                    start = val;
                    Stack.push('+');
                    continue;
                }

                val = start + num[i];
                if (val >= 0 && val < 64001 && arr[i - 1][val]){
                    start = val;
                    Stack.push('-');
                    continue;
                }

                val = (start - 32000) % num[i] == 0 ? ((start - 32000) / num[i] + 32000) : INT_MIN;
                if (val >= 0 && val < 64001 && arr[i - 1][val]){
                    start = val;
                    Stack.push('*');
                    continue;
                }

                val = (start - 32000) * num[i] + 32000;
                if (val >= 0 && val < 64001 && arr[i - 1][val]){
                    start = val;
                    Stack.push('/');
                    continue;
                }
            }

            cout << num[0];
            for (int i = 1; i < n; ++i){
                char op = Stack.top();
                Stack.pop();
                cout << op << num[i];

            }
            cout << '=' << target << endl;

        }
        else
            cout << "NO EXPRESSION" << endl;
    }
    return 0;
}

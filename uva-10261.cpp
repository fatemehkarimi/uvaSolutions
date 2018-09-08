//uva 10261
//Ferry Loading

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stack>

using namespace std;

int main(void)
{
    int T = 0;
    cin >> T;
    while (T--) {
        int l = 0;
        cin >> l;

        l *= 100;//in centimeters

        vector <int> nums;//in centimeters
        while (1){
            int n;
            cin >> n;

            if (n == 0)
                break;

            nums.push_back(n);   
        }

        vector < vector <bool> > arr(nums.size() + 1, vector <bool> (l + 1, 0));
        vector < vector <int> > count(nums.size() + 1, vector <int> (l + 1, -1));// for back tracking

        arr[0][l] = 1;
        int sum = 0;

        int car = 0;
        int i = 1;

        for (; i <= nums.size(); ++i){
            bool carInserted = 0;

            for (int j = 0; j <= l; ++j){
                if (arr[i - 1][j]) {
                    if (j - nums[i - 1] >= 0){//inserting left
                        arr[i][j - nums[i - 1]] = 1;
                        carInserted = 1;

                        count[i][j - nums[i - 1]] = j;
                    }

                    int remainRight = (l - (sum - (l - j)));
                    if (remainRight - nums[i - 1] >= 0){//inserting right
                        arr[i][j] = 1;
                        carInserted = 1;

                        count[i][j] = j;
                    }
                }
            }

            sum += nums[i - 1];
            if (!carInserted)
                break;
        }

        car = i - 1;

        stack <string> Stack;

        int start = -1;
        for (int i = 0; i < arr[car].size(); ++i)
            if (arr[car][i]){
                start = i;
                break;
            }

        cout << car << endl;
        while(car > 0){
            if (count[car][start] == start)
                Stack.push("port");
            else
                Stack.push("starboard");
            start = count[car][start];
            --car;
        }

        while (!Stack.empty()){
            cout << Stack.top() << endl;
            Stack.pop();
        }

        if (T != 0)
            cout << endl;

    }

    return 0;
}

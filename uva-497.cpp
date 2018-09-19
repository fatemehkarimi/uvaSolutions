//uva 497
//Strategic Defense Initiative

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stack>

using namespace std;

stack <int> LIS(vector <int> & nums);
int findLoc(vector <int> & nums, vector <int> & ends, int l, int r, int key);

int main(void)
{
    int T = 0;
    cin >> T;
    getchar();
    getchar();
    while (T--) {
        vector <int> nums;
        while (true) {
            string n;
            getline(cin, n);

            if (n == "")
                break;

            stringstream x(n);
            int tmp;
            x >> tmp;

            nums.push_back(tmp);
        }

        stack <int> result = LIS(nums);
        cout << "Max hits: " << result.size() << endl;
        while (!result.empty()){
            cout << result.top() << endl;
            result.pop();
        }

        if (T)
            cout << endl;

    }
    return 0;
}

int findLoc(vector <int> & nums, vector <int> & ends, int l, int r, int key)
{
    while (r - l > 1){
        int m = l + (r - l) / 2;

        if (nums[ends[m]] >= key)
            r = m;
        else
            l = m;
    }
    return r;
}

stack <int> LIS(vector <int> & nums)
{
    stack <int> result;
    if (nums.size() == 0)
        return result;

    vector <int> ends(nums.size());
    vector <int> pre(nums.size(), -1);
    int l = 1;

    for (int i = 0; i < nums.size(); ++i)
        if (nums[ends[0]] >= nums[i])
            ends[0] = i;
        else if (nums[ends[l - 1]] < nums[i]){
            pre[i] = ends[l - 1];
            ends[l++] = i;
        }
        else{
            int index = findLoc(nums, ends, 0, l - 1, nums[i]);
            pre[i] = ends[index - 1];
            ends[index] = i;
        }

    result.push(nums[ends[l - 1]]);
    int index = pre[ends[l - 1]];
    while(index >= 0){
        result.push(nums[index]);
        index = pre[index];
    }

    return result;
}

//uva 1261
//String Popping

#include <iostream>
#include <map>
#include <string>

using namespace std;

map <string, bool> checkedStrs;

bool checkProperty(string input);

int main(void)
{
    int T = 0;
    cin >> T;
    while (T--) {
        string input;
        cin >> input;

        cout << checkProperty(input) << endl;
    }

    return 0;
}

bool checkProperty(string input)
{
    if (input.size() == 0)
        return true;

    if (checkedStrs.count(input) != 0)
        return checkedStrs[input];

    for (int i = 0; i < input.size(); ++i){
        int j = i;
        while (j < input.size() && input[j] == input[i])
            ++j;

        if (j - i > 1){
            string new_str = input.substr(0, i) + input.substr(j);

            if (checkProperty(new_str)){
                checkedStrs[input] = true;
                return true;
            }
            i = j - 1;
        }
    }

    return false;
}

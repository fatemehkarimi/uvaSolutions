//uva 712
//S-Trees

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int toInt(string & binary);

int main(void)
{
    int n = 0;
    int tcounter = 0;
    while(true){
        cin >> n;

        if(n == 0)
            break;

        ++tcounter;

        vector <string> variables(n);
        for(int i = 0; i < n; ++i)
            cin >> variables[i];

        string values;
        cin >> values;

        string result;
        int m;
        cin >> m;
        for(int i = 0; i < m; ++i){
            string binary;
            cin >> binary;
            int index = toInt(binary);
            if(values[index] == '1')
                result = result + '1';
            else
                result = result + '0';
        }

        cout << "S-Tree #" << tcounter << ":" << endl;
        cout << result << endl << endl;
    }
    return 0;
}

int toInt(string & binary)
{
    int result = 0;
    for(int i = 0; i < (int)binary.size(); ++i)
        if(binary[i] == '1')
            result = result * 2 + 1;
        else
            result *= 2;
    return result;
}

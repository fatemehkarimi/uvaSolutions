//uva 785
//Grid Colouring

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void DFS(vector <string> & arr, vector <vector <bool> > & colored, int x, int y, char cc, char bound);

int main(void)
{
    while (true) {
        string input;
        string seperate_line;
        vector <string> arr;

        if (getline(std::cin, input))
            arr.push_back(input);
        else
            break;

        while (true){
            getline(std::cin, input);

            if (input[0] == '_'){
                seperate_line = input;
                break;
            }

            arr.push_back(input);
        }

        char bound;
        for (auto a : arr)
            for (auto b : a)
                if (b != ' '){
                    bound = b;
                    break;
                }

        vector <vector <bool> > colored(arr.size(), vector <bool> (80, false));

        for (int i = 0; i < arr.size(); ++i)
            for (int j = 0; j < arr[i].size(); ++j)
                if (arr[i][j] != ' ' && arr[i][j] != bound && !colored[i][j])
                    DFS(arr, colored, i, j, arr[i][j], bound);

        for (auto a : arr)
            cout << a << endl;
        cout << seperate_line << endl;
    }
    return 0;
}

void DFS(vector <string> & arr, vector <vector <bool> > & colored, int x, int y, char cc, char bound)
{
    colored[x][y] = 1;
    arr[x][y] = cc;

    int r = arr.size();

    if (x - 1 >= 0 && y < arr[x - 1].size() && arr[x - 1][y] != bound && !colored[x - 1][y])
        DFS(arr, colored, x - 1, y, cc, bound);

    if (x + 1 < r && y < arr[x + 1].size() && arr[x + 1][y] != bound && !colored[x + 1][y])
        DFS(arr, colored, x + 1, y, cc, bound);

    if (y - 1 >= 0 && arr[x][y - 1] != bound && !colored[x][y - 1])
        DFS(arr, colored, x, y - 1, cc, bound);

    if (y + 1 < arr[x].size() && arr[x][y + 1] != bound && !colored[x][y + 1])
        DFS(arr, colored, x, y + 1, cc, bound);

    return;
}

//uva 10258
//Contest Scoreboard

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int contestantNum(string a);
int problemNum(string a);
int timeCount(string a);

int main(void)
{
    int T = 0;
    cin >> T;

    string input;
   getline(cin, input);
   getline(cin, input);

    while (T--){
        int penalty[100] = {0};
        bool solved [100][10] = {0};
        int unsolved[100][10] = {0};

        bool submit[100] = {false};

        while (true){
            getline(cin, input);

            if (input == "")
                break;

            int conNum = contestantNum(input) - 1;
            int pNum = problemNum(input) - 1;
            int time = timeCount(input);
            char status = input[input.size() - 1];

            submit[conNum] = true;


            if (status == 'C'){
                if (!solved[conNum][pNum]){
                    solved[conNum][pNum] = 1;
                    penalty[conNum] += time;
                }
            }
            else if (status == 'I')
                if (!solved[conNum][pNum]){
                    ++unsolved[conNum][pNum];
                }

        }      

        vector < pair<int, pair<int, int> > > board;

        for (int i = 0; i < 100; ++i)
            for (int j = 0; j < 10; ++j)
                if (solved[i][j])
                    penalty[i] += (20 * unsolved[i][j]);

        for (int i = 0; i < 100; ++i){
            int count = 0;
            for (int j = 0; j < 10; ++j)
                if (solved[i][j])
                    ++count;

            if (submit[i])
                board.push_back(make_pair(count, make_pair(-penalty[i], -(i + 1))));
        }

        sort(board.begin(), board.end());

        for (auto a = board.crbegin(); a != board.crend(); ++a)
            cout << -a->second.second << ' ' << a->first << ' ' << -a->second.first << endl;


        if (T != 0)
            cout << endl;
    }

    return 0;
}

int contestantNum(string a)
{
    int code = 0;
    for (int i = 0; i < a.size() && a[i] != ' ' ; ++i)
        code = code * 10 + a[i] - '0';

    return code;
}

int problemNum(string a)
{
    int code = 0;
    int i = 0;
    for (i = 0; i < a.size() && a[i] != ' '; ++i);
    ++i;
    for (; i < a.size() && a[i] != ' '; ++i)
        code = code * 10 + a[i] - '0';

    return code;
}

int timeCount(string a)
{
    int code = 0;
    int i = 0;
    for (i = 0; i < a.size() && a[i] != ' '; ++i);
    ++i;
    for (; i < a.size() && a[i] != ' '; ++i);
    ++i;
    for (; i < a.size() && a[i] != ' '; ++i)
        code = code * 10 + a[i] - '0';

    return code;
}


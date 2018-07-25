//uva 10855
//Rotated squares

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector <string> rotateClkWise(vector <string> & SQ);
int findSQ(vector <string> & SQ1, vector <string> & SQ2);

int main(void)
{
    int N, n;
    while (true) {
        cin >> N >> n;

        if (N == 0 && n == 0)
            break;

        vector <string> SQ1(N);
        vector <string> SQ2(n);

        for (int i = 0; i < N; ++i)
            cin >> SQ1[i];

        for (int i = 0; i < n; ++i)
            cin >> SQ2[i];


        vector <int> result;

        for (int i = 0; i < 4; ++i){
            int tmp = findSQ(SQ1, SQ2);
            result.push_back(tmp);

            SQ2 = rotateClkWise(SQ2);
        }


        cout << result[0] << ' ' << result[1] << ' ' << result[2] << ' ' << result[3] << endl;

    }

    return 0;
}


vector <string> rotateClkWise(vector <string> & SQ)
{
    int n = SQ.size();
    vector <string> result;

    for (int j = 0; j < n; ++j){
        string tmp;
        for (int i = 0; i < n; ++i)
            tmp = SQ[i][j] + tmp;

        result.push_back(tmp);
    }

    return result;
}

int findSQ(vector <string> & SQ1, vector <string> & SQ2)
{
    int N = SQ1.size();
    int n = SQ2.size();
    int result = 0;

    for (int i = 0; i < N - n + 1; ++i)
        for (int j = 0; j < N - n + 1; ++j){
            bool equal = 1;
            for (int x = 0; x < n; ++x)
                for (int y = 0; y < n; ++y)
                    if (SQ2[x][y] != SQ1[i + x][j + y]){
                        equal = 0;
                        break;
                    }

            if (equal)
                ++result;
        }

    return result;
}

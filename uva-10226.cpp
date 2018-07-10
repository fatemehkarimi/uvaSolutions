//uva 10226
//Hardwood Species

#include <iostream>
#include <iomanip>
#include <map>

using namespace std;

int main(void)
{
    int T = 0;
    cin >> T;

    string tree;
    getline(cin, tree);
    getline(cin, tree);

    while (T--) {
        int treeCount = 0;
        map <string, int> trees;

        while (1) {
            getline(cin, tree);

            if (tree == "")
                break;

            ++trees[tree];
            ++treeCount;

        }
        /*for (auto a : trees)
            cout << a.first << ' ' << a.second << ' ' << fixed << setprecision(4) << ((double)a.second / treeCount) * 100 << endl;

        cout << treeCount << endl;*/

        for (auto a : trees)
            cout << a.first << ' ' << fixed << setprecision(4) << ((double)a.second / treeCount) * 100 << endl;

        if (T != 0)
            cout << endl;
    }
    return 0;
}

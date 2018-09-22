//uva 11003
//Boxes

#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int n = 0;
    while (true) {
        cin >> n; 

        if (!n)
            break;

        vector < pair <int, int> > boxes;//first = weight, second = load
        int max_load = 0;
        for (int i = 0; i < n; ++i){
            int x, y;
            cin >> x >> y;

            max_load = max(max_load, y);
            boxes.push_back(make_pair(x, y));
        }

        vector < vector <int> > arr(n, vector <int> (max_load + 1, 0));
        arr[0][boxes[0].second] = 1;

        for (int i = 1; i < n; ++i){
            arr[i][boxes[i].second] = 1;
            for (int j = 0; j < max_load + 1; ++j)
                if (arr[i - 1][j] != 0){
                    arr[i][j] = max(arr[i][j], arr[i - 1][j]);

                    if (j - boxes[i].first >= 0){
                        int load = min(j - boxes[i].first, boxes[i].second);
                        arr[i][load] = max(arr[i][load], arr[i - 1][j] + 1);
                    }
                }
        }

        int maxBox = 0;
        for (auto a : arr[n - 1])
            if (a > maxBox)
                maxBox = a;

        cout << maxBox << endl;
    }
    return 0;
}

//uva 11790
//Murcia’s Skyline

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int lis(vector <int> & heights, vector <int> & width, bool increase);

int main(void)
{
    int T = 0;
    cin >> T;
    int tcounter = 0;
    while (T--) {
        ++tcounter;

        int n = 0;
        cin >> n;

        vector <int> heights(n);
        vector <int> width(n);

        for (int i = 0; i < n; ++i)
            cin >> heights[i];
        for (int i = 0; i < n; ++i)
            cin >> width[i];

        int increase = lis(heights, width, 1);
        int decrease = lis(heights, width, 0);

        if (increase >= decrease)
            cout << "Case " << tcounter << ". Increasing (" << increase << "). Decreasing (" << decrease << ")." << endl;
        else
            cout << "Case " << tcounter << ". Decreasing (" << decrease << "). Increasing (" << increase << ")." << endl;
    }

    return 0;
}

int lis(vector <int> & heights, vector <int> & width, bool increase)
{
    int size = heights.size();
    vector <int> w = width;

    for (int i = 0; i < size; ++i)
        for (int j = 0; j < i; ++j){
            bool conditionSatisfied = 0;

            if (increase && heights[j] < heights[i])
                conditionSatisfied = 1;
            if (!increase && heights[j] > heights[i])
                conditionSatisfied = 1;

            if (conditionSatisfied)
                if (w[j] + width[i] > w[i])
                    w[i] = w[j] + width[i];
        }

    return *max_element(w.begin(), w.end());
}

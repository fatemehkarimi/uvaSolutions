//uva 10131
//Is Bigger Smarter?

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int main(void)
{
    vector <pair <pair <int, int>, int> > elephant;
    int w, iq;

    int n = 0;
    while (cin >> w >> iq)
        elephant.push_back(make_pair(make_pair(w, iq), n++));

    sort(elephant.begin(), elephant.end());

    vector <int> lis(elephant.size(), 1);
    vector <int> pre(elephant.size(), -1);

    for (int i = 1; i < elephant.size(); ++i){
        int wi = elephant[i].first.first;
        int iqi = elephant[i].first.second;

        for (int j = 0; j < i; ++j){
            int wj = elephant[j].first.first;
            int iqj = elephant[j].first.second;

            if (wj < wi && iqi < iqj && lis[i] < lis[j] + 1){
                lis[i] = lis[j] + 1;
                pre[i] = j;
            }
        }
    }

    int index = 0;
    for (int i = 0; i < elephant.size(); ++i)
        if (lis[index] < lis[i])
            index = i;

    stack <int> result;
    while (index >= 0){
        result.push(index);
        index = pre[index];
    }

    cout << result.size() << endl;
    while (!result.empty()){
        cout << elephant[result.top()].second + 1 << endl;
        result.pop();
    }

    return 0;
}

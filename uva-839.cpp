//uva 839
//Not so Mobile

#include <iostream>

using namespace std;

pair <pair <int, int>, bool > CheckTree(void);

int main(void)
{
    int T = 0;
    cin >> T;
    while(T--){
        pair < pair <int, int>, bool> tree = CheckTree();
        if(tree.second)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;

        if(T)
            cout << endl;
    }
    return 0;
}

pair <pair <int, int>, bool > CheckTree(void)
{
    int WL, DL, WR, DR;
    cin >> WL >> DL >> WR >> DR;

    pair <pair <int, int>, bool> node;
    node.second = 1;

    if(WL == 0){
        pair <pair <int, int>, bool> left = CheckTree();
        node.first.first = left.first.first + left.first.second;
        node.second &= left.second;
    }
    else
        node.first.first = WL;

    if(WR == 0){
        pair <pair <int, int>, bool> right = CheckTree();
        node.first.second = right.first.first + right.first.second;
        node.second &= right.second;
    }
    else
        node.first.second = WR;

    if(node.first.first * DL == node.first.second * DR)
        node.second &= 1;
    else
        node.second &= 0;

    return node;
}

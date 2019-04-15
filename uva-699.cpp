//uva 699
//The Falling Leaves

#include <iostream>
#include <map>

using namespace std;

typedef struct node{
    int value;
    int x;
    int y;
    node * left;
    node * right;

    node(){
        left = nullptr;
        right = nullptr;
    }
}node;

node * build_tree(int x, int y);
void preorder_traverse(node * tree, map <int, int> & piles);

int main(void)
{
    int tcounter = 0;
    while(true){
        ++tcounter;
        node * tree = build_tree(0, 0);
        if(tree == nullptr)
            break;

        map <int, int> piles;
        preorder_traverse(tree, piles);
        cout << "Case " << tcounter << ":" << endl;

        auto start = piles.begin();
        cout << start->second;
        ++start;
        for(; start != piles.end(); ++start)
            cout << ' ' << start->second;
        cout << endl << endl;
    }
    return 0; 
}

node * build_tree(int x, int y)
{
    int value;
    cin >> value;

    if(value == -1)
        return nullptr;

    node * new_node = new node();
    new_node->value = value;
    new_node->x = x;
    new_node->y = y;
    new_node->left = build_tree(x - 1, y - 1);
    new_node->right = build_tree(x + 1, y + 1);

    return new_node;
}

void preorder_traverse(node * tree, map <int, int> & piles)
{
    if(tree == nullptr)
        return;

    piles[tree->y] += tree->value;
    preorder_traverse(tree->left, piles);
    preorder_traverse(tree->right, piles);
    return;
}

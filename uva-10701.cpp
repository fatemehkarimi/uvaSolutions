//uva 10701
//Pre, in and post

#include <iostream>
#include <string>

using namespace std;

typedef struct node{
    char value;
    node * left;
    node * right;

    node(){
        left = nullptr;
        right = nullptr;
    }
}node;

node * build_tree(string & preorder, string & inorder, int l_index, int r_index, int & pre_index);
void postorder(node * tree, string & result);

int main(void)
{
    int T = 0;
    cin >> T;
    while(T--){
        int n;
        cin >> n;

        string preorder, inorder;
        cin >> preorder >> inorder;

        int index = 0;
        node * Tree = build_tree(preorder, inorder, 0, n, index);
        string result;
        postorder(Tree, result);
        cout << result << endl;
    }
    return 0;
}

node * build_tree(string & preorder, string & inorder, int l_index, int r_index, int & pre_index)
{
    if(l_index >= r_index)
        return nullptr;

    node * new_node = new node();
    new_node->value = preorder[pre_index];

    int loc = l_index;
    for(; loc < r_index; ++loc)
        if(preorder[pre_index] == inorder[loc])
            break;

    ++pre_index;
    new_node->left = build_tree(preorder, inorder, l_index, loc, pre_index);
    new_node->right = build_tree(preorder, inorder, loc + 1, r_index, pre_index);

    return new_node;
}

void postorder(node * tree, string & result)
{
    if(tree == nullptr)
        return;

    postorder(tree->left, result);
    postorder(tree->right, result);
    result = result + tree->value;
    return;
}

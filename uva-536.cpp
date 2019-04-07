//uva 536
//Tree Recovery

#include <iostream>
#include <vector>

using namespace std;

typedef struct node{
    char value;
    node * left;
    node * right;
}node;

node * build_Tree(string & preorder, string & inorder, pair <int, int> in_pointer, int & pointer);
void post_order(node * tree, string & path);

int main(void)
{
    string preorder, inorder;
    while(cin >> preorder >> inorder){
        int pointer = 0;
        node * tree = build_Tree(preorder, inorder, make_pair(0, (int)inorder.size()), pointer);

        string path;
        post_order(tree, path);
        cout << path << endl;
    }
    return 0;
}

node * build_Tree(string & preorder, string & inorder, pair <int, int> in_pointer, int & pointer)
{
    if(pointer >= (int)preorder.size() || in_pointer.first >= in_pointer.second)
        return nullptr;

    node * new_node = new node;
    new_node->value = preorder[pointer];

    int index = in_pointer.first;
    for(; index < in_pointer.second; ++index)
        if(inorder[index] == preorder[pointer])
            break;

    ++pointer;

    new_node->left = build_Tree(preorder, inorder, make_pair(in_pointer.first, index), pointer);
    new_node->right = build_Tree(preorder, inorder, make_pair(index + 1, in_pointer.second), pointer);

    return new_node;
}

void post_order(node * tree, string & path)
{
    if(tree == nullptr)
        return;

    post_order(tree->left, path);
    post_order(tree->right, path);
    path = path + tree->value;
    return;
}

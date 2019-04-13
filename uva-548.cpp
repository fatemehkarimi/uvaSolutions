//uva 548
//Tree

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <climits>

using namespace std;

typedef struct node
{
    int value;
    node * left;
    node * right;
    node(int _v, node * _l, node * _r){
        value = _v;
        left = _l;
        right = _r;
    }
}node;

node * build_tree(vector <int> & postorder, vector <int> & inorder, int & post_index, int left_in, int right_in);
pair <int, int> preorder(node * tree);

int main(void)
{
    string inorder, postorder;
    while(getline(std::cin, inorder)){
        getline(std::cin, postorder);

        vector <int> inorder_traverse;
        vector <int> postorder_traverse;

        stringstream stream1(inorder);

        int value;
        while (stream1 >> value)
            inorder_traverse.push_back(value);

        stream1.str(postorder);
        stream1.clear();
        while(stream1 >> value)
            postorder_traverse.push_back(value);


        int index = (int)postorder_traverse.size() - 1;
        node * Tree = build_tree(postorder_traverse, inorder_traverse, index, 0, (int)inorder_traverse.size());
        cout << preorder(Tree).second << endl;
    }
    return 0;
}

node * build_tree(vector <int> & postorder, vector <int> & inorder, int & post_index, int left_in, int right_in)
{
    if(left_in >= right_in)
        return nullptr;

    node * new_node = new node(postorder[post_index], nullptr, nullptr);

    int index;
    for(index = left_in; index < right_in; ++index)
        if(inorder[index] == postorder[post_index])
            break;

    --post_index;
    new_node->right = build_tree(postorder, inorder, post_index, index + 1, right_in);
    new_node->left = build_tree(postorder, inorder, post_index, left_in, index);

    return new_node;
}


 pair <int, int> preorder(node * tree)
{
    if(tree->left == nullptr && tree->right == nullptr)
        return make_pair(tree->value, tree->value);

    pair <int, int> left, right;

    if(tree->left == nullptr)
        left = make_pair(INT_MAX, INT_MAX);
    else
        left = preorder(tree->left);

    if(tree->right == nullptr)
        right = make_pair(INT_MAX, INT_MAX);
    else
        right = preorder(tree->right);

    if(left.first == INT_MAX)
        return make_pair(right.first + tree->value, right.second);
    if(right.first == INT_MAX)
        return make_pair(left.first + tree->value, left.second);

    if(left.first < right.first)
        return make_pair(left.first + tree->value, left.second);
    else if(left.first == right.first)
        return make_pair(left.first + tree->value, min(left.second, right.second));
    else
        return make_pair(right.first + tree->value, right.second);
}


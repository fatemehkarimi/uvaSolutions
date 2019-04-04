//uva 112
//Tree Summing

#include <iostream>
#include <string>
#include <stack>

using namespace std;

typedef struct node{
    int value;
    node * left;
    node * right;
}node;

bool check_for_sum(node * tree, int sum);
node * build_tree(string input, int & index);

int main(void)
{
    int n;
    while(cin >> n){
        string input;
        stack <char> string_validness;

        do{
            char c;
            cin >> c;

            if(c == '(')
                string_validness.push('(');
            if(c == ')')
                string_validness.pop();
            input = input + c;
        } while(!string_validness.empty());

        int index = 0;
        node * tree = build_tree(input, index);
        bool result = false;
        if(tree != nullptr)
            result = check_for_sum(tree, n);

        if(result)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
    return 0;
}

node * build_tree(string input, int & index)
{
    ++index;
    if(input[index] == ')'){
        ++index;
        return nullptr;
    }

    node * new_node = new node;
    new_node->value = 0;

    bool negative = false;
    if(input[index] == '-'){
        negative = true;
        ++index;
    }
    while(input[index] >= '0' && input[index] <= '9'){
        new_node->value = new_node->value * 10 + (input[index] - '0');
        ++index;
    }

    if(negative)
        new_node->value *= -1;

    new_node->left = build_tree(input, index);
    new_node->right = build_tree(input, index);
    ++index;//to remove the closing paranthesis
    return new_node;
}

bool check_for_sum(node * tree, int sum)
{
    bool result = false;
    if(tree->left != nullptr){
        tree->left->value += tree->value;
        result |= check_for_sum(tree->left, sum);
    }

    if(tree->right != nullptr){
        tree->right->value += tree->value;
        result |= check_for_sum(tree->right, sum);
    }

    if(tree->left == nullptr && tree->right == nullptr){
        if(tree->value == sum)
            return true;
        else
            return false;
    }
    return result;
}

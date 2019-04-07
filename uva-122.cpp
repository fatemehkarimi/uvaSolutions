//uva 122
//Trees on the level

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

typedef struct node{
    int value;
    node * left;
    node * right;
}node;

bool traverse_tree(node * tree, map <int, bool> tree_values);
void delete_tree(node * tree);

int main(void)
{
    string _pair;
    while(cin >> _pair){
        node * tree = nullptr;
        bool not_complete = false;

        while(_pair != "()"){
            bool value_exists = false;
            int value = 0;
            string path;

            for(int i = 0; i < _pair.size(); ++i)
                if(_pair[i] >= '0' && _pair[i] <= '9'){
                    value_exists = true;
                    value = value * 10 + _pair[i] - '0';
                }
                else if(_pair[i] == 'L' || _pair[i] == 'R')
                    path = path + _pair[i];

            if(tree == nullptr){
                tree = new node;
                tree->value = -1;
                tree->left = nullptr;
                tree->right = nullptr;
            }

            node * tmp = tree;
            for(int i = 0; i < path.size(); ++i)
                if(path[i] == 'L'){
                    if(tmp->left == nullptr){
                        node * left_c = new node;
                        left_c->value = -1;
                        left_c->left = nullptr;
                        left_c->right = nullptr;

                        tmp->left = left_c;
                        tmp = left_c;
                    }
                    else
                        tmp = tmp->left;
                }
                else{
                    if(tmp->right == nullptr){
                        node * right_c = new node;
                        right_c->value = -1;
                        right_c->left = nullptr;
                        right_c->right = nullptr;

                        tmp->right = right_c;
                        tmp = right_c;
                    }
                    else
                        tmp = tmp->right;
                }
            if(value_exists){
                if(tmp->value != -1)
                    not_complete = true;
                tmp->value = value;
            }

            cin >> _pair;
        }

        vector <int> path;
        queue <node *> Queue;

        Queue.push(tree);

        while(!not_complete && !Queue.empty()){
            node * front = Queue.front();
            Queue.pop();
            if(front->value != -1)
                path.push_back(front->value);
            else
                not_complete = 1;

            if(front->left != nullptr)
                Queue.push(front->left);
            if(front->right != nullptr)
                Queue.push(front->right);
        }

        if(not_complete)
            cout << "not complete" << endl;
        else{
            cout << path[0];
            for(int i = 1; i < path.size(); ++i)
                cout << ' ' << path[i];
            cout << endl;
        }

        delete_tree(tree);
        tree = nullptr;
    }
    return 0;
}

void delete_tree(node * tree)
{
    if(tree == nullptr)
        return;

    delete_tree(tree->left);
    delete_tree(tree->right);
    delete tree;

    return;
}


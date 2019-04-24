//uva 11234
//Expressions

#include <iostream>
#include <string>
#include <stack>
#include <queue>

using namespace std;

typedef struct node{
	char value;
	node * left;
	node * right;

	node(){
		left = right = nullptr;
	}
}node;

node * build_tree(string input);
void delete_tree(node * Tree);

int main(void)
{
	int T;
	cin >> T;
	while(T--){
		string postfix;
		cin >> postfix;

		node * Tree = build_tree(postfix);

		string result;
		queue <node *> Queue;
		Queue.push(Tree);

		while(!Queue.empty()){
			node * front = Queue.front();
			Queue.pop();

			result = front->value + result;
			if(front->right != nullptr)
				Queue.push(front->right);
			if(front->left != nullptr)
				Queue.push(front->left);
		}
		cout << result << endl;
		delete_tree(Tree);
	}
	return 0;
}

node * build_tree(string input)
{
	stack <node *> Stack;
	for(int start = 0; start < (int)input.size(); ++start){
		node * new_node = new node();
		new_node->value = input[start];

		if(input[start] >= 'A' && input[start] <= 'Z'){
			node * op1 = Stack.top();
			Stack.pop();
			node * op2 = Stack.top();
			Stack.pop();

			new_node->left = op1;
			new_node->right = op2;
		}
		Stack.push(new_node);
	}
	return Stack.top();
}

void delete_tree(node * Tree)
{
	if(Tree == nullptr)
		return;
	delete_tree(Tree->left);
	delete_tree(Tree->right);

	delete Tree;
}

//uva 11995
//I Can Guess the Data Structure!

#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main(void)
{
	int n = 0;
	while (cin >> n) {
		priority_queue <int> preQue;
		queue <int> Queue;
		stack <int> Stack;

		bool canBe [3] = {1, 1, 1};

		for (int i = 0; i < n; ++i) {
			int insrtruct, value;
			cin >> insrtruct >> value;

			if (insrtruct == 1){
				preQue.push(value);
				Queue.push(value);
				Stack.push(value);
			}
			else {
				int x1 = -1, x2 = -1, x3 = -1;
				if (!preQue.empty()){
					x1 = preQue.top();
					preQue.pop();
				}

				if (!Queue.empty()) {
					x2 = Queue.front();
					Queue.pop();
				}

				if (!Stack.empty()){
					x3 = Stack.top();
					Stack.pop();
				}

				if (x1 != value)
					canBe[0] = 0;
				if (x2 != value)
					canBe[1] = 0;
				if (x3 != value)
					canBe[2] = 0;
			}
		}

		if (canBe[0] && !canBe[1] && !canBe[2])
			cout << "priority queue" << endl;
		else if (!canBe[0] && canBe[1] && !canBe[2])
			cout << "queue" << endl;
		else if (!canBe[0] && !canBe[1] && canBe[2])
			cout << "stack" << endl;
		else if (!canBe[0] && !canBe[1] && !canBe[2])
			cout << "impossible" << endl;
		else
			cout << "not sure" << endl;

	}
	return 0;
}


//uva 12160
//Unlock the Lock

#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int BFS(vector <int> & buttons, int start, int goal);

int main(void)
{
	int tcounter = 0;
	int current_code, goal_code, n_buttons;
	while(true){
		cin >> current_code >> goal_code >> n_buttons;
		if(current_code == 0 && goal_code == 0 && n_buttons == 0)
			break;
		++tcounter;

		vector <int> buttons(n_buttons);
		for(int i = 0; i < n_buttons; ++i)
			cin >> buttons[i];

		int result = BFS(buttons, current_code, goal_code);
		cout << "Case " << tcounter << ": ";
		if(result < 0)
			cout << "Permanently Locked" << endl;
		else
			cout << result << endl;
	}
	return 0;
}

int BFS(vector <int> & buttons, int start, int goal)
{
	int limit = 0;
	queue <int> Queue;
	map <int, int> level;
	level[start] = 0;
	Queue.push(start);

	while(!Queue.empty()){
		++limit;
		if(limit > 10000)
			break;
		
		int front = Queue.front();
		Queue.pop();

		if(front == goal)
			return level[goal];

		for(auto button : buttons){
			int next = (front + button) % 10000;
			if(level.find(next) == level.end()){
				level[next] = level[front] + 1;
				Queue.push(next);
			}
		}
	}
	return -1;
}

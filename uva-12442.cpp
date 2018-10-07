//uva 12442
//Forwarding Emails

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>

using namespace std;

void DFS(map <int, int> & edges, vector <int> & len, int start);

int main(void)
{
	int T = 0;
	cin >> T;
	int tcounter = 0;
	while (T--) {
		int n = 0;
		cin >> n;
		++tcounter;

		map <int, int> edges;

		for (int i = 0; i < n; ++i){
			int t1, t2;
			cin >> t1 >> t2;
			--t1;
			--t2;
			edges[t1] = t2;
		}

		vector <int> len(n, 0);
		for (int i = 0; i < n; ++i)
			if (len[i] == 0)
				DFS(edges, len, i);

		int max_index = 0;
		int max_count = 0;
		for (int i = 0; i < n; ++i)
			if (max_count < len[i]){
				max_count = len[i];
				max_index = i;
			}

		cout << "Case " << tcounter << ": " << max_index + 1 << endl;
	}
	return 0;
}

void DFS(map <int, int> & edges, vector <int> & len, int start)
{
	vector <bool> visited(edges.size(), false);
	stack <int> Stack;
	Stack.push(start);
	visited[start] = true;

	while (true){
		int top = Stack.top();
		int next = edges[top];
		if (!visited[next]){
			if (len[next] != 0)
				break;
			
			Stack.push(next);
			visited[next] = true;
		}
		else {
			int l = 0;
			do {
				++l;
				Stack.pop();
			}while(Stack.top() != next);
			Stack.pop();
			++l;

			int s = next;
			do {
				len[s] = l;
				s = edges[s];
			}while (s != next);

			break;
		}	
	}

	while (!Stack.empty()){
		int top = Stack.top();
		Stack.pop();
		len[top] = len[edges[top]] + 1;
	}

	return;
}

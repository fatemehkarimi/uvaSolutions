//uva 247
//Calling Circles

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <map>
#include <set>

using namespace std;

void dfs(map <string, set <string> > & Graph, string start, map <string, bool> & visited, stack <string> & Stack);
void strongly_connected_component(map <string, set <string> > & Graph, string start, map <string, int> & visited, int code);

int main(void)
{
	int n, m;
	bool new_line = 0;
	int tcounter = 0;
	while(true){
		cin >> n >> m;

		if(n == 0 && m == 0)
			break;

		if(new_line)
			cout << endl;
		new_line = 1;

		++tcounter;

		map <string, set <string> > Graph;
		map <string, set <string> > TGraph;
		map <string, bool> visited;
		map <string, int> components;

		for(int i = 0; i < m; ++i){
			string s1, s2;
			cin >> s1 >> s2;

			Graph[s1].insert(s2);
			TGraph[s2].insert(s1);

			visited[s1] = false;
			visited[s2] = false;

			components[s1] = 0;
			components[s2] = 0;

		}

		stack <string> Stack;
		for(auto a : visited)
			if(!a.second)
				dfs(Graph, a.first, visited, Stack);

		int code = 1;
		while(!Stack.empty()){
			string top = Stack.top();
			Stack.pop();

			if(components[top] == 0){
				strongly_connected_component(TGraph, top, components, code);
				++code;
			}
		}

		cout << "Calling circles for data set " << tcounter << ":" << endl;
		for(int i = 1; i < code; ++i){
			vector <string> component;
			for(auto a : components)
				if(a.second == i)
					component.push_back(a.first);

			cout << component[0];
			for(int j = 1; j < component.size(); ++j)
				cout << ", " << component[j];
			cout << endl;
		}
	}
	return 0;
}

void dfs(map <string, set <string> > & Graph, string start, map <string, bool> & visited, stack <string> & Stack)
{
	visited[start] = 1;

	for(auto a : Graph[start])
		if(!visited[a])
			dfs(Graph, a, visited, Stack);

	Stack.push(start);
	return;
}

void strongly_connected_component(map <string, set <string> > & Graph, string start, map <string, int> & visited, int code)
{
	visited[start] = code;

	for(auto a : Graph[start])
		if(!visited[a])
			strongly_connected_component(Graph, a, visited, code);

	return;
}

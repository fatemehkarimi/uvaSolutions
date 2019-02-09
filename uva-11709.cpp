//uva 11709
//Trust groups

#include <iostream>
#include <string>
#include <stack>
#include <map>
#include <set>

using namespace std;

void dfs(map <string, set <string> > & Graph, string start, map <string, bool> & visited, stack <string> & Stack);
void find_component(map <string, set <string> > & Graph, string start, map <string, int> & visited, int index);

int main(void)
{
	int p, t;
	while(true){
		cin >> p >> t;
		getchar();

		if(p == 0 && t == 0)
			break;

		map <string, set <string> > Graph;
		map <string, set <string> > TGraph;
		map <string, bool> visited;
		map <string, int> component;

		for(int i = 0; i < p; ++i){
			string person;
			getline(std::cin, person);

			set <string> tmp;
			Graph[person] = tmp;
			TGraph[person] = tmp;
			visited[person] = 0;
			component[person] = 0;
		}

		for(int i = 0; i < t; ++i){
			string t1, t2;
			getline(std::cin, t1);
			getline(std::cin, t2);

			Graph[t1].insert(t2);
			TGraph[t2].insert(t1);
		}

		stack <string> Stack;
		for(auto & a : visited)
			if(!a.second)
				dfs(Graph, a.first, visited, Stack);

		int count_componenet = 1;
		while(!Stack.empty()){
			string top = Stack.top();
			Stack.pop();

			if(component[top] == 0){
				find_component(TGraph, top, component, count_componenet);
				++count_componenet;
			}
		}

		cout << count_componenet - 1 << endl;
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

void find_component(map <string, set <string> > & Graph, string start, map <string, int> & visited, int index)
{
	visited[start] = index;

	for(auto a : Graph[start])
		if(!visited[a])
			find_component(Graph, a, visited, index);

	return;
}

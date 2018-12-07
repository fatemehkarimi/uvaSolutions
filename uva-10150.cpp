//uva 10150
//Doublets

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

bool compare(string s1, string s2);
void BFS(vector <vector <int> > & Graph, vector <int> & path, int start, int end);

typedef struct stringcmp{
	bool operator()(string a, string b){
		if(a.size() < b.size())
			return true;

		if(a.size() == b.size())
			return a < b;

		return false;
	}
}stringcmp;

int main(void)
{
	map <int, string> code_words;
	map <string, int, stringcmp> words_code;

	int code = 0;

	while(true){
		string word;
		getline(std::cin, word);

		if(word == "")
			break;

		code_words[code] = word;
		words_code[word] = code;
		++code;
	}
	vector <vector <int> > Graph(code);

	for(auto word1 : words_code){
		auto word2 = words_code.find(word1.first);
		for(; word2 !=words_code.end(); ++word2)
			if(word1.first.size() != word2->first.size())
				break;
			 else if (compare(word1.first, word2->first)){
				Graph[word1.second].push_back(word2->second);
				Graph[word2->second].push_back(word1.second);
			}
	}


	string source, destination;
	bool first = 1;
	while(cin >> source >> destination){
		if(!first)
			cout << endl;

		first = 0;
		

		vector <int> path;
		BFS(Graph, path, words_code[source], words_code[destination]);

		if(path.size() == 0)
			cout << "No solution." << endl;
		else
			for(int i = path.size() - 1; i >= 0; --i)
				cout << code_words[path[i]] << endl;
	}

	return 0;
}

bool compare(string s1, string s2)
{
	int diff = 0;

	if(s1.size() != s2.size())
		return false;

	for(int i = 0; i < s1.size(); ++i)
		if(s1[i] != s2[i])
			++diff;

	if(diff == 1)
		return true;

	return false;
}

void BFS(vector <vector <int> > & Graph, vector <int> & path, int start, int end)
{
	int n = Graph.size();
	vector <int> parent(n, -1);
	vector <bool> visited(n, false);

	visited[start] = 1;
	queue <int> Queue;
	Queue.push(start);

	while(!Queue.empty()){
		int front = Queue.front();
		Queue.pop();

		for(auto a : Graph[front])
			if(!visited[a]){
				visited[a] = true;
				parent[a] = front;
				Queue.push(a);
			}
	}

	if(!visited[end])
		return;

	path.push_back(end);
	int e = parent[end];
	while(e != -1 && parent[e] != -1){
		path.push_back(e);
		e = parent[e];
	}
	path.push_back(start);

	return;
}

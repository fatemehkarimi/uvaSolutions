//uva 10044
//Erdös Numbers

#include <iostream>
#include <climits>
#include <string>
#include <vector>
#include <string>
#include <queue>
#include <map>

using namespace std;

void BFS(vector <vector <int> > & Graph, int root, vector <int> & level);

int main(void)
{
	int T = 0, scenario = 0;
	cin >> T;
	while(T--){
		int p, n;
		cin >> p >> n;
		getchar();

		vector < vector <int> > Graph;
		map <string, int> name_code;
		map <int, string> code_name;
		int num_name = 0;

		for(int i = 0; i < p; ++i){
			string paper;
			int comma_counter = 0;
			vector <int> connected;
			getline(std::cin, paper);
			string author;

			for(int i = 0; i < paper.size(); ++i)
				if(paper[i] == ',' || paper[i] == ':'){
					++comma_counter;
					if(comma_counter % 2 == 0){
						if(name_code.find(author) == name_code.end()){
							vector <int> edges;
							Graph.push_back(edges);
							name_code[author] = num_name;
							code_name[num_name++] = author;
						}
						connected.push_back(name_code[author]);
						author.clear();
						++i;//skipping whitespace
					}
					else
						author += paper[i];

					if(paper[i] == ':')
						break;
				}
				else
					author += paper[i];

			for(int j = 0; j < connected.size(); ++j)
				for(int k = 0; k < connected.size(); ++k)
					if(k != j)
						Graph[connected[j]].push_back(connected[k]);
		}
		
		vector <int> level(Graph.size(), INT_MAX);
		BFS(Graph, name_code["Erdos, P."], level);

		++scenario;
		cout << "Scenario " << scenario << endl;

		for(int i = 0; i < n; ++i){
			string name;
			getline(std::cin, name);
			int result;

			if(name_code.find(name) == name_code.end())
				result = INT_MAX;
			else
				result = level[name_code[name]];
			if(result != INT_MAX)
				cout << name << ' ' << result << endl;
			else
				cout << name << ' ' << "infinity" << endl;
		}
	}
	return 0;
}

void BFS(vector <vector <int> > & Graph, int root, vector <int> & level)
{
	level[root] = 0;
	queue <int> Queue;
	Queue.push(root);

	while(!Queue.empty()){
		int front = Queue.front();
		Queue.pop();

		for(auto a : Graph[front])
			if(level[a] == INT_MAX){
				level[a] = level[front] + 1;
				Queue.push(a);
			}
	}
	return;
}

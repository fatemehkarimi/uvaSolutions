//uva 259
//Software allocation

#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

bool move(map <char, vector <int> > & Graph, vector <char> & result, map <char, bool> & visited, char problem);

int main(void)
{
	string str;
	while (getline(cin, str)){
		map <char, vector <int> > problem;
		map <char, int> counts;

		while (1) {
			if (str == "")
				break;

			for (unsigned int i = 3; i < str.size() - 1; ++i)
				problem[str[0]].push_back(str[i] - '0');

			counts[str[0]] = str[1] - '0';
			getline(cin, str);

		}



		vector <char> result(10, '_');

		bool ok = 1;

		for (auto a : problem){
			if (!ok)
				break;

			char p = a.first;
			vector <int> comp = a.second;

			for (int i = 0; i < counts[p]; ++i){
				map <char, bool> visited;
				for (auto a : counts)
					visited[a.first] = 0;//initializing

				bool found = move(problem, result, visited, p);


				if (!found){
					ok = 0;
					break;
				}
			}
		}

		if (!ok)
			cout << "!";
		else
			for (auto a : result)
				cout << a;

		cout << endl;
	}

	return 0;
}


bool move(map <char, vector <int> > & Graph, vector <char> & result, map <char, bool> & visited, char problem)
{
	visited[problem] = true;
	vector <int> possibleComps = Graph[problem];
	for (auto a : possibleComps)
		if (result[a] == '_'){
			result[a] = problem;
			return 1;
		}

	/*for (auto a : visited)
		cout << a.first << ' ' << a.second << endl;*/


	for (auto a : possibleComps)
		if (!visited[result[a]] && move(Graph, result, visited, result[a])){
			result[a] = problem;
			return 1;
		}

	return 0;
}

//uva 10113
//Exchange Rates

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

int gcd(int a, int b);
pair <bool, pair <int, int> >  DFS(map < string, map <string, pair <int, int> > > & relations
		, string & start, string & end);
pair <bool, pair <int, int> > DFS(map < string, map <string, pair <int, int> > > & relations
								, map <string, bool> & visited, string & start, string & end);

int main(void)
{
	map < string, map <string, pair <int, int> > > relations;
	while (true) {
		char order;
		cin >> order;

		if (order == '!') {
			int n1, n2;
			string s1, s2;

			cin >> n1 >> s1;

			char trash;
			cin >> trash;

			cin >> n2 >> s2;
			int G = gcd(n1, n2);

			n1 /= G;
			n2 /= G;

			relations[s1].insert(make_pair(s2, make_pair(n1, n2)));
			relations[s2].insert(make_pair(s1, make_pair(n2, n1)));

		}
		else if (order == '?') {

			string s1, s2;
			cin >> s1;

			char trash;
			cin >> trash;

			cin >> s2;

			pair <bool, pair<int, int> > result = DFS(relations, s1, s2);
			if (result.first)
				cout << result.second.first << ' ';
			else
				cout << "? ";

			cout << s1 << " = ";

			if (result.first)
				cout << result.second.second << ' ';
			else
				cout << "? ";

			cout << s2 << endl;

		}
		else 
			break;
	}
	return 0;
}

pair <bool, pair <int, int> >  DFS(map < string, map <string, pair <int, int> > > & relations
		, string & start, string & end)
{
	map <string, bool> visited;
	for (auto a : relations)
		visited.insert(make_pair(a.first, 0));

	return DFS(relations, visited, start, end);
}

pair <bool, pair <int, int> > DFS(map < string, map <string, pair <int, int> > > & relations
								, map <string, bool> & visited, string & start, string & end)
{
	visited[start] = 1;
	for (auto a : relations[start])
		if (a.first == end)
			return make_pair(1, a.second);
		else if (!visited[a.first]){
			string next = a.first;
			pair <bool, pair <int, int> > result = DFS(relations, visited, next, end);

			if (result.first){
				int x = result.second.first * a.second.first;
				int y = result.second.second * a.second.second;

				int G = gcd(x, y);
				x /= G;
				y /= G;
				return make_pair(1, make_pair(x, y));
			}
		}

	return make_pair(0, make_pair(0, 0));
}


int gcd(int a, int b)
{
	while (b != 0){
		int r = a % b;
		a = b;
		b = r;
	}

	return a;
}

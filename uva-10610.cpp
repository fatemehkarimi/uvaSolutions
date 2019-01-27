//uva 10610
//Gopher and Hawks

#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <cmath>
#include <queue>

using namespace std;

double distance(pair <double, double> & first, pair <double, double> & second);
void BFS(vector < vector <bool> > & Graph, vector <int> & level, int start);

int main(void)
{
	int v, m;
	while(true){
		cin >> v >> m;
		m *= 60;//change it to seconds

		if(v == 0 && m == 0) break;

		vector < pair <double, double> > holes;
		double x_s, y_s;
		double x_e, y_e;

		cin >> x_s >> y_s >> x_e >> y_e;

		holes.push_back(make_pair(x_s, y_s));//source node index is 0
		holes.push_back(make_pair(x_e, y_e));//target node index is 1
		getchar();

		while(true){
			string input;
			getline(std::cin, input);

			if(input == "") break;

			stringstream hole(input);
			double x_h, y_h;

			hole >> x_h;
			hole >> y_h;

			holes.push_back(make_pair(x_h, y_h));
		}

		vector < vector <bool> > Graph(holes.size(), vector <bool> (holes.size(), false));

		for(int i = 0; i < holes.size(); ++i)
			for(int j = 0; j < holes.size(); ++j){
				double dis = distance(holes[i], holes[j]);

				if((dis / (double)v) <= (double)m)
					Graph[i][j] = 1;
			}

		vector <int> level(Graph.size(), -1);
		BFS(Graph, level, 0);

		if(level[1] == -1)
			cout << "No." << endl;
		else
			cout << "Yes, visiting " << level[1] - 2 << " other holes." << endl;
	}
	return 0;
}

double distance(pair <double, double> & first, pair <double, double> & second)
{
	double tmp = (first.first - second.first) * (first.first - second.first)
	+ (first.second - second.second) * (first.second - second.second);
	return sqrt(tmp);
}


void BFS(vector < vector <bool> > & Graph, vector <int> & level, int start)
{
	vector <bool> visited(Graph.size(),false);
	queue <int> Queue;

	visited[start] = 1;
	level[start] = 1;
	Queue.push(start);

	while(!Queue.empty()){
		int i = Queue.front();
		Queue.pop();

		for(int j = 0; j < Graph.size(); ++j)
			if(Graph[i][j] && !visited[j]){
				visited[j] = true;
				level[j] = level[i] + 1;
				Queue.push(j);
			}
	}

	return;
}

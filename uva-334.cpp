//uva 334
//Identifying Concurrent Events

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

void cuncurrent_recog(map <int, vector <int> > Graph, map <int, int> incomming_edges, vector < vector <bool> > & cuncurrency);

int main(void)
{
	int n = 0;
	int T = 0;
	while(true){
		cin >> n;
		if(n == 0) break;
		++T;

		map <int, vector <int> > Graph;
		map <int, string> code_event;
		map <string, int> event_code;
		int n_event = 0;

		//sequentional events
		for(int i = 0; i < n; ++i){
			int nn;
			cin >> nn;

			vector <int> sequentional;

			for(int j = 0; j < nn; ++j){
				string event;
				cin >> event;

				if(event_code.find(event) == event_code.end()){
					code_event[n_event] = event;
					event_code[event] = n_event;
					++n_event;
				}

				sequentional.push_back(event_code[event]);
			}

			for(int i = 0; i < (int)sequentional.size() - 1; ++i)
				Graph[sequentional[i]].push_back(sequentional[i + 1]);
		}

		//messages
		cin >> n;
		for(int i = 0; i < n; ++i){
			string e1, e2;
			cin >> e1 >> e2;

			Graph[event_code[e1]].push_back(event_code[e2]);
		}

		vector < vector <bool> > sequentional(n_event, vector <bool> (n_event, false));

		for(auto a : Graph)
			for(auto b : a.second)
				sequentional[a.first][b] = true;

		for(int k = 0; k < n_event; ++k)
			for(int i = 0; i < n_event; ++i)
				for(int j = 0; j < n_event; ++j)
					if(sequentional[i][k] & sequentional[k][j])
						sequentional[i][j] = true;


		int count_concur = 0;
		vector <pair <int, int> > result;

		for(int i = 0; i < n_event; ++i)
			for(int j = 0; j < i; ++j)
				if(sequentional[i][j] == false && sequentional[j][i] == false){
					++count_concur;
					result.push_back(make_pair(i, j));
				}

		cout << "Case " << T << ", ";
		if(count_concur == 0)
			cout << "no concurrent events." << endl;
		else{
			cout << count_concur << " concurrent events:" << endl;
			for(int i = 0; i < min((int)result.size(), 2); ++i)
			cout << '(' << code_event[result[i].first] << ',' << code_event[result[i].second] << ") ";
			cout << endl;
		}

	}
	return 0;
}

//uva 872
//Ordering

//solution was written with the aim of this link:
//https://github.com/morris821028/UVa/blob/master/volume001/124%20-%20Following%20Orders.cpp

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

void DFS(vector < vector <bool> > & Map, vector <bool> & variables, vector <bool> & visited, int index, int n, string result, bool & order_found);

int main(void)
{
    int T = 0;
    cin >> T;
    getchar();
    while(T--){
        getchar();

        string line;
        int n = 0;
        getline(std::cin, line);
        stringstream ss(line);

        vector <bool> variables(26, false);
        char tmp1, tmp2, tmp3;
        while(ss >> tmp1){
            ++n;
            variables[tmp1 - 'A'] = true;
        }

        vector < vector <bool> > Map(26, vector <bool> (26, false));

        getline(std::cin, line);
        ss.str("");
        ss.clear();
        ss << line;

        while(ss >> tmp1 >> tmp2 >> tmp3)
            Map[tmp1 - 'A'][tmp3 - 'A'] = true;

        bool order_found = 0;
        vector <bool> used(26, false);
        string result(n, ' ');
        DFS(Map, variables, used, 0, n, result, order_found);

        if(!order_found)
            cout << "NO" << endl;

        if(T) cout << endl;

    }
    return 0;
}

void DFS(vector < vector <bool> > & Map, vector <bool> & variables, vector <bool> & visited, int index, int n, string result, bool & order_found)
{
    if(index == n){
        cout << result[0];
        for(int i = 1; i < n; ++i)
            cout << ' ' << result[i];
        cout << endl;
        order_found = 1;
        return;
    }

    for(int i = 0; i < 26; ++i)
        if(variables[i] && !visited[i]){

            for(int j = 0; j < 26; ++j)
                if(Map[i][j] && visited[j])
                    return;

            visited[i] = 1;
            result[index] = (char)(i + 'A');
            DFS(Map, variables, visited, index + 1, n, result, order_found);
            visited[i] = 0;
        }
}

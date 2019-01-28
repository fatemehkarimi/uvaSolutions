//uva 124
//Following Orders

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <set>

using namespace std;

void readVar(map <char, string> & Graph, map <char, int> & incommingEdge, string & input);
void makeRelation(map <char, string> & Graph, map <char, int> & incommingEdge, string & input);
void allTopologicalSorts(map <char, string> & Graph, map <char, int> & incommingEdge);
void getTopologicalSort(map <char, string> & Graph, map <char, int> incommingEdge,
                        map <char, bool> visited, char start, set <string> & topos, string result);

int main(void)
{
    string input;
    bool new_line = false;
    while(getline(std::cin, input)){
        if(new_line) cout << endl;
        new_line = 1;
        map <char, string> Graph;
        map <char, int> incommingEdge;

        readVar(Graph, incommingEdge, input);
        getline(std::cin, input);
        makeRelation(Graph, incommingEdge, input);
        allTopologicalSorts(Graph, incommingEdge);
    }
    return 0;
}


void readVar(map <char, string> & Graph, map <char, int> & incommingEdge, string & input)
{
    stringstream ss(input);
    char tmp;
    string str;
    while(ss >> tmp){
        Graph[tmp] = str;
        incommingEdge[tmp] = 0;
    }

    return;
}

void makeRelation(map <char, string> & Graph, map <char, int> & incommingEdge, string & input)
{
    stringstream ss(input);
    char tmp1, tmp2;
    while(ss >> tmp1){
        ss >> tmp2;

        Graph[tmp1].push_back(tmp2);
        ++incommingEdge[tmp2];
    }

    return;
}

void allTopologicalSorts(map <char, string> & Graph, map <char, int> & incommingEdge)
{
    set <string> topos;
    map <char, bool> visited;

    for(auto a : incommingEdge)
        visited[a.first] = false;

    for(auto a : incommingEdge)
        if(a.second == 0)
            getTopologicalSort(Graph, incommingEdge, visited, a.first, topos, "");

    for(auto a : topos)
        cout << a << endl;

    return;
}

void getTopologicalSort(map <char, string> & Graph, map <char, int> incommingEdge,
                        map <char, bool> visited, char start, set <string> & topos, string result)
{
    result = result + start;
    visited[start] = true;

    for(auto a : Graph[start])
        incommingEdge[a]--;

    bool leaf = true;
    for(auto a : incommingEdge)
        if(!visited[a.first] && a.second == 0){
            leaf = false;
            getTopologicalSort(Graph, incommingEdge, visited, a.first, topos, result);
        }

    if(leaf)
        topos.insert(result);

    return;
}

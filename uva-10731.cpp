//uva 10731
//Test

#include <iostream>
#include <vector>
#include <stack>
#include <set>

using namespace std;

void dfs(vector < set <int> > & Graph, vector <int> & ids, vector <int> & low_link,
        vector <bool> & onStack, stack <int> & Stack, int start);

int main(void)
{
    int n = 0;
    bool new_line = 0;
    while(true){
        cin >> n;
        if(n == 0)
            break;

        if(new_line)
            cout << endl;
        new_line = 1;

        vector <bool> activities(26, false);
        vector <set <int> > Graph(26);

        for(int i = 0; i < n; ++i){
            vector <int> tmp;
            char c;
            for(int j = 0; j < 5; ++j){
                cin >> c;
                tmp.push_back(c - 'A');
                activities[c - 'A'] = 1;
            }
            cin >> c;
            activities[c - 'A'] = 1;
            for(auto a : tmp)
                Graph[c - 'A'].insert(a);
        }

        //Tarjan algorithm
        vector <int> ids(26, -1);
        vector <int> low_link(26, -1);
        vector <bool> onStack(26, false);
        stack <int> Stack;

        for(int i = 0; i < 26; ++i)
            if(ids[i] == -1)
                dfs(Graph, ids, low_link, onStack, Stack, i);

        for(int i = 0; i < 26; ++i)
            if(activities[i]){
                vector <int> tmp;

                for(int j = 0; j < 26; ++j)
                    if(activities[j] && low_link[j] == low_link[i]){
                        tmp.push_back(j);
                        activities[j] = false;
                    }

                cout << (char)(tmp[0] + 'A');
                for(int j = 1; j < tmp.size(); ++j)
                    cout << ' ' << (char)(tmp[j] + 'A');
                cout << endl;
            }
    }
    return 0;
}

void dfs(vector < set <int> > & Graph, vector <int> & ids, vector <int> & low_link,
        vector <bool> & onStack, stack <int> & Stack, int start)
{
    static int id = 0;
    ids[start] = low_link[start] = id++;
    Stack.push(start);
    onStack[start] = true;

    for(auto a : Graph[start]){
        if(ids[a] == -1)
            dfs(Graph, ids, low_link, onStack, Stack, a);

        if(onStack[a])
            low_link[start] = min(low_link[start], low_link[a]);
    }

    if(ids[start] == low_link[start]){
        while(true){
            int top = Stack.top();
            Stack.pop();
            onStack[top] = false;
            low_link[top] = low_link[start];
            if(top == start)
                break;
        }
    }
    return;
}

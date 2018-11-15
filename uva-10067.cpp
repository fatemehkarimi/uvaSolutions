//uva 10067
//Playing with Wheels

#include <iostream>
#include <string>
#include <map>
#include <set>
#include <queue>

using namespace std;

int getConfig(void);
int toNumber(string a);
int BFS(vector < vector <int> > & Graph, int start, int end);
string standard(string num);

int main(void)
{
    int T = 0;
    cin >> T;
    while(T--){
        int init = getConfig();
        int target = getConfig();

        set <int> forbidden;
        int n;
        cin >> n;
        for(int i = 0; i < n; ++i)
            forbidden.insert(getConfig());

        vector < vector <int> > Graph(10000);

        for(int i = 0; i < 10000; ++i){
            string num = std::to_string(i);
            num = standard(num);

            for(int j = 0; j < 4; ++j){
                string n1 = num;
                n1[j] = ((num[j] - '0') + 1) % 10 + '0';
                int n11 = toNumber(n1);

                if(forbidden.find(n11) == forbidden.end())
                    Graph[i].push_back(n11);

                string n2 = num;
                n2[j] = ((num[j] - '0') - 1 + 10) % 10 + '0';
                int n22 = toNumber(n2);

                if(forbidden.find(n22) == forbidden.end())
                    Graph[i].push_back(n22);
            }
        }

        cout << BFS(Graph, init, target) << endl;
    }
    return 0;
}

int toNumber(string a)
{
    return (a[0] - '0') * 1000 + (a[1] - '0') * 100 + (a[2] - '0') * 10 + (a[3] - '0');
}

string standard(string num)
{
    int size = num.size();
    for(int i = 0; i < 4 - size; ++i)
        num = '0' + num;

    return num;
}

int getConfig(void)
{
    int x1, x2, x3, x4;
    cin >> x1 >> x2 >> x3 >> x4;

    int result = x4 + x3 * 10 + x2 * 100 + x1 * 1000;
    return result;
}

int BFS(vector < vector <int> > & Graph, int start, int end)
{
    vector <int> distance(Graph.size(), -1);
    distance[start] = 0;

    queue <int> Queue;
    Queue.push(start);

    while(!Queue.empty()){
        int front = Queue.front();
        Queue.pop();

        for(auto a : Graph[front])
            if(distance[a] == -1){//not visited
                distance[a] = distance[front] + 1;
                Queue.push(a);
            }
    }

    return distance[end];
}

//uva 115
//Climbing Trees

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int isParent(map <string, vector <string> > & parent_Tree, string source, string destin);
pair <int, int> isCousin(map <string, vector <string> > & parent_Tree, map <string, vector <string> > & child_Tree, string p1, string p2);
string parentRelation(int level);
string childRelation(int level);

int main(void)
{
    map <string, vector <string> > parent_Tree;
    map <string, vector <string> > child_Tree;

    while(true){
        string child, parent;
        cin >> child >> parent;

        if(child == "no.child" && parent == "no.parent")
            break;

        parent_Tree[parent].push_back(child);
        child_Tree[child].push_back(parent);
    }

    string person1, person2;
    while(cin >> person1 >> person2){
        if((parent_Tree.find(person1) == parent_Tree.end() && child_Tree.find(person1) == child_Tree.end())
            || (parent_Tree.find(person2) == parent_Tree.end() && child_Tree.find(person2) == child_Tree.end())){
            cout << "no relation" << endl;
            continue;
        }

        int a1 = isParent(parent_Tree, person1, person2);
        int a2 = isParent(parent_Tree, person2, person1);

        if(a1 > 0){
            cout << parentRelation(a1) << endl;
            continue;
        }
        else if(a2 > 0){
            cout << childRelation(a2) << endl;
            continue;
        }

        pair <int, int> cousin = isCousin(parent_Tree, child_Tree, person1, person2);
        //cout << cousin.first << ' ' << cousin.second << endl;
        
        if(cousin.first == -1 && cousin.second == -1){
            cout << "no relation" << endl;//covers any remaining case
            continue;
        }
        if(cousin.first == 1 && cousin.second == 1)
            cout << "sibling" << endl;
        else{
                if(cousin.first == cousin.second)
                    cout << cousin.first - 1 << " cousin" << endl;
                else
                    cout << min(cousin.first, cousin.second) - 1 << " cousin removed " << abs(cousin.first - cousin.second) << endl;
        }
    }
    return 0;
}

int isParent(map <string, vector <string> > & parent_Tree, string source, string destin)
{
    map <string, int> levels;

    levels[source] = 0;

    queue <string> Queue;
    Queue.push(source);

    while(!Queue.empty()){
        string front = Queue.front();
        Queue.pop();

        for(auto a : parent_Tree[front]){
                Queue.push(a);
                levels[a] = levels[front] + 1;
        }
    }

    if(levels.find(destin) != levels.end())
        return levels[destin];
    else
        return -1;
}

pair <int, int> isCousin(map <string, vector <string> > & parent_Tree, map <string, vector <string> > & child_Tree, string p1, string p2)
{
    int m = -1, n = -1;
    map <string, int> levels;

    levels[p1] = 0;

    queue <string> Queue;
    Queue.push(p1);

    while(!Queue.empty()){
        string front = Queue.front();
        Queue.pop();

        bool found = false;

        for(auto a : child_Tree[front]){
                Queue.push(a);
                levels[a] = levels[front] + 1;
                int level_n = isParent(parent_Tree, a, p2);

                if(level_n != -1){
                    m = levels[a];
                    n = level_n;
                    found = true;
                    break;
                }
        }

        if(found)
            break;
    }

    return make_pair(m, n);
}

string parentRelation(int level)
{
    if(level == 1)
        return "parent";
    else if(level == 2)
        return "grand parent";

    string result = "grand parent";
    for(int i = 3; i <= level; ++i)
        result = "great " + result;
    return result;
}

string childRelation(int level)
{
    if(level == 1)
        return "child";
    else if(level == 2)
        return "grand child";

    string result = "grand child";
    for(int i = 3; i <= level; ++i)
        result = "great " + result;
    return result;
}

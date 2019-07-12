//uva 11049
//Basic wall maze

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>

using namespace std;

void BFS(vector <vector <bool> > & Graph, vector <vector <int> > & Parent,
         map <pair <int, int>, set <pair <int, int> > > & home_wall,
         int xS, int yS, int xE, int yE);

int x_dir[] = {-1, 0, 1, 0};
int y_dir[] = {0, -1, 0, 1};

int main(void)
{
    int xS, yS, xE, yE;
    while(cin >> yS >> xS, xS){
        cin >> yE >> xE;
        --xS, --yS, --xE, --yE;
        vector < pair <int, int> > wall_start(3);
        vector < pair <int, int> > wall_end(3);

        for(int i = 0; i < 3; ++i){
            int x1, y1, x2, y2;
            cin >> y1 >> x1 >> y2 >> x2;
            wall_start[i] = make_pair(x1, y1);
            wall_end[i] = make_pair(x2, y2);
        }

        map <pair <int, int>, set <pair <int, int> > > home_wall;
        for(int i = 0; i  <3; ++i)
            if(wall_start[i].first == wall_end[i].first){//case when wall is horizontal
                int row = wall_start[i].first;
                for(int p = wall_start[i].second; p < wall_end[i].second; ++p){
                    home_wall[make_pair(row - 1, p)].insert(make_pair(row, p));
                    home_wall[make_pair(row, p)].insert(make_pair(row - 1, p));
                }
            }
            else{//when wall is vertical
                int col = wall_start[i].second;
                for(int p = wall_start[i].first; p < wall_end[i].first; ++p){
                    home_wall[make_pair(p, col - 1)].insert(make_pair(p, col));
                    home_wall[make_pair(p, col)].insert(make_pair(p, col - 1));
                }
            }

        vector <vector <bool> > Graph(6, vector <bool>(6, 0));
        vector <vector <int> > Parent(6, vector <int>(6, -1));
        BFS(Graph, Parent, home_wall, xS, yS, xE, yE);
        
        string Path;
        while(xE != xS || yE != yS){
            int direction = Parent[xE][yE];
            if(direction == 0)
                Path = 'S' + Path;
            else if(direction == 1)
                Path = 'E' + Path;
            else if(direction == 2)
                Path = 'N' + Path;
            else
                Path = 'W' + Path;

            xE = xE + x_dir[direction];
            yE = yE + y_dir[direction];
        }
        cout << Path << endl;
    }
    return 0;
}

void BFS(vector <vector <bool> > & Graph, vector <vector <int> > & Parent,
         map <pair <int, int>, set <pair <int, int> > > & home_wall,
         int xS, int yS, int xE, int yE)
{
    int m = Graph.size();
    int n = Graph[0].size();

    queue <pair <int, int> > Queue;
    Queue.push(make_pair(xS, yS));
    Graph[xS][yS] = 1;//visited
    while(!Queue.empty()){
        pair <int, int> front = Queue.front();
        Queue.pop();

        if(front.first == xE && front.second == yE)
            return;

        for(int i = 0; i < 4; ++i){
            int x_n = front.first + x_dir[i];
            int y_n = front.second + y_dir[i];

            if(x_n >= 0 && x_n < m && y_n >= 0 && y_n < n && !Graph[x_n][y_n]){
                //if there is a wall between 2 adjacent home-> continue
                if(home_wall[front].find(make_pair(x_n, y_n)) != home_wall[front].end())
                    continue;

                Graph[x_n][y_n] = true;
                Parent[x_n][y_n] = (i + 2) % 4;
                Queue.push(make_pair(x_n, y_n));
            } 
        }
    }
    return;
}

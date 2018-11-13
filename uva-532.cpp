//uva 532
//Dungeon Master

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int BFS(vector < vector <string> > & cube, int xs, int ys, int zs, int xd, int yd, int zd);

int main(void)
{
    int l, r, c;
    while(true){
        cin >> l >> r >> c;

        if(l == 0 && r == 0 && c == 0)
            break;

        vector < vector <string> >  cube(l, vector <string> (r));

        int xs, ys, zs;
        int xd, yd, zd;

        for(int i = 0; i < l; ++i)
            for(int j = 0; j < r; ++j){
                string tmp;
                cin >> tmp;

                for(int k = 0; k < c; ++k)
                    if(tmp[k] == 'S'){
                        xs = i;
                        ys = j;
                        zs = k;
                        tmp[k] = '.';
                    }
                    else if(tmp[k] == 'E'){
                        xd = i;
                        yd = j;
                        zd = k;
                        tmp[k] = '.';
                    }

                cube[i][j] = tmp;
            }

        int min_minute = BFS(cube, xs, ys, zs, xd, yd, zd);

        if(min_minute == -1)
            cout << "Trapped!" << endl;
        else
            cout << "Escaped in " << min_minute << " minute(s)." << endl;
    }
    return 0;
}

int BFS(vector < vector <string> > & cube, int xs, int ys, int zs, int xd, int yd, int zd)
{
    int l = cube.size();
    int r = cube[0].size();
    int c = cube[0][0].size();

    vector < vector < vector <int> > > distance(l, vector < vector <int> > (r, vector <int> (c, -1)));
    distance[xs][ys][zs] = 0;

    queue < pair < pair<int, int>, int > > Queue;
    Queue.push(make_pair(make_pair(xs, ys), zs));
    cube[xs][ys][zs] = '#';

    while(!Queue.empty()){
        int xt = Queue.front().first.first;
        int yt = Queue.front().first.second;
        int zt = Queue.front().second;

        Queue.pop();

        int disT = distance[xt][yt][zt];

        int ys[4] = {-1, 0, 0, 1};
        int zs[4] = {0, -1, 1, 0};

        for(int i = 0; i < 4; ++i){
            int ny = yt + ys[i];
            int nz = zt + zs[i];

            if(ny >= 0 && ny < r && nz >= 0 && nz < c && cube[xt][ny][nz] == '.'){
                distance[xt][ny][nz] = disT + 1;
                Queue.push(make_pair(make_pair(xt, ny), nz));
                cube[xt][ny][nz] = '#';
            }
        }

        if(xt - 1 >= 0 && cube[xt - 1][yt][zt] == '.'){
            distance[xt - 1][yt][zt] = disT + 1;
            Queue.push(make_pair(make_pair(xt - 1, yt), zt));
            cube[xt - 1][yt][zt] = '#';
        }

        if(xt + 1 < l && cube[xt + 1][yt][zt] == '.'){
            distance[xt + 1][yt][zt] = disT + 1;
            Queue.push(make_pair(make_pair(xt + 1, yt), zt));
            cube[xt + 1][yt][zt] = '#';
        }
    }

    return distance[xd][yd][zd];
}

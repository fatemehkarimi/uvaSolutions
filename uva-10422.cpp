//uva 10422
//Knights in FEN

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>

using namespace std;

bool compareGoal(string state);
pair <int, int> empty_square(string & a);

int main(void)
{
    int T = 0;
    cin >> T;
    getchar();

    while(T--){
        string board;
        for(int i = 0; i < 5; ++i){
            string tmp;
            getline(std::cin, tmp);
            board += tmp;
        }

        map <string, bool> visited;
        queue <pair <int, string> > Queue;

        int horse_move_x[] = {-2, -2, -1, -1, 1, 1, 2, 2};
        int horse_move_y[] = {-1, 1, -2, 2, -2, 2, -1, 1};
        int step = -1;

        if(compareGoal(board))
            step = 0;
        else{
            Queue.push(make_pair(0, board));
            visited[board] = 1;
        }

        while(!Queue.empty()){
            int level = Queue.front().first;
            string state = Queue.front().second;
            Queue.pop();

            pair <int, int> xy = empty_square(state);

            bool found = 0;
            bool exceeded = 0;

            for(int i = 0; i < 8; ++i){
                int nx = xy.first + horse_move_x[i];
                int ny = xy.second + horse_move_y[i];

                if(nx >= 0 && nx < 5 && ny >= 0 && ny < 5){
                    string new_state = state;
                    new_state[nx * 5 + ny] = ' ';
                    new_state[xy.first * 5 + xy.second] = state[nx * 5 + ny];

                    if(!visited[new_state]){
                        visited[new_state] = 1;
                        if(compareGoal(new_state)){
                            step = level + 1;
                            found = 1;
                            break;
                        }

                        if(level + 1 >= 11){
                            exceeded = 1;
                            break;
                        }

                        Queue.push(make_pair(level + 1, new_state));
                    }
                }
            }

            if(found) break;
            if(exceeded) break;
        }

        if(step == -1)
            cout << "Unsolvable in less than 11 move(s)." << endl;
        else
            cout << "Solvable in " << step << " move(s)." << endl;
    }
    return 0;
}


bool compareGoal(string state)
{
    string goal;
    goal = "11111";
    goal += "01111";
    goal += "00 11";
    goal += "00001";
    goal += "00000";

    for(int i = 0; i < 25; ++i)
        if(goal[i] != state[i])
            return false;

    return true;
}

pair <int, int> empty_square(string & a)
{
    for(int i = 0; i < 25; ++i)
        if(a[i] == ' '){
            int x = i / 5;
            int y = i % 5;

            return make_pair(x, y);
        }

    return make_pair(-1, -1);
}

//uva 925
//No more prerequisites, please!

#include <iostream>
#include <climits>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main(void)
{
    int T = 0;
    cin >> T;
    while(T--){
        int n;
        cin >> n;

        map <int, string> code_course;
        map <string, int> course_code;

        vector <vector <int> > max_count_ways(n, vector <int>(n, 0));
        for(int i = 0; i < n; ++i){
            string course;
            cin >> course;
            course_code[course] = 0;
        }
        //sorting courses
        auto a = course_code.begin();
        for(int i = 0; i < n; ++i){
            a->second = i;
            code_course[i] = a->first;
            ++a;
        }

        int m;
        cin >> m;

        for(int i = 0; i < m; ++i){
            string source;
            int c;
            cin >>source >> c;

            for(int j = 0; j < c; ++j){
                string prereq;
                cin >> prereq;

                max_count_ways[course_code[source]][course_code[prereq]] = 1;
            }
        }

        //perfoming floyd_warshall algorithm to find the maximum possible length of the path
        for(int k = 0; k < n; ++k)
            for(int i = 0; i < n; ++i)
                for(int j = 0; j < n; ++j)
                    if(max_count_ways[i][k] != 0 && max_count_ways[k][j] != 0)
                        max_count_ways[i][j] = max(max_count_ways[i][j], max_count_ways[i][k] + max_count_ways[k][j]);

        for(int i = 0; i < n; ++i){
            vector <int> result;

            for(int j = 0; j < n; ++j)
                if(max_count_ways[i][j] == 1)
                    result.push_back(j);

            if(result.size() == 0)
                continue;

            cout << code_course[i] << ' ';
            cout << result.size();

            for(auto a : result)
                cout << ' ' << code_course[a];
            cout << endl;
        }
    }
    return 0;
}

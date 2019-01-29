//uva 1237
//Expert Enough?

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void)
{
    int T = 0;
    cin >> T;
    while(T--){
        int n = 0;
        cin >> n;

        vector <string> names(n);
        vector <int> low(n);
        vector <int> high(n);

        for(int i = 0; i < n; ++i){
            string tmp;
            int l, h;
            cin >> tmp >> l >> h;

            names[i] = tmp;
            low[i] = l;
            high[i] = h;
        }

        int q;
        cin >> q;

        for(int i = 0; i < q; ++i){
            int p;
            cin >> p;
            string result;
            bool found = 0;

            for(int j = 0; j < n; ++j)
                if(p >= low[j] && p <= high[j]){
                    if(!found){
                        found = 1;
                        result = names[j];
                    }
                    else{
                        found = 0;
                        break;
                    }
                }

            if(found) cout << result << endl;
            else cout << "UNDETERMINED" << endl;
        }

        if(T) cout << endl;
    }
    return 0;
}

//uva 11703
//sqrt log sin

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(void)
{
    vector <int> arr(1000001);
    arr[0] = 1;

    for (int i = 1; i < 1000001; ++i){
        int index = floor(i - sqrt(i));
        arr[i] = arr[index];

        index = floor(log(i));
        arr[i] += arr[index];

        index = floor(i * sin(i) * sin(i));
        arr[i] += arr[index];

        arr[i] %= 1000000;
    }

    while (true) {
        int index;
        cin >> index;

        if (index == -1)
            break;

        cout << arr[index] << endl;
    }
    return 0;
}

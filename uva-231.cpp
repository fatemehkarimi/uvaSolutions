//uva 231
//Testing the CATCHER

#include <iostream>
#include <vector>

using namespace std;

int LIS(vector <int> & num);
int findLocation(vector <int> & num, int left, int right, int key);

int main(void)
{
  int data;
  int tcounter = 0;
  bool start = 1;

  while (true) {
    cin >> data;

    if (data == -1)
      break;

    ++tcounter;
    if (start)
      start = 0;
    else
      cout << endl;

    vector <int> num;
    do {
      num.insert(num.begin(), data);
      cin >> data;
    }while (data != -1);


    cout << "Test #" << tcounter << ":" << endl;
    cout << "  maximum possible interceptions: " << LIS(num) << endl;
  }
  return 0;
}


int findLocation(vector <int> & num, int left, int right, int key)
{
  while (right - left > 1){
    int middle = left + (right - left) / 2;

    if (num[middle] >= key)
      right = middle;
    else
      left = middle;
  }

  return right;
}


int LIS(vector <int> & num)
{
  if (num.size() == 0)
    return 0;

  vector <int> lists(num.size());

  int length = 1;
  lists[0] = num[0];

  for (int i = 1; i < num.size(); ++i)
    if (num[i] < lists[0])
      lists[0] = num[i];
    else if (num[i] >= lists[length - 1])
      lists[length++] = num[i];
    else 
      lists[findLocation(lists, -1, length - 1, num[i])] = num[i];

  return length;
}

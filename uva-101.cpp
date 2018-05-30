//uva 101
//The Blocks Problem

#include <iostream>
#include <string>

using namespace std;

//prototypes
void returnBlocks(int **arr, int *currents, int n, int num);
void put(int ** arr, int *currents, int n, int num, int place);

int main(void)
{
	int n = 0;
	cin >> n;

	int ** arr = new int *[n]();
	*arr = new int[n * n]();

	for (int i = 0; i < n; ++i)
		arr[i] = (*arr + i * n);

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			arr[i][j] = -1;

	for (int i = 0; i < n; ++i)
		arr[i][0] = i;//initial place for blocks

	int * currents = new int[n]();
	for (int i = 0; i < n; ++i)
		currents[i] = i;

	while (true) {
		string part1;
		string part2;

		cin >> part1;
		if (part1 == "quit")
			break;

		int a = 0, b = 0;
		cin >> a >> part2 >> b;

		if (part1 == "move" && currents[a] != currents[b]) {

			if (part2 == "onto") {
				returnBlocks(arr, currents, n, a);
				returnBlocks(arr, currents, n, b);

				int counter = 0;
				while (arr[currents[a]][counter] != a)
					++counter;
				arr[currents[a]][counter] = -1;//removing a from previous location

				put(arr, currents, n, a, currents[b]);

			}
			else if (part2 == "over") {
				returnBlocks(arr, currents, n, a);

				int counter = 0;
				while (arr[currents[a]][counter] != a)
					++counter;
				arr[currents[a]][counter] = -1;//removing a from previous location

				put(arr, currents, n, a, currents[b]);

			}

		}

		else if (part1 == "pile" && currents[a] != currents[b]) {

			if (part2 == "onto") {
				returnBlocks(arr, currents, n, b);

				int col = 0;
				while (arr[currents[a]][col] != a)
					++col;


				int row = currents[a];
				while (col < n && arr[row][col] != -1) {
					put(arr, currents, n, arr[row][col], currents[b]);
					arr[row][col] = -1;
					++col;
				}
				
			}
			else if (part2 == "over") {

				int col = 0;
				while (arr[currents[a]][col] != a)
					++col;


				int row = currents[a];
				while (col < n && arr[row][col] != -1) {
					put(arr, currents, n, arr[row][col], currents[b]);
					arr[row][col] = -1;
					++col;
				}

			}

		}

	}//end while

	for (int i = 0; i < n; ++i) {
		cout << i << ':';

		for (int j = 0; j < n; ++j)
			if (arr[i][j] != -1)
				cout << ' ' << arr[i][j];

		cout << endl;
	}

	delete[] * arr;
	*arr = nullptr;

	delete[] arr;
	arr = nullptr;

	delete[] currents;
	currents = nullptr;

	return 0;
}


void put(int ** arr, int *currents,int n, int num, int place)//function for puting an element at the end of a block
{															//num is always at the end of the column
	int counter = 0;

	/*while (counter < n && arr[currents[num]][counter] != num)
		++counter;

	if (counter < n)
		arr[currents[num]][counter] = -1;//removing from its current place*/

	counter = 0;
	while (counter < n && arr[place][counter] != -1)
		++counter;
	
	arr[place][counter] = num;
	currents[num] = place;

	return;
}


void returnBlocks(int **arr, int *currents, int n, int num)
{
	for (int i = n - 1; i >= 0; --i) {
		if (arr[currents[num]][i] == num)
			return;

		if (arr[currents[num]][i] != -1) {
			int previous_location = currents[num];
			put(arr, currents, n, arr[currents[num]][i], arr[currents[num]][i]);
			arr[previous_location][i] = -1;

		}
	}

	return;
}
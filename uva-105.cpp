//uva 105
//The Skyline Problem

#include <iostream>
#include <vector>

using namespace std;

struct building
{
	int left;
	int height;
	int right;
};

int findHeight(vector <building> & b, int coordinate);

int main(void)
{
	vector <building> buildings;
	int t1 = 0, t2 = 0, t3 = 0;

	while (cin >> t1 >> t2 >> t3) {
		building tmp = { t1, t2, t3 };
		buildings.push_back(tmp);
	}

	int xs = buildings[0].left;
	int current_height = 0;

	while (true) {
		int h = findHeight(buildings, xs);

		if (h !=-1 && h != current_height) {
			current_height = h;
			cout << xs << ' ' << current_height << ' ';
		}

		if (h == -1) {
			cout << xs << ' ' << '0' << endl;
			break;
		}

		++xs;
	}

	return 0;
}


int findHeight(vector <building> & b, int coordinate)
{
	int height = 0;
	bool isMax = 1;

	for (auto a : b) {
		if (coordinate >= a.left && coordinate < a.right && height < a.height) {
			height = a.height;
		}

		if (coordinate < a.left)
			break;
	}

	for (auto a : b)
		if (coordinate < a.left || coordinate < a.right) {
			isMax = 0;
			break;
		}

	if (isMax)
		height = -1;//case the highest number in the coordinates

	return height;
}
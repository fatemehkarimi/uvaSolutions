//uva 119
//Greedy Gift Givers

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct person {
	string name;
	int initial;
	int recived;
};

int main(void)
{
	int n = 0;
	bool newline = 0;
	while (cin >> n) {
		if (newline)
			cout << endl;

		vector <struct person> people;

		for (int i = 0; i < n; ++i) {
			struct person tmp = {};
			cin >> tmp.name;
			people.push_back(tmp);
		}

		for (int i = 0; i < n; ++i) {
			string tmp;
			cin >> tmp;

			for (auto &a : people)
				if (a.name == tmp) {

					int t1 = 0;
					cin >> t1;
					a.initial += t1;
					int count = 0;
					cin >> count;

					if (count != 0)
						a.recived += (t1 - (t1 / count) * count);
					else
						a.recived += t1;

					for (int i = 0; i < count; ++i) {
						cin >> tmp;

						//increasing amout for that person

						for (auto &x : people) {
							if (tmp == x.name) {
								x.recived += (t1 / count);
								break;
							}
						}
					}

					break;//geting out of the loop wich finds the person
				}
		}

		for (auto a : people)
			cout << a.name << ' ' << a.recived - a.initial << endl;

		newline = 1;
	}

	return 0;
}
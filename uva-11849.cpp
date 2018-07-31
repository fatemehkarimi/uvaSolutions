//uva 11849
//CD

#include <iostream>
#include <set>

using namespace std;

int main(void)
{
	int m = 0, n = 0;
	while (true) {
		cin >> m >> n;

		if (m == 0 && n == 0)
			break;

		set <int> cd;
		int commonCd = 0;

		for (int i = 0; i < m + n; ++i){
			int t;
			cin >> t;
			auto tmp = cd.insert(t);
			if (!tmp.second)
				++commonCd;
		}

		cout << commonCd << endl;
	}

	return 0;
}

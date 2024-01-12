#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		vector<int> a(3);

		for (int& i : a) {
			cin >> i;
		}

		sort(a.begin(), a.end());

		cout << (a[0] == a[1] ? a[2] : a[0]) << endl;
	}
}

#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<bool> d(4, 1);

		for (int i = 0; i < n; i++) {
			int c[2];
			cin >> c[0] >> c[1];

			if (c[0]) {
				d[c[0] > 0] = 0;
			}
			
			if (c[1]) {
				d[2 + (c[1] > 0)] = 0;
			}
		}

		if (d[0] || d[1] || d[2] || d[3]) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
}

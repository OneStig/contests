#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<vector<long long>> m(n);
		vector<long long> a(n, 1073741823);

		for (int i = 0; i < n; i++) {
			m[i].resize(n);

			for (int j = 0; j < n; j++) {
				cin >> m[i][j];

				if (j > i) {
					a[j] &= m[i][j];
					a[i] &= m[i][j];
				}
			}
		}

		bool fail = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (m[i][j] != (a[i] | a[j])) {
					fail = 1;
					break;
				}
			}

			if (fail) {
				break;
			}
		}

		if (fail) {
			cout << "NO" << endl;
		}
		else {
			cout << "YES" << endl;
			for (int i = 0; i < a.size(); i++) {
				if (i != 0) {
					cout << " ";
				}

				cout << a[i];
			}

			cout << endl;
		}
	}
}

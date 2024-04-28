#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);

		for (int& i : a) {
			cin >> i;
		}

		// bounds of operations required
		int l = 0, r = n / 2;

		while (l < r) {
			int cur = (l + r) / 2;

			bool fail = 0;
			int last = 0 + cur;

			for (int i = 0; i < n; i++) {
				if (a[i] <= cur || a[i] > n - cur) {
					continue;
				}

				if (a[i] == last + 1) {
					last++;
				}
				else {
					fail = 1;
					break;
				}
			}

			if (fail) {
				l = cur + 1;
			}
			else {
				r = cur;
			}
		}

		cout << l << '\n';
	}
}

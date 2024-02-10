#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include <bits/debug.h>
#endif

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<int> d;
		vector<int> a(n);

		for (int& i : a) {
			cin >> i;
		}

		int q;
		cin >> q;

		for (int i = 0; i < n - 1; i++) {
			if (a[i] != a[i + 1]) {
				d.push_back(i);
			}
		}

		while (q--) {
			int l, r;
			cin >> l >> r;
			l--, r--;

			auto f = lower_bound(d.begin(), d.end(), l);

			if (f != d.end() && *f < r) {
				cout << *f + 1 << " " << *f + 2 << endl;
			}
			else {
				cout << "-1 -1" << endl;
			}
		}

		cout << endl;
	}
}

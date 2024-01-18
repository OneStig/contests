#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	
	while (t--) {
		int n;
		cin >> n;

		int mn = INT_MIN, mx = INT_MAX;
		set<int> bad;

		while (n--) {
			int a, x;
			cin >> a >> x;

			if (a == 1) {
				mn = max(mn, x);
			}
			else if (a == 2) {
				mx = min(mx, x);
			}
			else {
				bad.insert(x);
			}
		}

		int ans = mx - mn + 1;

		for (auto it = bad.begin(); it != bad.end(); it++) {
			if (*it >= mn && *it <= mx) {
				ans--;
			}
		}

		cout << max(0, ans) << endl;
	}
}

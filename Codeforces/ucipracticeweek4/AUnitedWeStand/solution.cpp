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

		sort(a.begin(), a.end());

		if (a[0] == a[n - 1]) {
			cout << -1 << endl;
			continue;
		}

		int ans = upper_bound(a.begin(), a.end(), a[0]) - a.begin();

		cout << ans << " " << n - ans << endl;

		for (int i = 0; i < ans; i++) {
			cout << a[0] << " ";
		}

		cout << endl;

		for (int i = ans; i < n; i++) {
			cout << a[i] << " ";
		}

		cout << endl;
	}
}

#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n, k;
		cin >> n >> k;

		vector<long long> a(n);

		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		if (k >= 3) {
			cout << 0 << endl;
			continue;
		}
		
		sort(a.begin(), a.end());

		long long ans = a[0];

		for (int i = 1; i < n; i++) {
			ans = min(ans, a[i] - a[i - 1]);
		}

		if (k == 1) {
			cout << ans << endl;
			continue;
		}

		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				long long test = a[j] - a[i];
				int cl = lower_bound(a.begin(), a.end(), test) - a.begin();

				if (cl < n) {
					ans = min(ans, abs(test - a[cl]));
				}

				if (cl > 0) {
					ans = min(ans, abs(test - a[cl - 1]));
				}
			}
		}


		cout << ans << endl;
	}
}

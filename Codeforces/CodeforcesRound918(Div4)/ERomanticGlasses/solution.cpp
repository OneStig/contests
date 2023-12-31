#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<int> a(n);

		long long sum = 0;

		map<long long, bool> seen;
		bool found = 0;

		for (int i = 0; i < n; i++) {
			cin >> a[i];

			if (i % 2) {
				a[i] *= -1;
			}

			sum += a[i];

			if (!sum || seen[sum]) {
				found = 1;
			}

			seen[sum] = 1;
		}

		cout << (found ? "YES" : "NO") << endl;
	}
}

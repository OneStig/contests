#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n, k, x;
		cin >> n >> k >> x;

		vector<int> a(n);

		for (int& i : a) {
			cin >> i;
		}

		sort(a.begin(), a.end());

		int sum = 0;

		for (int i = 0; i < n - k; i++) {
			if (i < n - k - x) {
				sum += a[i];
			}
			else {
				sum -= a[i];
			}
		}

		cout << sum << endl;
	}
}

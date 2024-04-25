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

		int lb = 0;
		int ub = 1e9;

		for (int i = 1; i < n; i++) {
			if (a[i] == a[i - 1]) {
				continue;
			}

			if (a[i] < a[i - 1]) {
				int mid = (a[i] + a[i - 1] + 1) / 2;
				lb = max(lb, mid);
			}
			else {
				int mid = (a[i] + a[i - 1]) / 2;
				ub = min(ub, mid);
			}
		}

		cout << (lb <= ub ? lb : -1) << '\n';
	}
}

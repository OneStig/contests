#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n, x;
		cin >> n >> x;

		if (n % x != 0) {
			cout << -1 << '\n';
			continue;
		}

		vector<int> a(n + 1);

		for (int i = 0; i <= n; i++) {
			a[i] = i;
		}

		a[1] = x;
		a[n] = 1;

		while (x < n) {
			for (int i = x * 2; i <= n; i+= x) {
				if (n % i == 0) {
					a[x] = i;
					x = i;
					break;
				}
			}
		}

		for (int i = 1; i <= n ; i++) {
			cout << a[i] << ' ';
		}

		cout << '\n';
	}
}

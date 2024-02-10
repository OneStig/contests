#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
	int t;
	cin >> t;

	while (t--) {
		ll n, k;
		cin >> n >> k;

		int ans = -1;

		for (ll i = 0; i <= n / 2; i++) {
			ll f = i * (i - 1) / 2;
			ll j = (n - i) * (n - i - 1) / 2;

			if (k == f + j) {
				ans = i;
				break;
			}
		}

		if (ans == -1) {
			cout << "NO" << endl;
		}
		else {
			cout << "YES" << endl;

			for (int i = 0; i < ans; i++) {
				cout << 1 << " ";
			}

			for (int i = 0; i < n - ans; i++) {
				cout << -1 << " ";
			}

			cout << endl;
		}
	}
}

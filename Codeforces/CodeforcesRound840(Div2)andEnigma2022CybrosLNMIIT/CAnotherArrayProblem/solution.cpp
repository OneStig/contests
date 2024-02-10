#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include <bits/debug.h>
#endif

#define ll long long

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		ll n;
		cin >> n;

		vector<ll> a(n);

		ll mx = INT_MIN;
		for (ll& i : a) {
			cin >> i;
			mx = max(mx, i);
		}

		if (n == 2) {
			cout << max(a[0] + a[1], 2 * abs(a[1] - a[0])) << endl;
			continue;
		}

		if (n == 3 && a[0] != mx && a[2] != mx) {
			ll ans = max({
				a[0] + a[1] + a[2],
				3 * abs(a[0] - a[1]),
				3 * abs(a[1] - a[2]),
				3 * a[0],
				3 * a[2]
			});

			cout << ans << endl;
			continue;
		}

		cout << (ll)mx * n << endl;
	}
}

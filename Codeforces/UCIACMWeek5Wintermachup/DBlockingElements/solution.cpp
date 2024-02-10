#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include <bits/debug.h>
#endif

using namespace std;

#define ll long long
const ll MX = 1000;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<ll> a(n);

		for (ll& i : a) {
			cin >> i;
		}
		
		ll l = 1, r = MX;

		while (l < r) {
			ll m = (l + r) >> 1;
			ll cur = 0;
			ll blocks = 0;

			for (int i = 0; i < n; i++) {
				if (cur + a[i] > m) {
					cur = 0;
					blocks += a[i];
				}
				else {
					cur += a[i];
				}

				if (blocks > m) {
					break;
				}
			}

			debug(l, m, r, blocks);
			if (blocks > m) {
				l = m + 1;
			}
			else {
				r = m;
			}
		}

		cout << l << endl;
	}
}

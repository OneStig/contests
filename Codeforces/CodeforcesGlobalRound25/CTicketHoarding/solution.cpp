#include <bits/stdc++.h>

#define ll long long

using namespace std;


int main() {
	int t;
	cin >> t;

	while (t--) {
		int n, m, k;
		cin >> n >> m >> k;

		vector<ll> a(n);
		vector<ll> b(n);

		for (ll& i : a) {
			cin >> i;
		}

		sort(a.begin(), a.end());

		ll total = 0;
		ll sofar = 0;

		for (int i = 0; i < n; i++) {
			if (k == 0) {
				break;
			}

			b[i] = min(m, k);
			k -= b[i];

			total += (a[i] + sofar) * b[i];
			sofar += b[i];
		}

		cout << total << '\n';
	}
}

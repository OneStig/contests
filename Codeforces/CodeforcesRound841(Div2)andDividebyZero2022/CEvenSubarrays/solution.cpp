#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
	int t;
	cin >> t;

	while (t--) {
		ll n;
		cin >> n;

		vector<ll> a(n);

		vector<ll> occ(2 * n);
		ll pfx = 0;
		occ[0] = 1;

		ll odds = 0;

		for (ll& i : a) {
			cin >> i;

			pfx ^= i;

			for (ll j = 0; j * j <= 2 * n; j++) {
				if ((pfx ^ (j * j)) < 2 * n) {
					odds += occ[pfx ^ (j * j)];
				}
			}

			occ[pfx]++;
		}

		ll evens = n * (n + 1) / 2 - odds;

		cout << evens << endl;
	}
}

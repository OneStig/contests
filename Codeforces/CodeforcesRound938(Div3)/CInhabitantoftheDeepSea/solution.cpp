#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
	int t;
	cin >> t;

	while (t--) {
		ll n, k;
		cin >> n >> k;

		deque<ll> ships(n);

		for (ll& x : ships) {
			cin >> x;
		}

		cout << n - ships.size() << '\n';
	}
}

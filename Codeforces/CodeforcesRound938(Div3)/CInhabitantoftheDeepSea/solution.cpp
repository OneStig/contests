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

		while (k > 0) {
			if (ships.size() == 0) {
				break;
			}

			if (ships.size() == 1) {
				if (ships.front() <= k) {
					ships.pop_front();
				}
				break;
			}

			ll& f = ships.front();
			ll& b = ships.back();
			ll mn = min(f, b);

			if (k >= 2 * mn) {
				f -= mn;
				b -= mn;
				k -= 2 * mn;
			}
			else {
				f -= (k + 1) / 2;
				b -= k / 2;
				k = 0;
			}

			if (f == 0) {
				ships.pop_front();
			}

			if (b == 0) {
				ships.pop_back();
			}
		}

		cout << n - ships.size() << '\n';
	}
}

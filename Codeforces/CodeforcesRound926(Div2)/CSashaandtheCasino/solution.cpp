#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
	int t;
	cin >> t;

	while (t--) {
		ll k, x, a;
		cin >> k >> x >> a;

		ll orig = a;
		ll lost = 0;

		ll cur_bet = 1;

		bool fail = 0;
		while (x--) {
			if (cur_bet >= a) {
				fail = 1;
				break;
			}

			a -= cur_bet;
			lost += cur_bet;

			cur_bet = lost / (k - 1) + 1;
		}

		if (fail) {
			cout << "NO" << "\n";
			continue;
		}

		cout << (k * a > orig ? "YES" : "NO") << "\n";
	}
}

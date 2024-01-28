#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
	ll n, k, p;
	cin >> n >> k >> p;

	set<ll> pills;

	for (ll i = 1; i <= sqrt(n) + 1; i++) {
		if (n % i == 0) {
			if (i * p >= n && i <= k) {
				pills.insert(i);
			}

			if (p >= i && (n / i) <= k) {
				pills.insert(n / i);
			}
		}
	}

	cout << pills.size() << endl;

	for (auto it = pills.begin(); it != pills.end(); it++) {
		cout << *it << endl;
	}
}

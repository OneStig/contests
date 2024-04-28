#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
	int t;
	cin >> t;

	while (t--) {
		ll n, k;
		cin >> n >> k;

		ll cur = (1 << 20) - 1;

		ll leading = (1 << 20);

		while (!(k & leading)) {
			leading /= 2;
		}

		cur ^= leading;

		vector<ll> ans = {k - leading, k + 1, k + 1 + leading};

		ll bit = 1;
		while (cur != 0) {
			if (cur % 2) {
				ans.push_back(bit);
			}

			cur /= 2;
			bit *= 2;
		}


		cout << ans.size() << "\n";
		for (auto x : ans) {
			cout << x << " ";
		}

		cout << '\n';
	}
}

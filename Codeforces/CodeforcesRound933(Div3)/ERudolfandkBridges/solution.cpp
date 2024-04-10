#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
	int t;
	cin >> t;

	while (t--) {
		ll n, m, k, d;
		cin >> n >> m >> k >> d;

		vector<ll> bridges(n);

		for (int b = 0; b < n; b++) {
			vector<ll> depths(m), dp(m);

			for (int i = 0; i < m; i++) {
				cin >> depths[i];
			}

			dp[0] = 1;
			multiset<ll> best;
			best.insert(1);

			for (int i = 1; i < m; i++) {
				dp[i] = *(best.begin()) + depths[i] + 1;
				best.insert(dp[i]);

				if (i - d - 1 >= 0) {
					best.erase(best.find(dp[i - d - 1]));
				}
			}

			bridges[b] = dp[m - 1];
		}

		ll sum = 0;

		for (int i = 0; i < k; i++) {
			sum += bridges[i];
		}

		ll ans = sum;

		for (int i = k; i < n; i++) {
			sum += bridges[i];
			sum -= bridges[i - k];
			ans = min(ans, sum);
		}

		cout << ans << '\n';
	}
}

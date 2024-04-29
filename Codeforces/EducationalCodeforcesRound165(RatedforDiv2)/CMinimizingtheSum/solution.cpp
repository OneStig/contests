#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n, k;
		cin >> n >> k;

		vector<ll> a(n + 1);
		vector<vector<ll>> dp(n + 1, vector<ll>(k + 1));

		ll total = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			total += a[i];
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= k; j++) {
				if (i - j < 1) {
					break;
				}

				ll mn = a[i];
				ll reduc = 0;

				for (int r = i; r >= i - j; r--) {
					mn = min(mn, a[r]);
				}

				for (int r = i; r >= i - j; r--) {
					reduc += a[r] - mn;
				}

				for (int pj = k; pj >= 0; pj--) {
					if (pj - j < 0) {
						break;
					}

					dp[i][pj - j] = max(dp[i][pj - j], dp[i - j - 1][pj] + reduc);
				}
			}
		}

		ll mx = LLONG_MIN;

		for (int i = 0; i <= k; i++) {
			mx = max(mx, dp[n][i]);
		}

		cout << total - mx << '\n';
	}
}

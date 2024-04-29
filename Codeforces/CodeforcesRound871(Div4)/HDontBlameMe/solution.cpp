#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll MOD = 1e9 + 7;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n, k;
		cin >> n >> k;

		vector<int> a(n);

		for (int& i : a) {
			cin >> i;
		}

		vector<vector<ll>> dp(n, vector<ll>(64));

		dp[0][a[0]] = 1;

		for (int i = 1; i < n; i++) {
			dp[i][a[i]]++;
			for (int j = 0; j < 64; j++) {
				dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
				dp[i][j & a[i]] = (dp[i][j & a[i]] + dp[i - 1][j]) % MOD;
			}
		}

		ll ans = 0;
		for (int i = 0; i < 64; i++) {
			if (__builtin_popcount(i) == k) {
				ans = (ans + dp[n - 1][i]) % MOD;
			}
		}

		cout << ans << '\n';
	}
}

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

		int dim = n;

		vector<ll> dp(n + 1);

		for (int i = 0; i < k; i++) {
			int r, c;
			cin >> r >> c;
			if (r == c) {
				dim--;
			}
			else {
				dim -= 2;
			}
		}

		dp[0] = 1;
		dp[1] = 1;

		for (ll i = 2; i <= dim; i++) {
			dp[i] = dp[i - 1];
			dp[i] += dp[i - 2] * (i - 1) * 2;
			dp[i] %= MOD;
		}
		
		cout << dp[dim] << '\n';
	}
}

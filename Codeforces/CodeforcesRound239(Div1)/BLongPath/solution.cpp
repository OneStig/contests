#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include <bits/debug.h>
#endif

#define ll long long

using namespace std;

const ll MOD = 1e9 + 7;

int main() {
	int n;
	cin >> n;

	vector<ll> p(n);

	for (ll& i : p) {
		cin >> i;
		i--;
	}

	vector<array<ll, 2>> dp(n);
	dp[0] = {0, 1};

	for (int i = 1; i < n; i++) {
		dp[i][0] = dp[i - 1][1] + (ll)1;
		dp[i][0] = (dp[i][0] + MOD);
		dp[i][1] = dp[i][0] + (ll)1 + dp[i][0] - dp[p[i]][0];
		dp[i][1] += MOD;
		dp[i][1] %= MOD;
	}

	//debug(dp);
	cout << (dp[n - 1][1] + 1) % MOD << endl;
}

// 1 2
// 1 -> 1 -> 2 -> 2 -> 3
// {0, 1}, {2, 3}
// 

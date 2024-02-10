#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include <bits/debug.h>
#endif

using namespace std;

int fact[(int)(1e5 + 1)];

int main() {
	int n;
	cin >> n;

	vector<int> a(n);

	for (int& i : a) {
		cin >> i;
	}

	int ans = 1;
	vector<int> dp(n);
	memset(fact, 0, sizeof(fact));

	for (int i = 0; i < n; i++) {
		int cur = a[i];

		int mx = fact[a[i]];
		vector<int> cf;
		cf.push_back(a[i]);

		for (int f = 2; f <= sqrt(a[i]); f++) {
			if (a[i] % f == 0) {
				mx = max({mx, fact[f], fact[a[i] / f]});

				cf.push_back(f);
				cf.push_back(a[i] / f);
			}
		}

		dp[i] = mx + 1;
		ans = max(ans, dp[i]);

		for (int f : cf) {
			fact[f] = max(fact[f], dp[i]);
		}
	}

	cout << ans << endl;
}

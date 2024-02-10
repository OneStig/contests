#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include <bits/debug.h>
#endif

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<string> matx(n);

	for (auto& s : matx) {
		cin >> s;
	}

	vector<vector<int>> dp(m, vector<int>(5001));

	for (int r = 0; r < n; r++) {
		int st = 0;
		for (int c = 0; c < m; c++) {
			if (matx[r][c] == '1') {
				st++;
			}
			else {
				st = 0;
			}

			dp[c][st]++;
		}
	}

	int ans = 0;

	for (int i = 0; i < m; i++) {
		int count = 0;
		for (int k = 5000; k >= 1; k--) {
			count += dp[i][k];

			ans = max(ans, k * count);
		}
	}

	cout << ans << endl;
}

#include <bits/stdc++.h>

using namespace std;

int dp[201][201][201];

int main() {
	int t;
	cin >> t;

    for (int i = 0; i <= 200; i++) {
        for (int j = 0; j <= 200; j++) {
            for (int k = 0; k <= 200; k++) {
                if (i - 1 >= 0) {
                    dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k]);
                }
                if (j - 1 >= 0) {
                    dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k]);
                }
                if (k - 1 >= 0) {
                    dp[i][j][k] = max(dp[i][j][k], dp[i][j][k - 1]);
                }

                if ((i + k) % 2 == 0 && (j + k) % 2 == 0) {
                    dp[i][j][k]++;
                }
            }
        }
    }

	while (t--) {
		vector<int> f(5);
		cin >> f[1] >> f[2] >> f[3] >> f[4];
		int ans = dp[f[1]][f[2]][f[3]] - 1;

		cout << ans + f[4] / 2 << '\n';
	}
}

// bob wins if
// f[1] + f[3] even
// f[2] + f[3] even
// f[4] even

// 1 001
// 2 010
// 3 011
// 4 100

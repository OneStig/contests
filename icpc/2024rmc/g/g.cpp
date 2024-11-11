#include <bits/stdc++.h>

using namespace std;

typedef int uci;
#define int long long
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

uci main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int r, c;
	cin >> r >> c;

	vector<string> grid(r);
	for (string& x : grid) cin >> x;

	vector<vector<array<int, 2>>> dp(r, vector<array<int, 2>>(c, {0, 0}));

	// compute horiz dp[0]

	for (int row = 0; row < r; row++) {
		for (int pos = 0; pos < c; pos++) {
			int mxlen = 0;
			int left = pos - 1, right = pos + 1;
			while (left >= 0 && right < c && grid[row][left] == grid[row][right]) {
				mxlen++;
				left--;
				right++;
			}

			int pallen = 1 + 2 * mxlen;

			for (int sweep = pos - mxlen; sweep <= pos + mxlen; sweep++) {
				dp[row][sweep][0] = max(dp[row][sweep][0], pallen);
			}
		}

		// off center palindromes

		for (int pos = 1; pos < c; pos++) {
			int mxlen = 0;
			int left = pos - 1, right = pos;
			while (left >= 0 && right < c && grid[row][left] == grid[row][right]) {
				mxlen++;
				left--;
				right++;
			}

			int pallen = 2 * mxlen;
			for (int sweep = pos - mxlen; sweep < pos + mxlen; sweep++) {
				dp[row][sweep][0] = max(dp[row][sweep][0], pallen);
			}
		}
	}

	// compute vert dp[1]

	for (int col = 0; col < c; col++) {
		for (int pos = 0; pos < r; pos++) {
			int mxlen = 0;
			int left = pos - 1, right = pos + 1;
			while (left >= 0 && right < r && grid[left][col] == grid[right][col]) {
				mxlen++;
				left--;
				right++;
			}

			int pallen = 1 + 2 * mxlen;

			for (int sweep = pos - mxlen; sweep <= pos + mxlen; sweep++) {
				dp[sweep][col][1] = max(dp[sweep][col][1], pallen);
			}
		}

		// off center palindromes

		for (int pos = 1; pos < r; pos++) {
			int mxlen = 0;
			int left = pos - 1, right = pos;
			while (left >= 0 && right < r && grid[left][col] == grid[right][col]) {
				mxlen++;
				left--;
				right++;
			}

			int pallen = 2 * mxlen;
			for (int sweep = pos - mxlen; sweep < pos + mxlen; sweep++) {
				dp[sweep][col][1] = max(dp[sweep][col][1], pallen);
			}
		}
	}

	// compute answer
	int ans{};

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			ans = max(ans, dp[i][j][0] * dp[i][j][1]);
		}
	}

	cout << ans << '\n';
}

#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "cpp-dump/cpp-dump.hpp"
#define dbg(...) cpp_dump(__VA_ARGS__)
#else
#define dbg(...)
#endif

typedef int uci;
#define int long long
#define ld long double
#define ve vector
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
typedef pair<int, int> pii;

uci main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        int n, x;
        cin >> n >> x;

        vector<int> a(n);
        for (int& x : a) cin >> x;

        ve<ve<int>> dp(n, ve<int>(n + 1));
        for (int i = 0; i < n; i++) {
            dp[i][0] = a[i];
            if (i != 0) {
                dp[i][0] = max(dp[i][0], dp[i - 1][0] + a[i]);
            }

            for (int j = 1; j <= n; j++)  {
                dp[i][j] = a[i] + x;
                if (i != 0) {
                    dp[i][j] = max({dp[i][j], dp[i - 1][j] + a[i], dp[i - 1][j - 1] + a[i] + x});
                }
            }
        }

        int ans = 0;
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j < n; j++) {
                ans = max(ans, dp[j][i]);
            }
            cout << ans << ' ';
        }

        cout << '\n';
    }
}

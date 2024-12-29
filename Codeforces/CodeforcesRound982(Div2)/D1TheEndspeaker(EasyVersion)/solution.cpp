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

const int INF = 1e16;

uci main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        ve<int> a(n + 1);
        ve<int> b(m + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            a[i] += a[i - 1];
        }

        for (int i = 1; i <= m; i++) cin >> b[i];

        ve<ve<int>> dp(n + 1, ve<int>(m + 1, INF));

        for (int k = 1; k <= m; k++) {
            dp[0][k] = 0;

            for (int i = 1; i <= n; i++) {
                if (k != 1) {
                    dp[i][k] = dp[i][k - 1];
                }

                // go back as much as we can up to b[k];
                int targ = a[i] - b[k];
                int pnt = lower_bound(all(a), targ) - a.begin();
                dp[i][k] = min(dp[i][k], dp[pnt][k] + (m - k));
            }
        }

        int ans = INF;
        for (int k = 1; k <= m; k++) {
            ans = min(ans, dp[n][k]);
        }
        cout << (ans == INF ? -1 : ans) << '\n';
    }
}

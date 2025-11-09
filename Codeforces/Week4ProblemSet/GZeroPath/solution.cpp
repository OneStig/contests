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

#define l first
#define r second

const int INF = 1e9;

uci main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        ve<ve<int>> a(n, ve<int>(m));
        for (auto& x : a) for (int& y : x) cin >> y;
    
        if ((n + m) % 2 == 0) {
            cout << "NO\n";
            continue;
        }

        ve<ve<pii>> dp(n, ve<pii>(m, {INF, -INF}));
        dp[0][0] = {a[0][0], a[0][0]};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i != 0) {
                    dp[i][j].l = min(dp[i][j].l, dp[i - 1][j].l + a[i][j]);
                    dp[i][j].r = max(dp[i][j].r, dp[i - 1][j].r + a[i][j]);
                }

                if (j != 0) {
                    dp[i][j].l = min(dp[i][j].l, dp[i][j - 1].l + a[i][j]);
                    dp[i][j].r = max(dp[i][j].r, dp[i][j - 1].r + a[i][j]);
                }
            }
        }

        bool yes = dp[n - 1][m - 1].l <= 0 && dp[n - 1][m - 1].r >= 0;
        cout << (yes ? "YES" : "NO") << '\n';
    }
}

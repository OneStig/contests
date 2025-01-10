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

const int INF = 1e9;

uci main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        string a, b, c;
        cin >> a >> b >> c;
        int n = sz(c);

        if (sz(b) < sz(a)) swap(a, b);

        ve<ve<int>> dp(n + 1, ve<int>(sz(a) + 1, INF));
        dp[0][0] = 0;

        for (int i = 1; i <= n; i++) {
            char cur = c[i - 1];
            for (int j = 0; j <= sz(a); j++) {
                // take from a
                if (j != 0) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + (cur != a[j - 1]));
                }

                // take from b
                if (i - j != 0 && i - j <= sz(b)) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j] + (cur != b[i - j - 1]));
                }
            }
        }

        cout << dp[n][sz(a)] << '\n';
    }
}

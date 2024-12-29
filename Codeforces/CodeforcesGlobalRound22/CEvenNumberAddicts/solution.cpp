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
        int n;
        cin >> n;
        int odd = 0;
        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;
            odd += abs(num) % 2;
        }

        ve<ve<ve<bool>>> dp(n + 1, ve<ve<bool>>(odd + 1, ve<bool>(2)));
        // remaining, remaining odds, alice odd parity
        dp[0][0][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= min(odd, i); j++) {
                for (int p : {0, 1}) {
                    if (i % 2 == n % 2) {
                        if (i != j) {
                            dp[i][j][p] = dp[i][j][p] || dp[i - 1][j][p];
                        }
                        if (j != 0) {
                            dp[i][j][p] = dp[i][j][p] || dp[i - 1][j - 1][!p];
                        }
                    }
                    else {
                        dp[i][j][p] = 1;
                        if (i != j) {
                            dp[i][j][p] = dp[i][j][p] && dp[i - 1][j][p];
                        }
                        if (j != 0) {
                            dp[i][j][p] = dp[i][j][p] && dp[i - 1][j - 1][p];
                        }
                    }
                }
            }
        }

        cout << (dp[n][odd][0] ? "Alice" : "Bob") << '\n';
    }
}

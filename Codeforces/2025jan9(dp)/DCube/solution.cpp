#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "cpp-dump/cpp-dump.hpp"
#define dbg(...) cpp_dump(__VA_ARGS__)
#else
#define dbg(...)
#endif

typedef int uci;
// #define int long long
#define ld long double
#define ve vector
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
typedef pair<int, int> pii;

const int MAX_N = 12;
const int INF = 1e9;

int dp[1 << (2 * MAX_N)];
int g[12][12][12];

uci main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                cin >> g[i][j][k];
            }
        }
    }

    fill(dp, dp + (1 << (2 * n)), INF);
    dp[0] = 0;

    for (int mask = 1; mask < (1 << (2 * n)); mask++) {
        for (int y = 0; y < n; y++) {
            if (!(mask & (1 << y))) continue;
            for (int z = 0; z < n; z++) {
                if (!(mask & (1 << (n + z)))) continue;

                int prev = mask - (1 << y) - (1 << (n + z));
                int x = __builtin_popcount(mask) / 2 - 1;
                dp[mask] = min(dp[mask], dp[prev] + g[x][y][z]);
            }
        }
    }

    int ans = dp[(1 << 2 * n) - 1];

    cout << ans << '\n';
}

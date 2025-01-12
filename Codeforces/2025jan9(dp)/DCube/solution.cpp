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

    for (int mask = 0; mask < (1 << (2 * n)) - 1; mask++) {
        if (dp[mask] == INF) continue;

        dbg(mask | cpp_dump::bin(2 * n, n), dp[mask]);

        ve<int> ys, zs;
        for (int y = 0; y < n; y++) {
            if (!(mask & (1 << y))) ys.push_back(y);
        }

        for (int z = 0; z < n; z++) {
            if (!(mask & (1 << (n + z)))) zs.push_back(z);
        }

        // assert(sz(ys) == sz(zs));

        int x = n - sz(ys);

        for (int y : ys) for (int z : zs) {
            int nxt = mask + (1 << y) + (1 << (n + z));
            dp[nxt] = min(dp[nxt], dp[mask] + g[x][y][z]);
            dbg(dp[nxt], x, y, z, g[x][y][z]);
        }
    }

    int ans = dp[(1 << 2 * n) - 1];

    cout << ans << '\n';
}

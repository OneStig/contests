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

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    ve<string> strs(n);
    for (auto& s : strs) {
        cin >> s;
    }

    ve<ve<int>> grid(n, ve<int>(m, 0));

    for (int j = 0; j < m; j++) {
        int cons = 0;
        for (int i = 0; i < n; i++) {
            if (strs[i][j] == '.') {
                cons++;
            }
            else {
                cons = 0;
            }

            if (cons >= k) {
                grid[i][j] = 1;
            }
        }
    }

    int ans = 1;
    queue<pii> bfs;
    bfs.push({k - 1, 0});

    while (sz(bfs)) {
        auto [x, y] = bfs.front();
        bfs.pop();

        ans = max(ans, x + 1);

        if (x + 1 < n && grid[x + 1][y] == 1) {
            grid[x + 1][y] = 2;
            bfs.push({x + 1, y});
        }

        if (y - 1 >= 0 && grid[x][y - 1] == 1) {
            grid[x][y - 1] = 2;
            bfs.push({x, y - 1});
        }

        if (y + 1 < m && grid[x][y + 1] == 1) {
            grid[x][y + 1] = 2;
            bfs.push({x, y + 1});
        }
    }

    cout << ans << '\n';
}

uci main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}

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

    int n, m;
    cin >> n >> m;

    ve<ve<int>> g(n, ve<int>(m));
    for (auto& x : g) for (auto& y : x) cin >> y;

    int ans = 0;

    ve<int> lastupd(1e5 + 1, -1);
    map<int, pii> cnt;
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            if (lastupd[g[r][c]] != r) {
                cnt[g[r][c]].first += cnt[g[r][c]].second * (r - lastupd[g[r][c]]);
                lastupd[g[r][c]] = r;
            }
            ans += cnt[g[r][c]].first;
            cnt[g[r][c]].second++;
        }
    }

    map<int, pii> vcnt;
    fill(all(lastupd), -1);

    for (int c = 0; c < m; c++) {
        for (int r = 0; r < n; r++) {
            if (lastupd[g[r][c]] != c) {
                vcnt[g[r][c]].first += vcnt[g[r][c]].second * (c - lastupd[g[r][c]]);
                lastupd[g[r][c]] = c;
            }
            ans += vcnt[g[r][c]].first;
            vcnt[g[r][c]].second++;
        }
    }

    cout << ans << '\n';
}

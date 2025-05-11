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

const int INF = 1e15;

void solve() {
    int n;
    cin >> n;

    ve<ve<int>> h(n, ve<int>(n));
    for (auto& x : h) for (int& y : x) cin >> y;

    ve<int> a(n), b(n);
    for (int& x : a) cin >> x;
    for (int& x : b) cin >> x;

    ve<array<int, 2>> dp1(n, {INF, INF}), dp2(n, {INF, INF});
    
    dp1[0] = {0, a[0]};

    for (int r = 1; r < n; r++) {
        set<int> diff;
        for (int c = 0; c < n; c++) {
            diff.insert(h[r][c] - h[r - 1][c]);
        }

        if (!diff.count(0)) {
            dp1[r][0] = dp1[r - 1][0];
            dp1[r][1] = dp1[r - 1][1] + a[r];
        }

        if (!diff.count(1)) {
            dp1[r][0] = min(dp1[r][0], dp1[r - 1][1]);
        }

        if (!diff.count(-1)) {
            dp1[r][1] = min(dp1[r][1], dp1[r - 1][0] + a[r]);
        }
    }

    dp2[0] = {0, b[0]};

    for (int c = 1; c < n; c++) {
        set<int> diff;
        for (int r = 0; r < n; r++) {
            diff.insert(h[r][c] - h[r][c - 1]);
        }

        if (!diff.count(0)) {
            dp2[c][0] = dp2[c - 1][0];
            dp2[c][1] = dp2[c - 1][1] + b[c];
        }

        if (!diff.count(1)) {
            dp2[c][0] = min(dp2[c][0], dp2[c - 1][1]);
        }

        if (!diff.count(-1)) {
            dp2[c][1] = min(dp2[c][1], dp2[c - 1][0] + b[c]);
        }
    }

    // dbg(dp1, dp2);

    int ans = min(dp1[n - 1][0], dp1[n - 1][1]) + min(dp2[n - 1][0], dp2[n - 1][1]);

    cout << (ans >= INF ? -1 : ans) << '\n';
}

uci main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}

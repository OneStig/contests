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

int cnt(ve<bool>& arr) {
    int res = 0;
    for (bool x : arr) {
        res += x;
    }
    return res;
}

void solve() {
    int n, m;
    cin >> n >> m;

    ve<string> a(n);
    for (auto& x : a) cin >> x;

    ve<ve<bool>> b(m, ve<bool>(n));
    ve<bool> mask(n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            string s;
            cin >> s;

            b[i][j] = s == a[j];
            mask[j] = mask[j] || b[i][j];
        }
    }

    if (cnt(mask) != n) {
        cout << -1 << '\n';
        return;
    }

    int mx = 0;
    for (ve<bool>& st : b) {
        mx = max(mx, cnt(st));
    }

    dbg(b, mx);

    int ans = n + 2 * (n - mx);
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

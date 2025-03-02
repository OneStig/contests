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
    int n, l, r;
    cin >> n >> l >> r;

    ve<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    assert(l == r); // subproblem d1

    if (l <= n) {
        cout << a[l] << '\n';
        return;
    }

    int ans = 0;


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

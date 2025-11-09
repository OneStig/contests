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

struct P {
    int x;
    int y;
};

int cross_product(P a, P b, P c){
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

void solve() {
    int n;
    cin >> n;
    ve<P> p(n);
    for (P& pt : p) {
        cin >> pt.x >> pt.y;
    }

    int ans = 0;
    int l = 0, r = 0;
    while (r < n) {
        if (r - l >= 2) {
            ans = max(ans, r - l + 1);
        }

        if (r == n - 1) break;

        if (l == r) {
            r++;
            continue;
        }

        // can we push r forwards?
        int res = cross_product(p[r - 1], p[r], p[r + 1]);
        int res2 = cross_product(p[r], p[r + 1], p[l]);
        int res3 = cross_product(p[r + 1], p[l], p[l + 1]);
        if (res < 0 && res2 < 0 && res3 < 0) { // two strict right turns
            r++;
            continue;
        }

        if (res >= 0) {
            l = r; // left turn fails
            continue;
        }

        while (l < r && (cross_product(p[r], p[r + 1], p[l]) >= 0 || cross_product(p[r + 1], p[l], p[l + 1]) >= 0)) {
            l++;
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

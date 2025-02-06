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

const ld ERR = 1e-7;

uci main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, k;
    cin >> n >> k;

    ve<pii> a(n);
    for (auto& x : a) cin >> x.first >> x.second;

    ld l = 0, r = 1e5;
    while (r - l > ERR) {
        ld mid = (l + r) / 2;
        int count = 0;

        for (auto& x : a) {
            if ((ld)x.first / (ld)x.second >= mid) {
                count++;
            }
        }
    }

    ld ans = (l + r) / 2;
    cout << fixed << setprecision(9) << ans << '\n';
}

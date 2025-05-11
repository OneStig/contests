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
        string s;
        cin >> n >> s;

        int invs = 0, bs = 0, ps = 0, beven = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == 'P') {
                ps++;
            }
            else {
                bs++;
                invs += ps;

                if (i % 2 == 0) {
                    beven++;
                }
            }
        }

        int swaps = abs(beven - (bs + 1) / 2);
        int ans = swaps + (invs - swaps) / 2;
        dbg(invs, bs, ps, beven, swaps, ans);

        cout << ans << '\n';
    }
}

// PPPBBB
// PPBBPB
// BPPBPB
// BBPPPB
// BBPBPP
// BBBPPP

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

bool ask(int u, int v) {
    cout << u << ' ' << v << endl;
    int res;
    cin >> res;
    if (res == -1) exit(0);
    return res;
}

void solve() {
    int n;
    cin >> n;

    set<pair<int, int>> asked;

    // check 1 2, 3 4, 5 6 etc.
    // then a < n / 2
    // check 1 2 3, 4 5 6, 7 8 9 etc.
    // then a < n / 3
    for (int gs = 2; gs <= n; gs++) {
        for (int g = 0; g < (n + gs - 1) / gs; g++) {
            int first = g * gs + 1;
            int last = min((g + 1) * gs, n);
        
            for (int i = first; i <= last; i++) {
                for (int j = i + 1; j <= last; j++) {
                    if (!asked.count({i, j})) {
                        asked.insert({i, j});
                        bool res = ask(i, j);
                        if (res) return;
                    }
                }
            }
        }
    }
}

uci main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}

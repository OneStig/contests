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

int cost(ve<int>& aa) {
    if (sz(aa) == 0) return 0;
    int mid = sz(aa) / 2;
    int med = aa[mid];
    int tot = 0;

    for (int i = 0; i < sz(aa); i++) {
        tot += abs(med - aa[i]) - abs(mid - i);
    }

    return tot;
}

uci main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        ve<int> as, bs;

        for (int i = 0; i < n; i++) {
            if (s[i] == 'a') {
                as.push_back(i);
            }
            else {
                bs.push_back(i);
            }
        }

        int ans = min(cost(as), cost(bs));
        cout << ans << '\n';
    }
}

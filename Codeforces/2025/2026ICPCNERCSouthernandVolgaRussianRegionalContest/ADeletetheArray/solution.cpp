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
    int n;
    cin >> n;
    int count = n;
    dbg(n);
    ve<int> a(n), nxt(n), prv(n);
    map<int, set<int>> pos;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pos[a[i]].insert(i);
        nxt[i] = i + 1;
        prv[i] = i - 1;
    }

    int start = 0;
    int ans = 0;

    dbg(a, nxt, prv);
    while (count) {
        ans++;
        if (count == 1) break;

        if (a[start] == a[nxt[start]]) {
            // greedy delete first 2
            int num = a[start];
            pos[num].erase(pos[num].begin());
            pos[num].erase(pos[num].begin());
            if (!sz(pos[num])) {
                pos.erase(num);
            }
            count -= 2;
            
            if (count != 0) {
                start = nxt[nxt[start]];
                prv[start] = -1;
            }
            continue;
        }

        // remove leftmost min
        count--;
        int lm = *(pos.begin()->second.begin());
        pos.begin()->second.erase(lm);

        if (start == lm) {
            start = nxt[lm];
        }

        if (!sz(pos.begin()->second)) {
            pos.erase(pos.begin());
        }

        if (prv[lm] != -1) {
            nxt[prv[lm]] = nxt[lm];
        }

        if (nxt[lm] != n) {
            prv[nxt[lm]] = prv[lm];
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

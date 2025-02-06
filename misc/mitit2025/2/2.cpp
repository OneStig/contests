#include <bits/stdc++.h>

using namespace std;

#define ONLINE_JUDGE

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

    ve<pii> en(n);
    array<multiset<int>, 2> my;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        my[y].insert(x);
    }

    for (auto& x : en) {
        cin >> x.first >> x.second;
    }

    sort(en.rbegin(), en.rend());

    bool yes = 1;

    for (auto& cur : en) {
        if (cur.second == 0) {
            int ztarg = (cur.first + 1) / 2;
            int otarg = cur.first;

            auto zit = my[0].lower_bound(ztarg);
            auto oit = my[1].lower_bound(otarg);

            if (zit != my[0].end()) {
                my[0].erase(zit);
            }
            else if (oit != my[1].end()) {
                my[1].erase(oit);
            }
            else {
                yes = 0;
                break;
            }
        }
        else {
            int ztarg = cur.first;
            int otarg = (cur.first + 1) / 2;

            auto zit = my[0].lower_bound(ztarg);
            auto oit = my[1].lower_bound(otarg);

            if (oit != my[1].end()) {
                my[1].erase(oit);
            }
            else if (zit != my[0].end()) {
                my[0].erase(zit);
            }
            else {
                yes = 0;
                break;
            }
        }
    }

    cout << (yes ? "YES" : "NO") << '\n';
}

uci main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}

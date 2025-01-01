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
    int n, m, L;
    cin >> n >> m >> L;

    ve<pii> hurdles(n);
    for (auto& h : hurdles) {
        cin >> h.first >> h.second;
    }

    sort(all(hurdles));

    ve<pii> pows(m);
    for (auto& p : pows) {
        cin >> p.first >> p.second;
    }

    sort(pows.rbegin(), pows.rend());

    int ans = 0;
    int k = 1;
    priority_queue<int> avail;
    for (auto& h : hurdles) {
        while (sz(pows) && pows.back().first < h.first) {
            avail.push(pows.back().second);
            pows.pop_back();
        }

        while (k <= h.second - h.first + 1) {
            if (!sz(avail)) {
                ans = -1;
                break;
            }

            k += avail.top();
            ans++;
            avail.pop();
        }

        if (ans == -1) break;
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

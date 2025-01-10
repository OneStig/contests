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

const int INF = 1000000000000000010;

uci main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    set<int> unq;
    ve<int> s;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (!unq.count(x)) {
            s.push_back(x);
            unq.insert(x);
        }
    }

    sort(all(s));

    ve<int> gaps = {INF};

    for (int i = 1; i < sz(s); i++) {
        gaps.push_back(s[i] - s[i - 1]);
    }

    dbg(INF, gaps);

    sort(all(gaps));
    ve<int> pfx(sz(gaps));
    pfx[0] = gaps[0];
    for (int i = 1; i < sz(gaps); i++) {
        pfx[i] = pfx[i - 1] + gaps[i];
    }

    dbg(gaps, pfx);

    int q;
    cin >> q;

    while (q--) {
        int l, r;
        cin >> l >> r;
        int gap = r - l;

        int ind = upper_bound(all(gaps), gap) - gaps.begin();
        dbg(gap, ind);
        int ans = (gap + 1) * (sz(gaps) - ind);
        if (ind != 0) {
            ans += pfx[ind - 1];
        }
        cout << ans << ' ';
    }

    cout << '\n';
}

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

struct Node {
    int l, r, mx, mn;

    bool operator<(const Node& b) const {
        return (mx - mn) > (b.mx - b.mn);
    }
};

uci main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;

    ve<int> a(n);
    for (int& x : a) cin >> x;

    if (n <= 2) {
        cout << "unstable\n";
        return 0;
    }

    set<pii> vis;

    priority_queue<Node> pq;
    for (int i = 1; i < n; i++) {
        Node cur = {i - 1, i, max(a[i], a[i - 1]), min(a[i], a[i - 1])};
        pq.push(cur);
        vis.insert({i - 1, i});
    }

    ve<int> ans;

    while (sz(ans) < n) {
        Node cur = pq.top();
        pq.pop();
        ans.push_back(cur.mx - cur.mn);

        if (cur.l > 0 && !vis.count({cur.l - 1, cur.r})) {
            Node left = {cur.l - 1, cur.r, max(cur.mx, a[cur.l - 1]), min(cur.mn, a[cur.l - 1])};
            pq.push(left);
            vis.insert({cur.l - 1, cur.r});
        }

        if (cur.r < n - 1 && !vis.count({cur.l, cur.r + 1})) {
            Node right = {cur.l, cur.r + 1, max(cur.mx, a[cur.r + 1]), min(cur.mn, a[cur.r + 1])};
            pq.push(right);
            vis.insert({cur.l, cur.r + 1});
        }
    }

    bool yes = 1;

    for (int k = 1; k <= n; k++) {
        if (ans[k - 1] > k) {
            yes = 0;
        }
    }

    cout << (yes ? "stable" : "unstable") << '\n';
}

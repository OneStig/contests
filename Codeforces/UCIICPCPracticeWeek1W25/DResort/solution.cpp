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

ve<int> dfs(int x, ve<int>& a, ve<ve<int>>& adj) {
    ve<int> path;
    while (x != 0 && sz(adj[x]) <= 1) {
        path.push_back(x);
        x = a[x];
    }
    reverse(all(path));
    return path;
}

uci main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;

    ve<int> t(n + 1), a(n + 1);

    ve<ve<int>> adj(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> t[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        adj[a[i]].push_back(i);
    }

    ve<int> best;

    for (int i = 1; i <= n; i++) {
        if (t[i] == 1) {
            ve<int> cur = dfs(i, a, adj);
            if (sz(cur) > sz(best)) {
                swap(best, cur);
            }
        }
    }

    cout << sz(best) << '\n';
    for (int& x : best) cout << x << ' ';
    cout << '\n';
}

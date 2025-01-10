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

pii dfs(int x, int par, ve<ve<int>>& adj, set<int>& a, int targ) {
    int edged = 0;
    int xd = 0;

    for (int& nb : adj[x]) {
        if (nb == par) continue;
        if (nb == targ) xd = 1;

        auto [nbedge, nbxd] = dfs(nb, x, adj, a, targ);
        if (nbedge != 0 || a.count(nb)) {
            edged++;
        }

        edged += nbedge;

        if (nbxd != 0) {
            xd = nbxd + 1;
        }
    }

    return {edged, xd};
}

uci main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        int n, k, x, y;
        cin >> n >> k >> x >> y;
        set<int> a;
        a.insert(x);

        for (int i = 0; i < k; i++) {
            int ai;
            cin >> ai;
            a.insert(ai);
        }

        ve<ve<int>> adj(n + 1);
        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        auto [ans, xdist] = dfs(y, 0, adj, a, x);
        dbg(ans, xdist);
        ans = ans * 2 - xdist;

        cout << ans << '\n';
    }
}

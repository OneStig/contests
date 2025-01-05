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

void dfs(int x, int par, ve<ve<pii>>& adj, ve<int>& ans, int label) {
    for (auto& nb : adj[x]) {
        if (nb.first == par) continue;

        ans[nb.second] = label;
        dfs(nb.first, x, adj, ans, (label == 2 ? 3 : 2));
    }
}

uci main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        ve<ve<pii>> adj(n + 1);
        
        int mxdeg = 0;
        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;

            adj[u].push_back({v, i});
            adj[v].push_back({u, i});

            mxdeg = max(mxdeg, sz(adj[u]));
            mxdeg = max(mxdeg, sz(adj[v]));
        }

        if (mxdeg > 2) {
            cout << "-1\n";
            continue;
        }

        ve<int> ans(n);

        for (int i = 1; i <= n; i++) {
            if (sz(adj[i]) == 1) {
                dfs(i, 0, adj, ans, 3);
            }
        }

        for (int i = 1; i < n; i++) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }
}

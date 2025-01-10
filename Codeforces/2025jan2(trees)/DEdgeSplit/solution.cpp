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

void dfs(int x, ve<ve<pii>>& adj, ve<bool>& vis, ve<bool>& ans) {
    vis[x] = 1;
    for (auto& [nb, edge] : adj[x]) {
        if (!vis[nb]) {
            ans[edge] = 1;
            dfs(nb, adj, vis, ans);
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;

    ve<ve<pii>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }
    
    ve<bool> vis(n + 1), ans(m);

    dfs(1, adj, vis, ans);


    set<int> ext;

    for (int i = 1; i < n; i++) {
        for (auto& [_, edge] : adj[i]) {
            if (vis[edge] == 0) {
                ext.insert(i);
            }
        }
    }

    if (sz(ext) == 3) {

    }

    for (bool x : ans) {
        cout << x;
    }
    cout << '\n';
}

uci main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}

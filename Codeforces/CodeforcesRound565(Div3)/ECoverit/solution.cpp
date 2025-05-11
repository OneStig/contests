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

void dfs(int x, int group, ve<ve<int>>& adj, ve<bool>& vis, array<ve<int>, 2>& groups) {
    vis[x] = 1;
    groups[group].push_back(x);

    for (int& nb : adj[x]) {
        if (!vis[nb]) {
            dfs(nb, 1 - group, adj, vis, groups);
        }
    }
}

uci main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        ve<ve<int>> adj(n + 1);
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        array<ve<int>, 2> groups;
        ve<bool> vis(n + 1);

        dfs(1, 0, adj, vis, groups);

        if (sz(groups[1]) < sz(groups[0])) {
            swap(groups[1], groups[0]);
        }

        cout << sz(groups[0]) << '\n';
        for (int& x : groups[0]) {
            cout << x << ' ';
        }
        cout << '\n';
    }
}

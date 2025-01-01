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

int dfs(int x, int par, int pos, ve<ve<pii>>& adj) {
    int passes = 0;

    for (auto& [nb, nbpos] : adj[x]) {
        if (nb == par) continue;

        int curcost = pos > nbpos;
        curcost += dfs(nb, x, nbpos, adj);
        passes = max(passes, curcost);
    }

    return passes;
}

void solve() {
    int n;
    cin >> n;

    ve<ve<pii>> adj(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }

    int ans = dfs(1, 0, n, adj);
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

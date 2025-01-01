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

int n, k, c;

void dfs(int x, int par, ve<ve<int>>& adj, ve<int>& down) {
    int depth = 0;

    for (int& nb : adj[x]) {
        if (nb == par) continue;

        dfs(nb, x, adj, down);
        depth = max(depth, 1 + down[nb]);
    }

    down[x] = depth;
}

int dfs2(int x, int par, ve<ve<int>>& adj, ve<int>& down, int upval, int ply) {
    int best = upval * k - ply * c;

    ve<pii> paths;
    for (int& nb : adj[x]) {
        if (nb == par) continue;
        paths.push_back({1 + down[nb], nb});
    }

    sort(all(paths));

    for (int& nb : adj[x]) {
        if (nb == par) continue;
        int nxtup = upval + 1;

        if (nb == paths[sz(paths) - 1].second) {
            if (sz(paths) > 1) {
                nxtup = max(nxtup, 1 + paths[sz(paths) - 2].first);
            }
        }
        else {
            nxtup = max(nxtup, 1 + paths[sz(paths) - 1].first);
        }

        best = max(best, dfs2(nb, x, adj, down, nxtup, ply + 1));
    }

    return best;
}

void solve() {
    cin >> n >> k >> c;

    ve<ve<int>> adj(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    ve<int> down(n + 1);
    dfs(1, 0, adj, down);
    int ans = max(down[1] * k, dfs2(1, 0, adj, down, 0, 0));

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

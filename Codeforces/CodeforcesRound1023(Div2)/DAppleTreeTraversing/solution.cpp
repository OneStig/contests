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

vector<bool> del;

void dfs2(int x, int p, ve<ve<int>>& adj, ve<int>& dist, ve<int>& par) {
    par[x] = p;
    dist[x] = dist[p] + 1;

    for (int& nb : adj[x]) {
        if (nb != p && !del[nb]) {
            dfs2(nb, x, adj, dist, par);
        }
    }
}

void dfs(int x, int p, ve<ve<int>>& adj, ve<bool>& vis, ve<int>& dist, ve<int>& comp) {
    vis[x] = 1;
    dist[x] = dist[p] + 1;
    comp.push_back(x);

    for (int& nb : adj[x]) {
        if (nb != p && !del[nb]) {
            dfs(nb, x, adj, vis, dist, comp);
        }
    }
}

void solve() {
    int n;
    cin >> n;

    ve<ve<int>> adj(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    ve<array<int, 3>> ans;
    del = vector<bool>(n + 1);

    int remain = n;
    while (remain > 0) {
        ve<bool> vis(n + 1);
        ve<int> dist(n + 1), par(n + 1);

        for (int i = 1; i <= n; i++) {
            if (!del[i] && !vis[i]) {
                ve<int> comp;
                dfs(i, 0, adj, vis, dist, comp);

                int start = i;
                for (int& x : comp) {
                    if (dist[x] > dist[start] || (dist[x] == dist[start] && x > start)) {
                        start = x;
                    }
                }

                dfs2(start, 0, adj, dist, par);

                int end = start;

                for (int& x : comp) {
                    if (dist[x] > dist[end] || (dist[x] == dist[end] && x > end)) {
                        end = x;
                    }
                }

                array<int, 3> ap = {dist[end], max(start, end), min(start, end)};
                ans.push_back(ap);

                int todel = end;
                while (todel != 0) {
                    del[todel] = 1;
                    todel = par[todel];
                }

                remain -= ap[0];
            }
        }
    }

    sort(ans.rbegin(), ans.rend());

    for (auto& path : ans) {
        cout << path[0] << ' ' << path[1] << ' ' << path[2] << ' ';
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

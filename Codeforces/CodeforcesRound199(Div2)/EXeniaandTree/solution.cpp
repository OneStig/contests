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

const int MAX_N = 1e5 + 5;
const int INF = 1e9;

int st[MAX_N];
map<int, int> cst[MAX_N];

int dfs(int x, int par, ve<set<int>>& adj) {
    st[x] = 1;
    for (const int& nb : adj[x]) {
        if (nb != par) {
            st[x] += dfs(nb, x, adj);
        }
    }

    return st[x];
}

void centroid(int root, ve<set<int>>& adj, ve<ve<int>>& pars, ve<int> stk) {
    int locn = dfs(root, -1, adj);
    int par = -1;
    bool foundroot = 0;

    while (!foundroot) {
        foundroot = 1;
        for (const int& nb : adj[root]) {
            if (nb != par) {
                if (st[nb] > locn / 2) {
                    par = root;
                    root = nb;
                    foundroot = 0;
                    break;
                }
            }
        }
    }

    stk.push_back(root);

    ve<int> nxt(adj[root].begin(), adj[root].end());

    for (int x : nxt) {
        adj[x].erase(root);
    }

    adj[root] = {};

    pars[root] = stk;
    for (int pr : stk) {
        cst[pr][root] = INF;
    }

    for (int nx : nxt) {
        centroid(nx, adj, pars, stk);
    }
}

void cdist(int root, int x, ve<set<int>>& adj, int ply) {
    cst[root][x] = ply;

    for (const int& nb : adj[x]) {
        if (cst[root].count(nb) && cst[root][nb] == INF) {
            cdist(root, nb, adj, ply + 1);
        }
    }
}

void paint(int targ, ve<int>& reds, ve<ve<int>>& pars) {
    for (int& pr : pars[targ]) {
        reds[pr] = min(reds[pr], cst[pr][targ]);
    }
}

uci main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    ve<set<int>> adj(n + 1), adjcpy;

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
    }

    adjcpy = adj;

    ve<ve<int>> pars(n + 1);

    centroid(1, adj, pars, {});

    for (int all = 1; all <= n; all++) {
        cdist(all, all, adjcpy, 0);
    }

    ve<int> reds(n + 1, INF);
    paint(1, reds, pars);

    while (m--) {
        int typ, v;
        cin >> typ >> v;

        if (typ == 1) {
            paint(v, reds, pars);
        }
        else {
            // respond to query
            int ans = INF;

            for (int& pr : pars[v]) {
                ans = min(ans, cst[pr][v] + reds[pr]);
            }

            cout << ans << '\n';
        }
    }
}

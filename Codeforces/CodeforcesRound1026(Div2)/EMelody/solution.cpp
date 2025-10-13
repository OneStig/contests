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

const int MAX_VP = 1e9 + 1;

int dfs(int x, map<int, set<pii>>& adj, set<int>& vis) {
    vis.insert(x);

    int count = 1;
    for (auto [nb, edge] : adj[x]) {
        if (!vis.count(nb)) {
            count += dfs(nb, adj, vis);
        }
    }


    return count;
}

void solve() {
    int n;
    cin >> n;

    map<int, set<pii>> adj;

    int v, p;
    for (int i = 0; i < n; i++) {
        cin >> v >> p;

        p += MAX_VP;

        adj[v].insert({p, i});
        adj[p].insert({v, i});
    }

    bool yes = 1;
    int odd = 0;
    int start = v;

    for (const auto& [node, edges] : adj) {
        if (sz(edges) % 2) {
            start = node;
            odd++;
        }
    }

    if (odd != 0 && odd != 2) {
        yes = 0;
    }

    set<int> vis;

    if (yes == 1 && sz(adj) != dfs(start, adj, vis)) {
        yes = 0;
    }

    if (!yes) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";


    ve<pii> mainseq;
    int cur = start;
    while (sz(adj[cur])) {
        auto nxt = *adj[cur].begin();

        mainseq.push_back(nxt);
        adj[cur].erase(nxt);
        adj[nxt.first].erase({cur, nxt.second});

        cur = nxt.first;
    }

    ve<int> ans;

    cur = start;
    for (pii& edge : mainseq) {
        while (sz(adj[cur])) {
            auto nxt = *adj[cur].begin();

            ans.push_back(nxt.second);
            adj[cur].erase(nxt);
            adj[nxt.first].erase({cur, nxt.second});

            cur = nxt.first;
        }

        ans.push_back(edge.second);
        cur = edge.first;
    }

    while (sz(adj[cur])) {
        auto nxt = *adj[cur].begin();

        ans.push_back(nxt.second);
        adj[cur].erase(nxt);
        adj[nxt.first].erase({cur, nxt.second});

        cur = nxt.first;
    }


    for (int& x : ans) {
        cout << x + 1 << ' ';
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

// wlog 1 vol 2 pitch 3 vol 4 ...
// 
// for each vol/pitch, everything needs to be paired except 2 endpoints
// the construct euler tour?
// in each dimension, odd endpoints must match up
// otherwise not possible

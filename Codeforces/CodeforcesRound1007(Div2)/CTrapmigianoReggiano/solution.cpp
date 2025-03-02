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

void dfs(int x, int p, ve<ve<int>>& adj, ve<int>& ans) {
    for (int& ch : adj[x]) {
        if (ch != p) {
            dfs(ch, x, adj, ans);
        }
    }

    ans.push_back(x);
}

void solve() {
    int n, st, en;
    cin >> n >> st >> en;

    ve<ve<int>> adj(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    ve<int> ans;

    dfs(en, -1, adj, ans);

    for (int& x : ans) {
        cout << x << ' ';
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

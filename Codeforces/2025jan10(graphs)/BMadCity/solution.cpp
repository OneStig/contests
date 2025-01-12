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

bool dfs(int x, ve<ve<int>>& adj, ve<int>& col) {
    for (int& nb : adj[x]) {
        if (col[nb] == -1) {
            col[nb] = !col[x];
            dfs(nb, adj, col);
        }
        else {
            if (col[nb] == col[x]) return false;
        }
    }
    return true;
}

uci main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;

        ve<ve<int>> adj(n + 1);
        for (int i = 0; i < n; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        if (a == b) {
            cout << "NO\n";
            continue;
        }

        ve<int> col(n + 1, -1);
        col[1] = 0;
        bool ans = dfs(1, adj, col);

        cout << (ans ? "YES" : "NO") << '\n';
    }
}

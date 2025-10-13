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

uci main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;

    ve<ve<int>> adj(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    ve<int> ans(n), rev(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> ans[i];
        rev[ans[i]] = i;
    }

    for (auto& e : adj) {
        sort(e.begin(), e.end(), [&](int a, int b) -> bool {
            return rev[a] < rev[b];
        });
    }

    bool yes = 1;
    int ind = 0;

    vector<bool> vis(n + 1);
    queue<int> bfs;
    bfs.push(1);
    vis[1] = 1;

    while (bfs.size()) {
        int cur = bfs.front();
        bfs.pop();

        if (ans[ind++] != cur) {
            yes = 0;
            break;
        }

        for (auto& nxt : adj[cur]) {
            if (!vis[nxt]) {
                vis[nxt] = 1;
                bfs.push(nxt);
            }
        }
    }

    cout << (yes ? "YES" : "NO") << '\n';
}

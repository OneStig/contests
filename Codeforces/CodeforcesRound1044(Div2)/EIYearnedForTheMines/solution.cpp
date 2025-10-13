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

void solve() {
    int n;
    cin >> n;

    ve<bool> vis(n + 1);
    ve<ve<int>> adj(n + 1);
    ve<int> deg(n + 1);

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }

    ve<pii> ans;

    for (int i = 1; i <= n; i++) {
        if (deg[i] >= 3) {
            vis[i] = 1;
            ans.push_back({2, i});
            ans.push_back({1, i});

            for (int& nb : adj[i]) {
                deg[nb]--;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (deg[i] <= 1) {
            int cur = i;
            while (!vis[cur]) {
                vis[cur] = 1;
                ans.push_back({1, cur});

                for (int& nb : adj[cur]) {
                    if (!vis[nb]) {
                        cur = nb;
                        break;
                    }
                }
            }
        }
    }

    cout << sz(ans) << '\n';
    for (auto& x : ans) {
        cout << x.first << ' ' << x.second << '\n';
    }
}

uci main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}

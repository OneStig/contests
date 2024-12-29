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
    ve<ve<int>> adj(n + 1);
    ve<bool> isleaf(n + 1);

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int lcount = 0;
    for (int i = 1; i <= n; i++) {
        if (sz(adj[i]) == 1) {
            lcount++;
            isleaf[i] = 1;
        }
    }

    // trivial wins
    int ans = lcount * (n - lcount);

    if (ans != 0) {
        // otherwise count possible pairs;
        int pc = 0, qc = 0;
        for (int i = 1; i <= n; i++) {
            if (!isleaf[i]) {
                int adjleaves = 0;
                for (int& nb : adj[i]) {
                    adjleaves += isleaf[nb];
                }

                if (adjleaves == 0) {
                    pc++;
                }
                else if (adjleaves != sz(adj[i])){
                    qc += sz(adj[i]) - adjleaves;
                    qc--; // remove extra p counts on same path
                }
            }
        }

        ans += pc * qc;
    }

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

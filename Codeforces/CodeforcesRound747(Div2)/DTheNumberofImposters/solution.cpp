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

pii dfs(int x, int c, ve<ve<pii>>& adj, ve<int>& col) {
    pii cur = {c, 1 - c};

    col[x] = c;

    for (auto [nb, opp] : adj[x]) {
        int expect = c ^ opp;
        if (col[nb] == -1) {
            pii chres = dfs(nb, expect, adj, col);
            if (chres.first == -1) return chres;

            cur.first += chres.first;
            cur.second += chres.second;
        }
        else if (col[nb] != expect) {
            return {-1, -1};
        }
    }

    return cur;
}

uci main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        // 0 for same, 1 for opposite
        ve<ve<pii>> adj(n + 1);
        ve<int> col(n + 1, -1);

        int u, v;
        string s;
        for (int i = 0; i < m; i++) {
            cin >> u >> v >> s;
            int opp = s[0] == 'i';

            adj[u].push_back({v, opp});
            adj[v].push_back({u, opp});
        }

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (col[i] == -1) {
                pii res = dfs(i, 0, adj, col);
                if (res.first == -1) {
                    ans = -1;
                    break;
                }
                ans += max(res.first, res.second);
            }
        }

        cout << ans << '\n';
    }
}

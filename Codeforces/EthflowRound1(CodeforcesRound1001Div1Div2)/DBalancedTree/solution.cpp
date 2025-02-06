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

const int MAX_N = 2e5;

int l[MAX_N], r[MAX_N];
int ans;

int dfs(int x, int par, ve<ve<int>>& adj) {
    int mx = 0;

    ve<int> cx;

    for (int& nb : adj[x]) {
        if (nb == par) continue;

        int c = dfs(nb, x, adj);
        cx.push_back(c);
        mx = max(mx, c);
    }

    mx = min(l[x], max(r[x], mx));

    for (int& c : cx) {
        if (mx < c) {
            ans += c - mx;
        }
    }

    return mx;
}

void solve() {
    int n;
    cin >> n;
        
    for (int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
    }

    ve<ve<int>> adj(n);

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    ans = 0;
    ans += dfs(0, -1, adj);

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

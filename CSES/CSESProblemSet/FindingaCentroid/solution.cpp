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

int n;

void dfs(int x, int par, ve<ve<int>>& adj, ve<int>& stsz) {
    stsz[x] = 1;

    for (int& nb : adj[x]) {
        if (nb == par) continue;

        dfs(nb, x, adj, stsz);
        stsz[x] += stsz[nb];
    }
}

int dfs2(int x, int par, ve<ve<int>>& adj, ve<int>& stsz) {
    for (int& nb : adj[x]) {
        if (nb == par) continue;

        if (stsz[nb] > n / 2) {
            return dfs2(nb, x, adj, stsz);
        }
    }

    return x;
}

uci main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;

    ve<ve<int>> adj(n);

    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    ve<int> stsz(n);
    dfs(0, -1, adj, stsz);

    cout << dfs2(0, -1, adj, stsz) + 1 << '\n';
}


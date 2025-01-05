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

int dfs(int x, ve<ve<int>>& adj, ve<int>& dp) {
    if (sz(adj[x]) == 0) {
        dp[x] = 1;
        return 1;
    }

    int mxdepth = 0;
    int dpsum = 0;

    for (int& nb : adj[x]) {
        mxdepth = max(mxdepth, dfs(nb, adj, dp) + 1);
        dpsum += dp[nb];
    }

    dp[x] = max(mxdepth, dpsum);

    return mxdepth;
}

uci main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;

    ve<ve<int>> adj(n + 1);
    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        adj[p].push_back(i);
    }

    ve<int> dp(n + 1);
    dfs(1, adj, dp);
    cout << dp[1] << '\n';
}

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

void dfs(int x, int par, ve<ve<int>>& adj, ve<array<pii, 2>>& dp, ve<ve<bool>>& ans) {
    dp[x][0] = {1, sz(adj[x])};
    dp[x][1] = {0, 1};

    for (int& nb : adj[x]) {
        if (nb == par) {
            ans[x].push_back(0);
            continue;
        }
        dfs(nb, x, adj, dp, ans);

        dp[x][0].first += dp[nb][1].first;
        dp[x][0].second += dp[nb][1].second;

        int choice;
        if (dp[nb][0].first == dp[nb][1].first) {
            choice = (dp[nb][0].second < dp[nb][1].second ? 0 : 1);
        }
        else {
            choice = (dp[nb][0].first > dp[nb][1].first ? 0 : 1);
        }

        ans[x].push_back(choice);
        dp[x][1].first += dp[nb][choice].first;
        dp[x][1].second += dp[nb][choice].second;
    }
}

void dfs2(int x, int par, ve<ve<int>>& adj, ve<ve<bool>>& ans, ve<int>& labels) {
    for (int i = 0; i < sz(adj[x]); i++) {
        int nb = adj[x][i];
        if (nb == par) continue;

        if (labels[x] == -1 && ans[x][i] == 0) {
            labels[nb] = sz(adj[nb]);
        }
        else {
            labels[nb] = -1;
        }

        dfs2(nb, x, adj, ans, labels);
    }
}


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

    if (n == 2)  {
        cout << "2 2\n1 1\n";
        return 0;
    }

    ve<array<pii, 2>> dp(n + 1);
    ve<ve<bool>> ans(n + 1);

    dfs(1, 0, adj, dp, ans);

    ve<int> labels(n + 1);
    int choice;
    if (dp[1][0].first == dp[1][1].first) {
        choice = (dp[1][0].second < dp[1][1].second ? 0 : 1);
    }
    else {
        choice = (dp[1][0].first > dp[1][1].first ? 0 : 1);
    }

    int maxgood = dp[1][choice].first;
    int sumweight = dp[1][choice].second;
    labels[1] = (choice ? -1 : sz(adj[1]));

    dfs2(1, 0, adj, ans, labels);

    cout << maxgood << ' ' << sumweight << '\n';
    for (int i = 1; i <= n; i++) {
        cout << abs(labels[i]) << ' ';
    }
    cout << '\n';
}

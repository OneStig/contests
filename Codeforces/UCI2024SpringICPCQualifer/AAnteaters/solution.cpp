#include <bits/stdc++.h>

using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifndef ONLINE_JUDGE
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define ll long long
typedef int uci;
#define int long long
#define ld long double
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

void dfs(int x, int par, vector<vector<int>>& adj, vector<array<int, 2>>& lr, vector<array<int, 2>>& dp) {
    for (int& nb : adj[x]) {
        if (nb == par) continue;
        dfs(nb, x, adj, lr, dp);
    }

    if (par != -1) {
        // left, max(left, right)
        // right, max(left, right)
        dp[par][0] += max(dp[x][0] + abs(lr[x][0] - lr[par][0]), dp[x][1] + abs(lr[x][1] - lr[par][0]));
        dp[par][1] += max(dp[x][0] + abs(lr[x][0] - lr[par][1]), dp[x][1] + abs(lr[x][1] - lr[par][1]));
    }
}

void solve() {
    int n;
    cin >> n;

    vector<array<int, 2>> lr(n);

    for (auto& x : lr) {
        cin >> x[0] >> x[1];
    }

    vector<vector<int>> adj(n);

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<array<int, 2>> dp(n);

    dfs(0, -1, adj, lr, dp);

    cout << max(dp[0][0], dp[0][1]) << '\n';
}

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}

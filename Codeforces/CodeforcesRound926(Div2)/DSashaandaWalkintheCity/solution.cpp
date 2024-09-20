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

typedef int uci;
#define int long long
#define ld long double
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

const int MOD = 998244353;

void dfs(int x, int par, vector<vector<int>>& adj, vector<vector<int>>& dp) {
    dp[x][0] = 1;

    for (int nb : adj[x]) {
        if (nb == par) continue;

        dfs(nb, x, adj, dp);
        dp[x][0] = (dp[x][0] * (dp[nb][0] + 1)) % MOD;
        dp[x][1] = (dp[x][1] + dp[nb][1] + dp[nb][0]) % MOD;
    }
}

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> adj(n + 1), dp(n + 1, vector<int>(2));

        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(1, 0, adj, dp);
        int ans = (dp[1][0] + dp[1][1] + 1) % MOD;
        cout << ans << '\n';
    }
}

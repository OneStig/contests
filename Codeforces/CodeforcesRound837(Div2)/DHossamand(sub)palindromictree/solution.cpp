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

void dfs(int x, int par, int root, int ply, vector<vector<int>>& adj, vector<vector<int>>& parent, vector<array<int, 3>>& seg) {
    parent[x][root] = par;
    if (ply > 1) {
        seg.push_back({ply, root, x});
    }

    for (int& nb : adj[x]) {
        if (nb == par) continue;

        dfs(nb, x, root, ply + 1, adj, parent, seg);
    }
}

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        int ans = 1;
        vector<vector<int>> adj(n);

        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<vector<int>> parent(n, vector<int>(n));
        vector<array<int, 3>> seg;
        vector<vector<int>> dp(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            dfs(i, i, i, 1, adj, parent, seg);
            dp[i][i] = 1;
        }

        sort(all(seg));

        for (auto& cur : seg) {
            int a = cur[1], b = cur[2];

            if (cur[0] == 2) {
                if (s[a] == s[b]) {
                    dp[a][b] = 2;
                }
                else {
                    dp[a][b] = 1;
                }
            }
            else {
                if (s[a] == s[b]) {
                    dp[a][b] = 2 + dp[parent[a][b]][parent[b][a]];
                }
                else {
                    dp[a][b] = max(dp[parent[a][b]][b], dp[a][parent[b][a]]);
                }
            }

            ans = max(ans, dp[a][b]);
        }

        cout << ans << '\n';
    }
}

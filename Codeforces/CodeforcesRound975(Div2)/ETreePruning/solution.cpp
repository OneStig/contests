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

const int INF = 1e9;
int n;

int dfs(int x, int par, int ply, vector<vector<int>>& adj, vector<int>& ans) {
    int mxdepth = ply;
    for (int& nb : adj[x]) {
        if (nb == par) continue;
        int cur = dfs(nb, x, ply + 1, adj, ans);
        mxdepth = max(mxdepth, cur);
    }

    // for any cut to < ply, node must be removed
    ans[1]++, ans[ply]--;
    // for any cut to ply, only subtrees are removed
    // for any cut to > ply, we increment by 1 for values > deepest point
    ans[mxdepth + 1]++;

    return mxdepth;
}

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        cin >> n;

        vector<vector<int>> adj(n + 1);
        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> ans(n + 3);
        dfs(1, 1, 1, adj, ans);
        for (int i = 1; i <= n; i++) {
            ans[i] += ans[i - 1];
        }

        int minop = INF;
        for (int i = 1; i <= n; i++) {
            minop = min(minop, ans[i]);
        }

        cout << minop << '\n';
    }
}

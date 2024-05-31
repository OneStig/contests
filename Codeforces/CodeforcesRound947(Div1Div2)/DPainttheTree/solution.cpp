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

const int MAX_N = 2e5 + 1;

int n, a, b;
int depths[MAX_N], last[MAX_N];

int dfs(int x, int par, vector<vector<int>>& adj) {
    int depth{};

    for (int& nb : adj[x]) {
        if (nb == par) continue;

        depth = max(depth, dfs(nb, x, adj) + 1);
    }

    return depth;
}

void dfs2(int x, int par, vector<vector<int>>& adj) {
    last[x] = par;
    depths[x] = depths[par] + 1;

    if (x == b) return;

    for (int& nb : adj[x]) {
        if (nb == par) continue;

        dfs2(nb, x, adj);
    }
}

void solve() {
    cin >> n >> a >> b;
    a--, b--;

    vector<vector<int>> adj(n);

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ans{}, dist;

    if (a != b) {
        // find midpoint where b first colors something blue
        depths[a] = -1;
        dfs2(a, a, adj);
        int middepth = depths[b] / 2;

        while (depths[b] != middepth) {
            ans++;
            b = last[b];
        }
    }

    int mxdist = dfs(b, -1, adj);
    ans += 2 * (n - 1) - mxdist;


    cout << ans << '\n';
}

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}

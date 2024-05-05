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

void dfs(int x, int par, vector<int>& xa, vector<vector<array<int, 2>>>& adj, int end) {
    if (x == end) {
        return;
    }

    for (auto& nb : adj[x]) {
        if (nb[0] == par) continue;

        xa[nb[0]] = xa[x] ^ nb[1];
        dfs(nb[0], x, xa, adj, end);
    }
}

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    a--, b--;

    vector<vector<array<int, 2>>> adj(n);

    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> xora(n, -1), xorb(n, -1);
    xora[a] = 0;
    xorb[b] = 0;
    dfs(a, -1, xora, adj, b);
    dfs(b, -1, xorb, adj, -1);

    if (xora[b] == 0) {
        cout << "YES\n";
        return;
    }

    xora[b] = -1;
    xorb[b] = -1;

    set<int> bvals;
    for (int& bv : xorb) {
        if (bv != -1) {
            bvals.insert(bv);
        }
    }

    bool yes = 0;
    for (int& av : xora) {
        if (av != -1 && bvals.contains(av)) {
            yes = 1;
            break;
        }
    }

    cout << (yes ? "YES\n" : "NO\n");
}

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int t;
    cin >> t;

    while (t--) {
        dbg(t);
        solve();
    }
}

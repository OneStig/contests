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

void dfs(int x, int par, vector<vector<int>>& adj, string& s, array<int, 4>& leaves) {
    int count{};
    for (int& nb : adj[x]) {
        if (nb == par) continue;
        count++;
        dfs(nb, x, adj, s, leaves);
    }

    if (count == 0) {
        if (s[x] == '0') leaves[0]++;
        else if (s[x] == '1') leaves[1]++;
        else leaves[2]++;
    }
    else if (x != 0 && s[x] == '?') {
        leaves[3]++;
    }
}

void solve() {
    int n;
    string s;
    cin >> n;

    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cin >> s;

    // is each leaf 0, 1 or ?
    char root = s[0];
    array<int, 4> leaves = {0, 0, 0, 0};
    dfs(0, 0, adj, s, leaves);

    dbg(root, leaves);

    int change = 1;
    if (root == '?') {
        if (leaves[1] == leaves[0] && leaves[3] % 2 == 1) {
            // change can stay 1, arbitrariliy defer root selection
            root = '0';
        }
        else {
            change = 0;
            root = (leaves[1] > leaves[0] ? '0' : '1');
        }
    }
    int ans = (root == '0' ? leaves[1] : leaves[0]) + (leaves[2] + change) / 2;

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

// Intermediary nodes don't matter?
// since it's substring, weight is only nonzero if root != leaf

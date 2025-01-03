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

const int MAX_N = 2e5 + 1;
int n, m, b, e;

void solve() {
    cin >> n >> m;

    vector<set<int>> adj(n + m);
    vector<int> depth(n + m, -1);

    map<int, int> color;

    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        u--, v--;

        if (color.contains(c)) {
            c = color[c] + n;
        }
        else {
            color[c] = sz(color);
            c = color[c] + n;
        }

        adj[c].insert(u);
        adj[c].insert(v);

        adj[v].insert(c);
        adj[u].insert(c);
    }

    cin >> b >> e;
    b--, e--;

    depth[b] = 0;

    queue<int> bfs;
    bfs.push(b);

    while (!bfs.empty()) {
        int cur = bfs.front();
        bfs.pop();

        if (cur == e) {
            break;
        }

        for (int nb : adj[cur]) {
            if (depth[nb] == -1) {
                depth[nb] = depth[cur] + 1;
                bfs.push(nb);
            }
        }
    }

    cout << depth[e] / 2 << '\n';
}

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}

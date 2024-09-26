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

const int INF = 1e16;

void dijk(int start, vector<bool>& horse, vector<vector<pair<int, int>>>& adj, vector<int>& dist) {
    if (horse[start]) start += sz(adj) / 2;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [d, cur] = pq.top();
        pq.pop();
        if (dist[cur] != INF) continue;
        dist[cur] = d;

        for (auto& [nb, w] : adj[cur]) {
            if (dist[nb] == INF) {
                pq.push({d + w, nb});
            }
        }
    }
}

void solve() {
    int n, m, h;
    cin >> n >> m >> h;
    vector<bool> horse(n + 1);
    for (int i = 0; i < h; i++) {
        int a;
        cin >> a;
        horse[a] = 1;
    }

    vector<vector<pair<int, int>>> adj(2 * n + 1);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        adj[n + u].push_back({n + v, w / 2});
        adj[n + v].push_back({n + u, w / 2});

        if (horse[u]) {
            adj[v].push_back({n + u, w});
        }
        else {
            adj[v].push_back({u, w});
        }

        if (horse[v]) {
            adj[u].push_back({n + v, w});
        }
        else {
            adj[u].push_back({v, w});
        }
    }

    vector<int> rob(2 * n + 1, INF), mar(2 * n + 1, INF);
    dijk(1, horse, adj, rob);
    dijk(n, horse, adj, mar);

    int best = INF;

    for (int i = 1; i <= n; i++) {
        int a = min(rob[i], rob[n + i]), b = min(mar[i], mar[n + i]);
        best = min(best, max(a, b));
    }

    cout << (best == INF ? -1 : best) << '\n';
}

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}

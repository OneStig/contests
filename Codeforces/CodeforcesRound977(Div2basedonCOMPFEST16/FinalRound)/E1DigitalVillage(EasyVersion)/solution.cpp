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

const int INF = 1e12;

void dfs(int x, int cur, vector<vector<pair<int, int>>>& adj, vector<int>& mn) {
    for (auto& nb : adj[x]) {
        int test = max(cur, nb.second);
        if (mn[nb.first] > test) {
            mn[nb.first] = test;
            dfs(nb.first, test, adj, mn);
        }
    }
}

void solve() {
    int n, m, p;
    cin >> n >> m >> p;
    vector<int> s(p);
    for (int& x : s) cin >> x;

    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<vector<int>> each(n + 1, vector<int>(n + 1, INF));
    vector<int> bests(n + 1, INF);

    for (int& st : s) {
        each[st][st] = 0;
        dfs(st, 0, adj, each[st]);
        // dbg(st, each[st]);
    }

    for (int k = 1; k <= n; k++) {
        if (k >= p) {
            cout << "0 ";
            continue;
        }

        int score = INF, best = -1;
        for (int& st : s) {
            int sum{};
            for (int& targ : s) {
                sum += min(bests[targ], each[st][targ]);
            }

            if (sum < score) {
                best = st;
                score = sum;
            }
        }

        // update the bests
        for (int& st : s) {
            bests[st] = min(bests[st], each[best][st]);
        }

        cout << score << ' ';
    }
    cout << '\n';
}

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}

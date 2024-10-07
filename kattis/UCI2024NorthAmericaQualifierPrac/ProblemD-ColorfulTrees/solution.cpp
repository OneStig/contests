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

const int MAX_N = 1e5 + 1;

int c[MAX_N];
int tot[MAX_N];

map<int, int> dfs(int x, int par, vector<set<int>>& adj, vector<int>& ans) {
    adj[x].erase(par);

    int xans{};
    map<int, int> cur;

    for (int nb : adj[x]) {
        map<int, int> nxt = dfs(nb, x, adj, ans);
        xans += ans[nb];
        if (sz(nxt) > sz(cur)) {
            swap(cur, nxt);
        }

        for (auto& [col, count] : nxt) {
            if (cur.contains(col)) {
                xans -= 2 * cur[col] * count;
            }

            cur[col] += count;
        }
    }

    xans -= cur[c[x]];
    cur[c[x]]++;

    // dbg(xans);
    xans += tot[c[x]] - cur[c[x]];
    ans[x] = xans;

    // dbg(x, xans, cur);

    return cur;
}

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
        tot[c[i]]++;
    }


    vector<pair<int, int>> edges;
    vector<set<int>> adj(n + 1);

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        edges.emplace_back(u, v);
        adj[u].insert(v);
        adj[v].insert(u);
    }

    // root at 1
    vector<int> ans(n + 1);
    dfs(1, 1, adj, ans);

    for (auto& e : edges) {
        if (adj[e.first].contains(e.second)) {
            cout << ans[e.second] << '\n';
        }
        else {
            cout << ans[e.first] << '\n';
        }
    }
}

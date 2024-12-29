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

void solve() {
    int n, m;
    cin >> n >> m;

    vector<set<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
    }

    vector<array<int, 3>> ans;
    for (int cur = 1; cur <= n; cur++) {
        while (sz(adj[cur]) > 1) {
            int a = *adj[cur].begin();
            int b = *adj[cur].rbegin();
            adj[cur].erase(a);
            adj[cur].erase(b);
            adj[a].erase(cur);
            adj[b].erase(cur);

            m -= 2;

            if (adj[a].count(b)) {
                m--;
                adj[a].erase(b);
                adj[b].erase(a);
            }
            else {
                m++;
                adj[a].insert(b);
                adj[b].insert(a);
            }

            ans.push_back({cur, a, b});
        }
    }

    if (m != 0) {
        vector<int> mg;
        unordered_set<int> vis;
        int third = -1, last;
        for (int i = 1; i <= n; i++) {
            if (!vis.count(i)) {
                mg.push_back(i);
                if (sz(adj[i])) {
                    int p = *adj[i].begin();
                    vis.insert(p);

                    if (third == -1) {
                        third = p;
                        last = i;
                        mg.pop_back();
                    }
                }
            }
        }

        while (sz(mg)) {
            int cur = mg.back();
            mg.pop_back();
            ans.push_back({last, cur, third});
            last = cur;
        }
    }

    cout << sz(ans) << '\n';
    for (auto& an : ans) {
        cout << an[0] << ' ' << an[1] << ' ' << an[2] << '\n';
    }
}

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}

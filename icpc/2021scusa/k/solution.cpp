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

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int& x : a) cin >> x;

    vector<set<int>> adj;
    vector<vector<int>> edges(n);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (a[i] ^ a[j] ^ a[k] == 0) {
                    edges[i].push_back(sz(adj));
                    edges[j].push_back(sz(adj));
                    edges[k].push_back(sz(adj));

                    adj.push_back(set<int>());
                }
            }
        }
    }

    for (auto& e : edges) {
        for (int i = 0; i < sz(e); i++) {
            for (int j = i + 1; j < sz(e); j++) {
                adj[e[i]].insert(e[j]);
                adj[e[j]].insert(e[i]);
            }
        }
    }

    int ans{};
    int nodes = sz(adj);
    vector<bool> exist(nodes, 1);

    while (nodes > 0) {
        // dbg(nodes, adj);
        // dbg(nodes);
        int mn = 100000000, mnx = -1;
        int mx = 0, mxx = -1;

        for (int i = 0; i < sz(adj); i++) {
            if (!exist[i]) continue;

            if (sz(adj[i]) < mn) {
                mn = sz(adj[i]);
                mnx = i;
            }

            if (sz(adj[i]) >= mx) {
                mx = sz(adj[i]);
                mxx = i;
            }
        }

        int del = -1;
        if (mn == 0) {
            del = mnx;
        }
        else if (mn == 1) {
            del = *adj[mnx].begin();
        }
        else {
            del = mxx;
        }

        for (int nb : adj[del]) {
            if (!exist[nb]) continue;
            exist[nb] = 0;

            for (int nnb : adj[nb]) {
                adj[nnb].erase(nb);
            }
            nodes--;
        }

        // dbg(del, mn, mx, mnx, mxx);

        adj[del] = set<int>();
        exist[del] = 0;
        nodes--;
        ans++;
    }

    cout << ans << '\n';
}

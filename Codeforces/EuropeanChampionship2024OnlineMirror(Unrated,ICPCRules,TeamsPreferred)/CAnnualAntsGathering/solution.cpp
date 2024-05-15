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

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<set<int>> adj(n);
    vector<int> ants(n, 1);

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;

        adj[u].insert(v);
        adj[v].insert(u);
    }

    int count = n;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> leaves;

    for (int i = 0; i < n; i++) {
        if (sz(adj[i]) == 1) {
            leaves.push({1, i});
        }
    }

    bool fail = 0;
    while (!leaves.empty()) {
        auto cur = leaves.top();
        leaves.pop();

        if (count == 1) {
            break;
        }

        int par = *(adj[cur.second].begin());

        if (ants[par] < cur.first) {
            fail = 1;
            break;
        }

        ants[par] += cur.first;
        adj[par].erase(cur.second);

        count--;

        if (sz(adj[par]) == 1) {
            leaves.push({ants[par], par});
        }
    }

    cout << (fail ? "NO" : "YES") << '\n';
}

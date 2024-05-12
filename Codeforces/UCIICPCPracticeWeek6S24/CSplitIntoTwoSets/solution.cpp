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

int n;

bool dfs(int x, vector<vector<int>>& adj, vector<array<int, 2>>& doms, vector<int>& assign) {
    int curcolor = assign[x];

    for (int& nb : adj[doms[x][0]]) {
        if (nb == x) continue;

        if (assign[nb] == 0) {
            assign[nb] = (curcolor == 1 ? 2 : 1);
            if (dfs(nb, adj, doms, assign)) {
                return true;
            }
        }
        else if (assign[nb] == curcolor) {
            return true;
        }
    }

    for (int& nb : adj[doms[x][1]]) {
        if (nb == x) continue;

        if (assign[nb] == 0) {
            assign[nb] = (curcolor == 1 ? 2 : 1);
            if (dfs(nb, adj, doms, assign)) {
                return true;
            }
        }
        else if (assign[nb] == curcolor) {
            return true;
        }
    }

    return false;
}

void solve() {
    cin >> n;

    vector<array<int, 2>> doms(n);
    vector<vector<int>> adj(n + 1);
    vector<int> assign(n);

    bool fail = 0;

    for (int i = 0; i < n; i++) {
        cin >> doms[i][0] >> doms[i][1];
        adj[doms[i][0]].push_back(i);
        adj[doms[i][1]].push_back(i);

        if (doms[i][0] == doms[i][1]) {
            fail = 1;
        }
    }

    if (!fail) {
        for (int i = 0; i < n; i++) {
            if (!assign[i]) {
                assign[i] = 1;
                if (dfs(i, adj, doms, assign)) {
                    fail = 1;
                    break;
                }
            }
        }
    }

    cout << (fail ? "NO" : "YES") << '\n';
}

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}

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

int MAX_N = 2e5;

int dfs(int x, int par, int ply, vector<vector<int>>& g, vector<int>& d) {
    int mn = -1, mx = -1;
    for (int& nb : g[x]) {
        if (nb == par) continue;

        int cur = dfs(nb, x, ply + 1, g, d);
        if (mx == -1) {
            mx = cur;
        }
        else {
            mn = cur;

            if (mn > mx) {
                swap(mn, mx);
            }
        }
    }

    if (mn == -1) {
        mn = ply;
    }

    if (mx == -1) {
        mx = ply;
    }

    d[x] = mn;
    return mx;
}

void dfs2(int x, int par, int ply, int plycap, vector<vector<int>>& g, vector<int>& d) {
    plycap = min(plycap, d[x]);

    if (ply == plycap + 1) {
        g[x] = vector<int>();
    }
    else {
        for (int& nb : g[x]) {
            if (nb == par) continue;

            dfs2(nb, x, ply + 1, plycap, g, d);
        }
    }
}

int count(int x, int par, vector<vector<int>>& g) {
    int cnt = 1;
    for (int& nb : g[x]) {
        if (nb == par) continue;
        cnt += count(nb, x, g);
    }

    return cnt;
}

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<vector<int>> g(n + 1);
    vector<int> d(n + 1);

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i = 0; i < log2(n); i++) {
        dfs(1, 0, 0, g, d);
        // dbg(d);
        dfs2(1, 0, 0, INT_MAX, g, d);
        // dbg(i, n - count(1, 0, g));
    }

    int ans = n - count(1, 0, g);
    cout << ans << '\n';
}

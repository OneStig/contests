#include <bits/stdc++.h>
#include <vector>

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

#define pi pair<int, int>

int c[1001];

const int INF = 1e12;

pi dfs(int x, vector<vector<int>>& adj) {
    if (adj[x].empty()) {
        return {INF, c[x]};
    }

    pi cx = {INF, INF};

    set<int> seen;
    for (int nb : adj[x]) {
        pi nxt = dfs(nb, adj);

        cx.first = min(cx.first, c[x] + nxt.first);
        if (!seen.empty()) {
            cx.first = min(cx.first, c[x] + *seen.begin() + nxt.second);
        }
        seen.insert(nxt.second);
        cx.second = min(cx.second, c[x] + nxt.second);
    }

    return cx;
}

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    vector<int> deg(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }

    int ans = INF;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        deg[b]++;
    }

    set<int> singles;

    for (int i = 1; i <= n; i++) {
        if (deg[i] == 0) {
            pi cur = dfs(i, adj);
            ans = min(ans, cur.first);

            if (!singles.empty()) {
                ans = min(ans, *singles.begin() + cur.second);
            }

            singles.insert(cur.second);
        }
    }

    cout << ans << '\n';
}

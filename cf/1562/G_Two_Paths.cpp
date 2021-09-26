#include <bits/stdc++.h>
 
using namespace std;
 
#define F first
#define S second
 
#define pb push_back
#define mp make_pair
 
#define int long long
 
#define pii pair<int, int>
 
#define all(_) begin(_), end(_)
 
#define smx(y, x) ((y) = max(x, y))
#define smn(y, x) ((y) = min(x, y))
 
void setIO() {
    ios_base::sync_with_stdio(false);
 
    cin.tie(nullptr);
    cout.tie(nullptr);
}
 
const int N = 6e5 + 5;
const int L = 2e1 + 1;
 
const int inf = 9e17;
const int mod = 1e9 + 7; 
 
int xyz = 1; // test cases
 
int n, q;
 
int timer;
 
int arr[N];
int bit[N];
 
int dis[N];
int dep[N];
int add[N];
int prn[N][L];
 
int ans[N];
 
int dp[N];
int ti[N];
int to[N];
 
vector<pii> con[N];
vector<int> que[N];
 
bool anc(int x, int y) {
    return ti[x] <= ti[y] && to[y] <= to[x];
}
 
int lca(int u, int v) {
    if (dep[u] > dep[v])
        swap(u, v);
 
    if (anc(u, v)) return u;
 
    for (int i = 20; i >= 0; i--)
        if (prn[v][i] && !anc(prn[v][i], u))
            v = prn[v][i];
 
    return prn[v][0];
}
 
int get(int i) {
    int res = 0;
    for (; i > 0; i -= (-i & i))
        res += bit[i];
    return res;
}
 
void upd(int i, int x) {
    for (; i < N; i += (-i & i))
        bit[i] += x;
}
 
int dfs(int i, int p, int r, int d, int l) {
    ti[i] = ++timer;
 
    dis[i] = d;
    dep[i] = l;
 
    prn[i][0] = p;
    for (int j = 1; j < L; j++)
        prn[i][j] = prn[prn[i][j - 1]][j - 1];
 
    dp[i] = arr[i];
    for (auto [v, c] : con[i]) {
        if (v != p)
            dp[i] += dfs(v, i, c, d + c, l + 1);
    }
 
    to[i] = ++timer;
 
    return add[i] = max(0ll, dp[i] - 2 * r);
}
 
void rrt(int i, int p, int x) {
    /* cout << i << " > " << x << endl; */
 
    for (int j : que[i])
        ans[j] += x;
 
    for (auto [v, c] : con[i]) {
        if (v == p) continue;
 
        dp[i] -= add[v];
        dp[v] += max(0ll, dp[i] - 2 * c);
 
        rrt(v, i, max(0ll, dp[i] - 2 * c));
 
        dp[v] -= max(0ll, dp[i] - 2 * c);
        dp[i] += add[v];
    }
}
 
void run() {
    cin >> n >> q;
 
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
 
    for (int i = 2; i <= n; i++) {
        int u;
        int v;
        int w;
        cin >> u >> v >> w;
 
        con[u].emplace_back(v, w);
        con[v].emplace_back(u, w);
    }
 
    dfs(1, 0, 0, 0, 0);
 
    /* for (int i = 1; i <= n; i++) cout << i << ": " << dp[i] << " " << add[i] << endl; */
 
    for (int i = 1; i <= n; i++) {
        int v = dp[i] - add[i];
        upd(ti[i] + 0, +v);
        upd(to[i] + 1, -v);
    }
 
    for (int i = 1; i <= q; i++) {
        int u;
        int v;
        cin >> u >> v;
 
        int l = lca(u, v);
 
        ans[i] = dp[l];
        ans[i] -= dis[u] + dis[v] - 2 * dis[l];
        ans[i] += get(to[u]) - get(ti[l]);
        ans[i] += get(to[v]) - get(ti[l]);
 
        /* cout << i << ": " << get(to[u]) - get(ti[l]) << " " << get(to[v]) - get(ti[l]) << " | " << l << endl; */
 
        que[l].pb(i);
    }
 
    rrt(1, 0, 0);
 
    for (int i = 1; i <= q; i++)
        cout << ans[i] << "\n";
}
 
signed main() {
    setIO();
 
    while (xyz--)
        run();
 
#ifdef LOCAL
    cin.clear(); cout.flush(); system("pause");
#endif
 
    return 0;
}
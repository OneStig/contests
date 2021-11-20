#pragma GCC optimize("O3")
 
#include <bits/stdc++.h>
 
using namespace std;
 
#pragma region MACROS
 
#define F first
#define S second
 
#define pb push_back
#define mp make_pair
 
#define int int64_t
 
#define pii pair<int, int>
 
#define ee end
#define bb begin
#define all(_) begin(_), end(_)
 
#define smx(y, x) ((y) = max(x, y))
#define smn(y, x) ((y) = min(x, y))
 
#pragma endregion
 
void setIO() {
    ios_base::sync_with_stdio(false);
 
    cin.tie(nullptr);
    cout.tie(nullptr);
}
 
const int N = 2e5 + 5;
 
const int inf = 2e17;
const int mod = 1e9 + 7;
 
int xyz = 1; // test cases
 
int sqr(int x) {
    return x * x % mod;
}
 
int bin(int b, int e) {
    if (e == 0) return 1;
    if (e == 1) return b;
 
    return sqr(bin(b, e / 2)) * bin(b, e % 2) % mod;
}
 
int n, m;
 
int cnt;
 
int vis[N];
int clr[N];
 
vector<pii> con[N];
 
bool dfs(int i, int x) {
    cnt += (clr[i] = x);
 
    int res = true;
    for (auto [v, t] : con[i]) {
        if (clr[v] != -1) {
            if (clr[v] != (x ^ t)) {
                return false;
            }
        }
        else {
            res &= dfs(v, x ^ t);
        }
    }
 
    return res;
}
 
void mrk(int i) {
    clr[i] = -1;
    vis[i] = +1;
    for (auto [v, _] : con[i])
        if (!vis[v]) mrk(v);
}
 
void run() {
    cin >> n >> m;
 
    for (int i = 1; i <= n; i++) {
        vis[i] = +0;
        clr[i] = -1;
        con[i].clear();
    }
 
    for (int i = 1; i <= m; i++) {
        int u;
        int v;
        cin >> u >> v;
 
        string z;
        cin >> z;
 
        int t;
        if (z == "imposter") t = 1;
        if (z == "crewmate") t = 0;
 
        con[u].emplace_back(v, t);
        con[v].emplace_back(u, t);
    }
 
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
 
        int cur = 0;
        int can = 0;
 
        cnt = 0;
        if (dfs(i, 0))
            can = true, smx(cur, cnt); mrk(i);
 
        cnt = 0;
        if (dfs(i, 1))
            can = true, smx(cur, cnt); mrk(i);
 
        if (!can) { cout << "-1\n"; return; }
 
        ans += cur;
    }
 
    cout << ans << "\n";
}
 
signed main() {
    setIO();
 
    cin >> xyz;
    while (xyz--)
        run();
 
    return 0;
}
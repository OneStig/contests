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
#define ve vector

const int INF = 1e15;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    ve<ve<int>> a(n, ve<int>(m));
    for (auto& x : a) for (auto& y : x) cin >> y;

    // ve<ve<ve<int>>> dp(n, ve<ve<int>>(m, ve<int>(m, INF)));

    ve<int> dp(m, INF);
    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        ve<int> ndp(m, INF);
        for (int r = 0; r < m; r++) {
            ve<int> ldp(m);
            for (int j = 0; j < m; j++) {
                ldp[j] = dp[j] + k * r;
                if (j != 0) {
                    ldp[j] = min(ldp[j], ldp[j - 1]);
                }
                ldp[j] += a[i][(j + r) % m];
                ndp[j] = min(ndp[j], ldp[j]);
            }
        }

        dp = ndp;
    }

    cout << dp[m - 1] << '\n';
}

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}

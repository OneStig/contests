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

const int INF = 1e9;

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int r, c, n;
    cin >> r >> c >> n;

    vector<vector<int>> g(r, vector<int>(c));
    for (auto& x : g) for (auto& y : x) cin >> y;

    vector<vector<int>> dp(r, vector<int>(n + 1, INF));

    for (int row = 0; row < r; row++) {
        dp[row][0] = 0;
    }

    for (int col = 0; col < c; col++) {
        vector<vector<int>> ndp(r, vector<int>(n + 1, INF));

        for (int row = 0; row < r; row++) {
            if (g[row][col] == -1) continue;
            bool pass = col != 0 && col != c - 1 && row != 0 && row != r - 1 &&
                        g[row - 1][col] > g[row][col] &&
                        g[row + 1][col] > g[row][col] &&
                        g[row][col - 1] != -1 && g[row][col - 1] < g[row][col] &&
                        g[row][col + 1] != -1 && g[row][col + 1] < g[row][col];

            for (int np = pass; np <= n; np++) {
                ndp[row][np] = dp[row][np - pass] + g[row][col];

                if (row != 0) {
                    ndp[row][np] = min(ndp[row][np], dp[row - 1][np - pass] + g[row][col]);
                }

                if (row != r - 1) {
                    ndp[row][np] = min(ndp[row][np], dp[row + 1][np - pass] + g[row][col]);
                }
            }
        }

        dp = ndp;
        // dbg(dp);
    }

    int best = INF;
    for (int row = 0; row < r; row++) {
        best = min(best, dp[row][n]);
    }

    if (best == INF) {
        cout << "impossible\n";
    }
    else {
        cout << best << '\n';
    }
}

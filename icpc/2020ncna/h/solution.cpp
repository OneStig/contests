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

const int MAX_B = 60;
const int MOD = 998244353;

int dp[MAX_B][101][101];

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, t;
    cin >> n >> t;

    dp[MAX_B - 1][0][0] = 1;

    for (int i = MAX_B - 2; i >= 0; i--) {
        bool cur = n & (1ll << i);
        // dbg(i, cur);
        for (int pj = 0; pj <= t; pj++) {
            for (int pk = 0; pk <= t; pk++) {
                int have = 2 * pk + cur;

                for (int j = 0; j <= t; j++) {
                    if (j > have) break;
                    int k = have - j;
                    if (k > t) continue;

                    dp[i][j][k] += dp[i + 1][pj][pk];
                    dp[i][j][k] %= MOD;
                    // dbg(i, j, k, dp[i][j][k]);
                }
            }
        }
    }

    int ans{};

    for (int j = 0; j <= t; j++) {
        ans += dp[0][j][0];
        ans %= MOD;
        // dbg(j, dp[0][j][0]);
    }

    cout << ans << '\n';
}

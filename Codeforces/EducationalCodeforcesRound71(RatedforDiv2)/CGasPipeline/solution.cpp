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

const int INF = 1e16;

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n, a, b;
        string s;
        cin >> n >> a >> b >> s;

        vector<array<int, 2>> dp(n + 1);
        dp[0][1] = INF;
        dp[0][0] = b;

        for (int i = 1; i <= n; i++) {
            if (s[i - 1] == '1' || (i < n && s[i] == '1')) {
                dp[i][0] = INF;
            }
            else {
                dp[i][0] = min(dp[i - 1][0] + a + b, dp[i - 1][1] + 2 * a + b);
            }

            dp[i][1] = min(dp[i - 1][0] + 2 * a + 2 * b, dp[i - 1][1] + a + 2 * b);
        }

        cout << dp[n][0] << '\n';
    }
}

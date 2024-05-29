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

const int MAX_H = 1e5 + 1, INF = 1e10;

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int m, x;
        cin >> m >> x;

        // dp[i][j] = min cost to achieve j happiness after i months
        vector<vector<int>> dp(2, vector<int>(MAX_H, INF));
        dp[0][0] = 0;

        int hsum{};

        for (int i = 0; i < m; i++) {
            int c, h;
            cin >> c >> h;
            hsum += h;

            for (int j = 0; j <= hsum; j++) {
                dp[1][j] = min(dp[1][j], dp[0][j]);

                if (dp[0][j] + c <= x * i) {
                    dp[1][j + h] = min(dp[1][j + h], dp[0][j] + c);
                }
            }
            swap(dp[0], dp[1]);
        }

        int ans{};

        for (int i = hsum; i >= 0; i--) {
            if (dp[0][i] < INF) {
                ans = i;
                break;
            }
        }

        cout << ans << '\n';
    }
}

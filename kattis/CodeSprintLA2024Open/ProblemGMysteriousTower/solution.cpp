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

#define pld pair<long double, long double>

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    vector<ld> p(n);
    for (ld& pb : p) cin >> pb;

    vector<vector<pld>> dp(n + 1, vector<pld>(n + 1));

    dp[0][0] = {0, 1};

    for (int i{}; i < n; i++) {
        vector<ld> exp;
        for (int j{}; j < n; j++) {
            if (dp[i][j].second == 0) continue;

            ld expectation = dp[i][j].first / dp[i][j].second;
            exp.push_back(expectation);

            ld up = p[i] * dp[i][j].second;
            ld down = (1 - p[i]) * dp[i][j].second;
            
            // if face up
            dp[i + 1][j + 1].first += (expectation + 1) * up;
            dp[i + 1][j + 1].second += up;

            // if face down
            if (j == 0) {
                dp[i + 1][0].first += expectation * down;
                dp[i + 1][0].second += down;
            }
            else {
                dp[i + 1][j - 1].first += (expectation + 1) * down;
                dp[i + 1][j - 1].second += down; 
            }
        }
    }

    ld ans{};

    vector<ld> expa;
    for (int d = 0; d <= n; d++) {
        ans += ((dp[n][d].first / dp[n][d].second) - d) * dp[n][d].second;
        expa.push_back(dp[n][d].first / dp[n][d].second);
    }

    cout << setprecision(15) << ans << '\n';
}

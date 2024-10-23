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

int dp[40][10][40];

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, K;
    cin >> n >> K;

    // dp construct answer up to ceil(l / 2)?
    // last dp pos cant have k / 2 since it connects on the flip

    // dp[i][j][k], up to position i, last digit was j, currently have k in a row

    // if last digit j, we increment for next digit, where k is 1 if not neighbor of j
    // otherwise it's current k + 1

    for (int d = 1; d <= 9; d++) {
        dp[0][d][1] = 1;
    }

    for (int i = 0; i < (n + 1) / 2; i++) {
        for (int dig = 0; dig <= 9; dig++) {
            for (int k = 1; k < K; k++) {
                if (dp[i][dig][k]) {
                    for (int nd = 0; nd <= 9; nd++) {
                        if (abs(dig - nd) == 1) {
                            dp[i + 1][nd][k + 1] += dp[i][dig][k];
                        }
                        else {
                            dp[i + 1][nd][1] += dp[i][dig][k];
                        }
                    }
                }
            }
        }
    }

    if (n % 2 == 1) {
        K = K / 2 + 1;
    }

    // dbg(endlim);

    int ans{};
    for (int dig = 0; dig <= 9; dig++) {
        // ^ elijah if ur reading this ;)

        for (int k = 1; k < K; k++) {
            ans += dp[(n + 1) / 2 - 1][dig][k];
        }
    }

    cout << ans << '\n';
}

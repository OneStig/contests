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

const int MOD = 998244353;

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<array<int, 2>> dp(n + 1);
        dp[0] = {1, 1};

        int mn{}, mx{};

        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;

            vector<int> vals = {mn + x, abs(mn + x), };

            if (mn != mx) {
                vals.push_back(mx + x);
                vals.push_back(abs(mx + x));
            }

            int newmn = *min_element(all(vals));
            int newmx = *max_element(all(vals));

            for (int j = 0; j < sz(vals); j++) {
                if (vals[j] == newmn) {
                    dp[i][0] += dp[i - 1][j / 2];
                }

                if (vals[j] == newmx) {
                    dp[i][1] += dp[i - 1][j / 2];
                }

            }

            mn = newmn;
            mx = newmx;

            dp[i][0] %= MOD;
            dp[i][1] %= MOD;
        }

        cout << dp[n][1] << '\n';
    }
}

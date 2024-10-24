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

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n + 1), dp(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        int streak{};
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1];

            if (a[i] != 0) {
                dp[i]++;
            }

            if (i != 1) {
                int subgrids = (max(a[i], a[i - 1]) + 1) / 2;
                dp[i] = min(dp[i], dp[i - 2] + subgrids);
            }

            if (a[i] <= 2 && streak >= 2 && streak % 2 == 0 && i - streak >= 2 && a[i - streak - 1] <= 2) {
                dp[i] = min(dp[i], dp[i - streak - 2] + streak + 1);
            }

            if (a[i] == 3 || a[i] == 4) {
                streak++;
            }
            else {
                streak = 0;
            }
        }

        cout << dp[n] << '\n';
    }
}

// xx
// xxxx
// xxxx
// xx

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

const int BIG = 1e10;

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int w, f, n;
        cin >> w >> f >> n;
        vector<int> s(n);
        int totcost = 0;
        for (int& x : s) {cin >> x; totcost += x;}

        // build up fire/water for ans # of seconds, then cast all spells at once
        vector<bool> dp(totcost + 1);
        dp[0] = 1;

        // find reachable sums
        for (int& m : s) {
            for (int i = totcost; i - m >= 0; i--) {
                dp[i] = dp[i] || dp[i - m];
            }
        }

        int ans = BIG;
        for (int i = 0; i <= totcost; i++) {
            // if we want to fill dp[i] with water
            // what is the cost?
            if (dp[i]) {
                ans = min(ans, max(
                    (i + w - 1) / w,
                    (totcost - i + f - 1) / f
                ));
            }
        }

        cout << ans << '\n';
    }
}

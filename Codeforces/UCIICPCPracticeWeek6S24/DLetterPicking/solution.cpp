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

void solve() {
    string s;
    cin >> s;
    int n = sz(s);

    // 0 bob, 1 draw, 2 alice
    vector<vector<uci>> dp(n, vector<uci>(n));

    for (int l = n - 2; l >= 0; l--) {
        for (int r = l + 1; r < n; r += 2) {
            // size 2 case
            if (r - l == 1) {
                dp[l][r] = (s[r] == s[l] ? 1 : 2);
            }
            else {
                int leftleft = dp[l + 2][r];
                if (leftleft == 1) {
                    if (s[l] < s[l + 1]) {
                        leftleft = 2;
                    }
                    else if (s[l] > s[l + 1]) {
                        leftleft = 0;
                    }
                }

                int leftright = dp[l + 1][r - 1];
                if (leftright == 1) {
                    if (s[l] < s[r]) {
                        leftright = 2;
                    }
                    else if (s[l] > s[r]) {
                        leftright = 0;
                    }
                }

                int rightleft = dp[l + 1][r - 1];
                if (rightleft == 1) {
                    if (s[r] < s[l]) {
                        rightleft = 2;
                    }
                    else if (s[r] > s[l]) {
                        rightleft = 0;
                    }
                }

                int rightright = dp[l][r - 2];
                if (rightright == 1) {
                    if (s[r] < s[r - 1]) {
                        rightright = 2;
                    }
                    else if (s[r] > s[r - 1]) {
                        rightright = 0;
                    }
                }

                dp[l][r] = max(min(leftleft, leftright), min(rightleft, rightright));
            }
        }
    }

    if (dp[0][n - 1] == 0) {
        cout << "Bob\n";
    }
    else if (dp[0][n - 1] == 1) {
        cout << "Draw\n";
    }
    else {
        cout << "Alice\n";
    }
}

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}

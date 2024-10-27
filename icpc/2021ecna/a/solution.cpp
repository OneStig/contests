#include <bits/stdc++.h>
#include <cwchar>

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
    int n;
    cin >> n;
    vector<int> dp(n + 1, INF);
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        // mul

        for (int f = 1; f <= sqrt(i); f++) {
            if (i % f == 0) {
                int f2 = i / f;
                dp[i] = min(dp[i], dp[f] + dp[f2]);
            }
        }

        // add

        for (int t = 1; t <= i / 2; t++) {
            int alt = i - t;
            dp[i] = min(dp[i], dp[alt] + dp[t]);
        }

        // concat
        string num = to_string(i);
        for (int j = 0; j < sz(num) - 1; j++) {
            string a = num.substr(0, j + 1);
            string b = num.substr(j + 1, sz(num) - j - 1);
            if (b[0] != '0') {
                dp[i] = min(dp[i], dp[stoll(a)] + dp[stoll(b)]);
            }
        }
    }

    cout << dp[n] << '\n';
}

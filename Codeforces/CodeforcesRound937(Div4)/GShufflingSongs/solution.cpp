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

        vector<int> genres(n), writers(n);
        map<string, int> as, bs;
        for (int i = 0; i < n; i++) {
            string a, b;
            cin >> a >> b;

            if (!as.contains(a)) as[a] = sz(as);
            if (!bs.contains(b)) bs[b] = sz(bs);

            genres[i] = as[a];
            writers[i] = bs[b];
        }

        vector<vector<bool>> dp(1 << n, vector<bool>(n));
        for (int i = 0; i < n; i++) {
            dp[1 << i][i] = 1;
        }

        int ans = n - 1;
        for (int m = 1; m < 1 << n; m++) {
            for (int i = 0; i < n; i++) {
                if (dp[m][i]) {
                    for (int j = 0; j < n; j++) {
                        if ((m & (1 << j)) == 0 && (genres[i] == genres[j] || writers[i] == writers[j])) {
                            dp[m + (1 << j)][j] = 1;
                            ans = min(ans, n - (__builtin_popcount(m) + 1));
                        }
                    }
                }
            }
        }

        cout << ans << '\n';
    }
}

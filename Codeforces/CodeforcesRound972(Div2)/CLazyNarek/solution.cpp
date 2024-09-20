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

    string narek = "narek";
    set<char> in = {
        'n', 'a', 'r', 'e', 'k'
    };

    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<string> a(n);
        for (auto& x : a) cin >> x;

        vector<int> dp(5, INT_MIN);
        dp[4] = 0;
        for (int i = 0; i < n; i++) {
            vector<int> ndp = dp;
            for (int l = 0; l < 5; l++) {
                int score = dp[l];
                char last = l;

                for (int j = 0; j < m; j++) {
                    if (a[i][j] == narek[(last + 1) % 5]) {
                        if (last == 3) {
                            score += 5;
                        }

                        last = (last + 1) % 5;
                    }
                    else if (in.contains(a[i][j])) {
                        score--;
                    }
                }
                ndp[last] = max(ndp[last], score);
            }

            dp = ndp;
        }

        int ans{};
        for (int i = 0; i < 5; i++) {
            ans = max(ans, dp[i] - ((i + 1) % 5));
        }

        cout << ans << '\n';
    }
}

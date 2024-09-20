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

    int t;
    cin >> t;

    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        vector<vector<vector<int>>> fwd(n, vector<vector<int>>(2, vector<int>(26)));
        vector<vector<vector<int>>> bwd(n, vector<vector<int>>(2, vector<int>(26)));

        for (int i = 0; i < n; i++) {
            if (i != 0) fwd[i] = fwd[i - 1];

            for (int j = 0; j < 26; j++) {
                if (s[i] - 'a' != j) {
                    fwd[i][i % 2][j]++;
                }
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            if (i != n - 1) bwd[i] = bwd[i + 1];

            for (int j = 0; j < 26; j++) {
                if (s[i] - 'a' != j) {
                    bwd[i][i % 2][j]++;
                }
            }
        }

        if (n % 2 == 0) {
            array<int, 2> ans = {INT_MAX, INT_MAX};
            for (int c = 0; c < 26; c++) {
                for (int p = 0; p < 2; p++) {
                    ans[p] = min(ans[p], fwd[n - 1][p][c]);
                }
            }
            cout << ans[0] + ans[1] << '\n';
        }
        else {
            int ans = INT_MAX;
            for (int i = 0; i < n; i++) {
                array<int, 2> cur = {INT_MAX, INT_MAX};
                for (int c = 0; c < 26; c++) {
                    for (int p = 0; p < 2; p++) {
                        int let = 0;
                        if (i != 0) let += fwd[i - 1][p][c];
                        if (i != n - 1) let += bwd[i + 1][1 - p][c];
                        cur[p] = min(cur[p], let);
                    }
                }

                ans = min(ans, cur[0] + cur[1]);
            }
            cout << ans + 1 << '\n';
        }
    }
}

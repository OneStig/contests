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
        int n, m;
        cin >> n >> m;

        vector<vector<int>> a(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }
        vector<vector<bool>> visit(n, vector<bool>(m));

        int ans{1};
        int target = gcd(a[0][0], a[n - 1][m - 1]);

        for (int test = 1; test * test <= target; test++) {
            if (target % test == 0) {
                array<int, 2> totest = {test, target / test};
                for (int fact : totest) {
                    if (target % fact == 0) {
                        visit[0][0] = 1;

                        for (int i = 0; i < n; i++) {
                            for (int j = 0; j < m; j++) {
                                if (i != 0 || j != 0) {
                                    bool possib = 0;

                                    if (i != 0) {
                                        possib |= visit[i - 1][j];
                                    }

                                    if (j != 0) {
                                        possib |= visit[i][j - 1];
                                    }

                                    visit[i][j] = possib & (a[i][j] % fact == 0);
                                }
                            }
                        }

                        if (visit[n - 1][m - 1]) {
                            ans = max(ans, fact);
                        }
                    }
                }
            }
        }

        cout << ans << '\n';
    }
}

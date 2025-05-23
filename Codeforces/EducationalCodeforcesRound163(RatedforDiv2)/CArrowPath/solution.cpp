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
        array<string, 2> grid;
        cin >> grid[0] >> grid[1];

        vector<vector<bool>> reach(2, vector<bool>(n));
        reach[0][0] = 1;

        for (int i = 0; i < n; i++) {
            for (int r = 0; r < 2; r++) if (reach[r][i]) {
                if (i != n - 1) {
                    if (grid[r][i + 1] == '>') {
                        reach[r][i + 2] = 1;
                    }

                    if (grid[1 - r][i] == '>') {
                        reach[1 - r][i + 1] = 1;
                    }
                }
            }
        }

        bool yes = reach[1][n - 1] || reach[0][n - 1] || reach[1][n - 2];

        cout << (yes ? "YES" : "NO") << '\n';
    }
}

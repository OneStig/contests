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

    int n;
    cin >> n;
    vector<string> g(n);
    vector<vector<bool>> lit(n, vector<bool>(n));

    for (auto& x : g) cin >> x;

    auto good = [&](int x, int y) -> bool {
        return (x >= 0 && x < n && y >= 0 && y < n && g[x][y] == '?');
    };

    bool yes = 1;
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            if (g[r][c] == '?') {
                for (int r1 = r + 1; r1 < n; r1++) {
                    if (g[r1][c] != '.' && g[r1][c] != '?') break;
                    lit[r1][c] = 1;
                }

                for (int r1 = r - 1; r1 >= 0; r1--) {
                    if (g[r1][c] != '.' && g[r1][c] != '?') break;
                    lit[r1][c] = 1;
                }

                for (int c1 = c + 1; c1 < n; c1++) {
                    if (g[r][c1] != '.' && g[r][c1] != '?') break;
                    lit[r][c1] = 1;
                }

                for (int c1 = c - 1; c1 >= 0; c1--) {
                    if (g[r][c1] != '.' && g[r][c1] != '?') break;
                    lit[r][c1] = 1;
                }
            }
            else if (g[r][c] != '.' && g[r][c] != 'X') {
                int need = g[r][c] - '0';
                int has = good(r + 1, c) +
                good(r - 1, c) +
                good(r, c + 1) +
                good(r, c - 1);

                if (need != has) {
                    yes = 0;
                    break;
                }
            }
        }

        if (!yes) break;
    }


    if (yes) {
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (g[r][c] == '.' && !lit[r][c]) {
                    yes = 0;
                    break;
                }

                if (g[r][c] == '?' && lit[r][c]) {
                    yes = 0;
                    break;
                }
            }

            if (!yes) break;
        }
    }

    cout << yes << '\n';
}

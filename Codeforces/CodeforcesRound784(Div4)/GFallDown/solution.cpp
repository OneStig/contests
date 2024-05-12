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
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);

    for (auto& s : grid) {
        cin >> s;
    }

    for (int c = 0; c < m; c++) {
        int bottom = n - 1;

        for (int r = n - 1; r >= 0; r--) {
            if (grid[r][c] == 'o') {
                bottom = r - 1;
            }
            else if (grid[r][c] == '*') {
                swap(grid[r][c], grid[bottom][c]);
                bottom--;
            }
        }
    }

    for (auto& s : grid) {
        cout << s << '\n';
    }
    cout << '\n';
}

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}

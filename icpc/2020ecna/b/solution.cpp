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

vector<int> dx{1, -1, 0, 0, 1, -1, 1, -1};
vector<int> dy{0, 0, 1, -1, 1, 1, -1, -1};

int n, m;

bool inside(int x, int y){
    return x < n && x >= 0 && y < m && y >= 0;
}

bool dp[11][11][105][8];
bool ndp[11][11][105][8];

void clr() {
    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 11; j++) {
            for (int k = 0; k <= 102; k++) {
                for (int d = 0; d < 8; d++) {
                    ndp[i][j][k][d] = 0;
                }
            }
        }
    }
}

void clr2() {
    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 11; j++) {
            for (int k = 0; k <= 102; k++) {
                for (int d = 0; d < 8; d++) {
                    dp[i][j][k][d] = 0;
                }
            }
        }
    }
}

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    vector<vector<char>> g(n, vector<char>(m));

    for (auto& x : g) for (auto& y : x) cin >> y;

    string s;
    int mxk;
    cin >> mxk >> s;

    if (mxk != 0 && mxk >= sz(s) - 1) {
        cout << "NO\n";
        return 0;
    }

    clr2();
    // dbg(s);
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            if (g[x][y] == s[0]) {
                for (int dir = 0; dir < 8; dir++) {
                    // dbg(x, y, 0, dir);
                    dp[x][y][0][dir] = 1;
                }
            }
        }
    }

    // dbg(s);

    for (int i = 0; i < sz(s) - 1; i++) {
        clr();
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < m; y++) {
                for (int k = 0; k <= mxk; k++) {
                    for (int dir = 0; dir < 8; dir++) {
                        if (dp[x][y][k][dir]) {
                            for (int ndir = 0; ndir < 8; ndir++) {
                                int nx = x + dx[ndir], ny = y + dy[ndir];

                                if (inside(nx, ny) && g[nx][ny] == s[i + 1]) {
                                    ndp[nx][ny][k + (i != 0 && dir != ndir)][ndir] = 1;
                                }
                            }
                        }
                    }
                }
            }
        }

        swap(dp, ndp);
    }

    bool good = 0;
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            for (int dir = 0; dir < 8; dir++) {
                if (dp[x][y][mxk][dir]) {
                    // dbg(x, y, mxk, dir);
                    good = 1;
                }
            }
        }
    }

    cout << (good ? "YES" : "NO") << '\n';
}

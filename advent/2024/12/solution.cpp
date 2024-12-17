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

    vector<string> g;
    string x;
    while (cin >> x) {
        g.push_back(x);
    }

    int r = sz(g);
    int c = sz(g[0]);

    vector<int> dr = {-1, 0, 1, 0};
    vector<int> dc = {0, 1, 0, -1};

    int ans = 0;
    int ans2 = 0;

    vector<vector<bool>> vis(r, vector<bool>(c));
    vector<vector<vector<bool>>> sides(r, vector<vector<bool>>(c, vector<bool>(4)));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < r; j++) {
            if (!vis[i][j]) {
                char targ = g[i][j];
                queue<pair<int, int>> q;
                q.push({i, j});

                vis[i][j] = 1;

                int area = 0;
                int perim = 0;
                int scount = 0;
                while (sz(q)) {
                    auto cur = q.front();
                    q.pop();

                    area++;
                    for (int d = 0; d < 4; d++) {
                        int nr = cur.first + dr[d];
                        int nc = cur.second + dc[d];

                        if (nr < 0 || nr >= r || nc < 0 || nc >= c || g[nr][nc] != targ) {
                            perim++;
                            
                            int unique = 1;
                            int left = (d + 3) % 4;
                            int right = (d + 1) % 4;

                            int lr = cur.first + dr[left];
                            int lc = cur.second + dc[left];

                            int rr = cur.first + dr[right];
                            int rc = cur.second + dc[right];

                            if (lr >= 0 && lr < r && lc >= 0 && lc < c &&
                                g[lr][lc] == targ && sides[lr][lc][d]) {
                                unique--;
                            }

                            if (rr >= 0 && rr < r && rc >= 0 && rc < c &&
                                g[rr][rc] == targ && sides[rr][rc][d]) {
                                unique--;
                            }

                            scount += unique;
                            sides[cur.first][cur.second][d] = 1;
                        }
                        else if (!vis[nr][nc]) {
                            vis[nr][nc] = 1;
                            q.push({nr, nc});
                        }
                    }
                }

                dbg(targ, area, scount, area * scount);

                ans += area * perim;
                ans2 += area * scount;
            }
        }
    }

    dbg(ans, ans2);
}

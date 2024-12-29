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
    string s;
    while (cin >> s) {
        g.push_back(s);
    }

    int n = sz(g), m = sz(g[0]);

    int sx, sy, ex, ey;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == 'S') {
                sx = i;
                sy = j;
            }
            else if (g[i][j] == 'E') {
                ex = i;
                ey = j;
            }
        }
    }

    map<pair<int, int>, int> dist;
    pair<int, int> cur = {sx, sy}, end = {ex, ey};
    dist[{sx, sy}] = 0;

    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    while (cur != end) {
        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i], ny = cur.second + dy[i];
            pair<int, int> nxt = {nx, ny};
            if (g[nx][ny] != '#' && !dist.count(nxt)) {
                dist[nxt] = dist[cur] + 1;
                cur = nxt;
                break;
            }
        }
    }

    int total = dist[end];

    int cheats = 0;
    for (auto [pos, d] : dist) {
        for (int i = 0; i < 4; i++) {
            int cx = pos.first + 2 * dx[i], cy = pos.second + 2 * dy[i];
            pair<int, int> c = {cx, cy};

            if (dist.count(c)) {
                int cdist = (total - dist[c]) + 2 + d;
                if (total - cdist >= 100) {
                    cheats++;
                }
            }
        }
    }

    dbg(cheats);

    int cheats2 = 0;

    for (auto [pos, d] : dist) {
        for (int cx = pos.first - 20; cx <= pos.first + 20; cx++) {
            for (int cy = pos.second - 20; cy <= pos.second + 20; cy++) {
                pair<int, int> c = {cx, cy};
                int cost = abs(pos.first - cx) + abs(pos.second - cy);
                if (cost > 20 || !dist.count(c)) continue;
            
                int cdist = (total - dist[c]) + cost + d;
            
                if (total - cdist >= 100) {
                    cheats2++;
                }
            }
        }
    }

    dbg(cheats2);
}

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

int n, k;

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> k;
    vector<vector<vector<char>>> grid(4, vector<vector<char>>(n, vector<char>(n)));
    for (auto& x : grid[0]) { // x is a row in grid[0]
        string s; // take in put of row
        cin >> s;

        // copy ever character per row over
        for (int j = 0; j < n; j++) {
            x[j] = s[j];
        }
    }

    for (int rot = 1; rot < 4; rot++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                grid[rot][j][n - i - 1] = grid[rot - 1][i][j];
                // cout << grid[rot][i][j];
            }
            // cout << '\n';
        }
    }

    int sx, sy{-1};
    for (int i = 0; i < n; i++) {
        if (sy != -1) break;
        for (int j = 0; j < n; j++) {
            if (grid[0][i][j] == 'E') {
                sx = i;
                sy = j;
                break;
            }
        }
    }

    int ans = -1;
    // x (row), y (col), rot (0, 1, 2, 3) + 1 is clockwise 90 degrees
    unordered_map<int, int> vis;
    queue<int> bfs;
    bfs.push({sx, sy, 0, 0});
    vis[{sx, sy, 0, 0}] = 1;
    while (!bfs.empty()) {
        auto cur = bfs.front();
        bfs.pop();
        // dbg(cur);

        // our neighbors are sx +- 1, sy +- 1, also increment steps % k
        // if we are going to the kth step, then we have to

        int nextStep = (cur[3] + 1) % k;
        int rotation = (cur[2] + (nextStep == 0)) % 4;

        if (grid[rotation][cur[0]][cur[1]] == 'X') {
            ans = vis[cur];
            break;
        }

        if (grid[rotation][cur[0]][cur[1]] == 'W') {
            continue;
        }

        vector<pair<int, int>> nbs = {
            {cur[0] + 1, cur[1]},
            {cur[0], cur[1] + 1},
            {cur[0] - 1, cur[1]},
            {cur[0], cur[1] - 1}
        };

        for (auto nb : nbs) {
            if (nb.first < 0 || nb.first >= n || nb.second < 0 || nb.second >= n) {
                continue;
            }

            if (grid[rotation][nb.first][nb.second] == 'W') continue;
            if (grid[rotation][nb.first][nb.second] == 'X') {
                ans = vis[cur];
                break;
            }

            array<int, 4> nxt = {nb.first, nb.second, rotation, nextStep};
            if (vis[nxt] == 0) {
                vis[nxt] = vis[cur] + 1;
                bfs.push(nxt);
                // dbg("push", cur, nxt);
            }
        }

        if (ans != -1) break;
    }

    cout << ans << '\n';
}

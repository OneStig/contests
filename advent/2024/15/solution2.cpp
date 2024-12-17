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

    string x;
    cin >> x;


    vector<string> g;
    int i = 0;
    int ar, ac;
    while (x[0] == '#') {
        g.push_back(x);
        for (int j = 0; j < sz(x); j++) {
            if(x[j] == '@') {
                ar = i;
                ac = j;
                break;
            }
        }
        
        cin >> x;

        i++;
    }

    string k;
    while (cin >> k) {
        x += k;
    }

    int R = sz(g);
    int C = sz(g[0]);

    C *= 2;
    vector<string> grid = vector<string>(R, string(C, ' '));

    g[ar][ac] = '.';

    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C / 2; c++) {
            if (g[r][c] == 'O') {
                grid[r][c * 2] = '[';
                grid[r][c * 2 + 1] = ']';
            }
            else {
                grid[r][c * 2] = g[r][c];
                grid[r][c * 2 + 1] = g[r][c];
            }

            if (r == ar && c == ac) {
                dbg(ar, ac, "");
                grid[r][c * 2] = '@';
            }
        }
        dbg(grid[r]);
    }

    ac *= 2;
    

    int ans = 0;

    map<char, pair<int, int>> dir = {
        {'<', {0, -1}},
        {'^', {-1, 0}},
        {'>', {0, 1}},
        {'v', {1, 0}}
    };

    for (char mv : x) {
        auto [dr, dc] = dir[mv];

        if (mv == '<' || mv == '>') {
            bool found = 0;
            int stop = 0;
            int br = ar;
            int bc = ac;

            for (; 1; stop++) {
                br += dr;
                bc += dc;

                if (grid[br][bc] == '#') {
                    break;
                }

                if (grid[br][bc] == '.') {
                    found = 1;
                    break;
                }
            }

            dbg(found, ar, ac, br, bc);

            if (found) {
                for (int count = 0; count <= stop; count++) {
                    grid[br][bc] = grid[br - dr][bc - dc];
                    br -= dr;
                    bc -= dc;
                }

                grid[ar][ac] = '.';
                ar += dr;
                ac += dc;
            }
        }
        else {
            set<pair<int, int>> moving;
            queue<pair<int, int>> tomove;
            tomove.push({ar, ac});
            moving.insert({ar, ac});

            bool good = 1;
            while (sz(tomove)) {
                auto cur = tomove.front();
                tomove.pop();

                pair<int, int> up = {cur.first + dr, cur.second};
                if (grid[up.first][up.second] == '#') {
                    good = 0;
                    break;
                }
                else if (grid[up.first][up.second] != '.' && !moving.contains(up)) {
                    moving.insert(up);
                    tomove.push(up);
                }

                if (grid[cur.first][cur.second] == ']') {
                    pair<int, int> left = {cur.first, cur.second - 1};
                    if (!moving.contains(left)) {
                        moving.insert(left);
                        tomove.push(left);
                    }
                }
                else if (grid[cur.first][cur.second] == '[') {
                    pair<int, int> right = {cur.first, cur.second + 1};
                    if (!moving.contains(right)) {
                        moving.insert(right);
                        tomove.push(right);
                    }
                }
            }

            if (good) {
                if (mv == 'v') {
                    for (auto it = moving.rbegin(); it != moving.rend(); it++) {
                        auto cur = *it;
                        grid[cur.first + dr][cur.second] = grid[cur.first][cur.second];
                        grid[cur.first][cur.second] = '.';
                    }
                }
                else {
                    for (auto it = moving.begin(); it != moving.end(); it++) {
                        auto cur = *it;
                        grid[cur.first + dr][cur.second] = grid[cur.first][cur.second];
                        grid[cur.first][cur.second] = '.';
                    }
                }

                ar += dr;
                ac += dc;
            }
        }

        dbg(ar, ac);
        for (auto& k : grid) {
            dbg(k);
        }
    }

    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            if (grid[r][c] == '[') {
                ans += r * 100 + c;
            }
        }
    }

    dbg(ans);
}

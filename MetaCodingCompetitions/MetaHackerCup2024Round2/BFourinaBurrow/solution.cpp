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

typedef array<int, 7> gs;

string g[6];
// set<int> wins[7];
vector<array<int, 8>> cwins;
vector<array<int, 8>> fwins;

int win2(const gs& st) {
    int winner = 0;
    cwins = vector<array<int, 8>>();
    fwins = vector<array<int, 8>>();

    for (int c = 0; c < 7; c++) {
        // wins[c].insert(20);
        for (int r = 0; r <= st[c]; r++) {
            bool curwin = 0;

            // vert (up)
            if (st[c] >= r + 3 && g[r][c] == g[r + 1][c] && g[r][c] == g[r + 2][c] && g[r][c] == g[r + 3][c]) {
                curwin = 1;
                // wins[c].insert(r + 1);
                // wins[c].insert(r + 2);
                // wins[c].insert(r + 3);

                if (g[r][c] == 'C') {
                    cwins.push_back({c, r, c, r + 1, c, r + 2, c, r + 3});
                }
                else {
                    fwins.push_back({c, r, c, r + 1, c, r + 2, c, r + 3});

                }
            }

            // horiz (right)
            if (c < 4 && st[c + 1] >= r && st[c + 2] >= r && st[c + 3] >= r && g[r][c] == g[r][c + 1] && g[r][c] == g[r][c + 2] && g[r][c] == g[r][c + 3]) {
                curwin = 1;
                // wins[c + 1].insert(r);
                // wins[c + 2].insert(r);
                // wins[c + 3].insert(r);

                if (g[r][c] == 'C') {
                    cwins.push_back({c, r, c + 1, r, c + 2, r, c + 3, r});
                }
                else {
                    fwins.push_back({c, r, c + 1, r, c + 2, r, c + 3, r});
                }
            }

            // diag (up right)
            if (c < 4 && st[c + 1] >= r + 1 && st[c + 2] >= r + 2 && st[c + 3] >= r + 3 && g[r][c] == g[r + 1][c + 1] && g[r][c] == g[r + 2][c + 2] && g[r][c] == g[r + 3][c + 3]) {
                curwin = 1;
                // wins[c + 1].insert(r + 1);
                // wins[c + 2].insert(r + 2);
                // wins[c + 3].insert(r + 3);
                if (g[r][c] == 'C') {
                    cwins.push_back({c, r, c + 1, r + 1, c + 2, r + 2, c + 3, r + 3});
                }
                else {
                    fwins.push_back({c, r, c + 1, r + 1, c + 2, r + 2, c + 3, r + 3});
                }
            }

            // diag (up left)
            if (c > 2 && st[c - 1] >= r + 1 && st[c - 2] >= r + 2 && st[c - 3] >= r + 3 && g[r][c] == g[r - 1][c + 1] && g[r][c] == g[r - 2][c + 2] && g[r][c] == g[r - 3][c + 3]) {
                curwin = 1;
                // wins[c - 1].insert(r + 1);
                // wins[c - 2].insert(r + 2);
                // wins[c - 3].insert(r + 3);
                if (g[r][c] == 'C') {
                    cwins.push_back({c, r, c - 1, r + 1, c - 2, r + 2, c - 3, r + 3});
                }
                else {
                    cwins.push_back({c, r, c - 1, r + 1, c - 2, r + 2, c - 3, r + 3});
                }
            }

            if (curwin) {
                // wins[c].insert(r);
                if (g[r][c] == 'C') {
                    winner |= 1;
                }
                else {
                    winner |= 2;
                }
            }
        }
    }

    return winner;
}

int win(const gs& st) {
    int winner = 0;
    for (int c = 0; c < 7; c++) {
        for (int r = 0; r <= st[c]; r++) {
            if (
                (st[c] >= r + 3 && g[r][c] == g[r + 1][c] && g[r][c] == g[r + 2][c] && g[r][c] == g[r + 3][c]) ||
                (c < 4 && st[c + 1] >= r && st[c + 2] >= r && st[c + 3] >= r && g[r][c] == g[r][c + 1] && g[r][c] == g[r][c + 2] && g[r][c] == g[r][c + 3]) ||
                (c < 4 && st[c + 1] >= r + 1 && st[c + 2] >= r + 2 && st[c + 3] >= r + 3 && g[r][c] == g[r + 1][c + 1] && g[r][c] == g[r + 2][c + 2] && g[r][c] == g[r + 3][c + 3]) ||
                (c > 2 && st[c - 1] >= r + 1 && st[c - 2] >= r + 2 && st[c - 3] >= r + 3 && g[r][c] == g[r - 1][c + 1] && g[r][c] == g[r - 2][c + 2] && g[r][c] == g[r - 3][c + 3])
            ) {
                if (g[r][c] == 'C') {
                    winner |= 1;
                }
                else {
                    winner |= 2;
                }

                if (winner == 3) return 3;
            }
        }
    }

    return winner;
}


void solve() {
    for (int r = 5; r >= 0; r--) {
        cin >> g[r];
    }

    gs start = {-1, -1, -1, -1, -1, -1, -1};
    gs end = {5, 5, 5, 5, 5, 5, 5};
    // 0 = draw, 1 C, 2 F

    int potwin = win2(end);
    // dbg(sz(cwins), sz(fwins));
    // dbg(potwin);

    if (potwin != 3) {
        if (potwin == 0) {
            cout << "0\n";
        }
        else if (potwin == 1) {
            cout << "C\n";
        }
        else if (potwin == 2) {
            cout << "F\n";
        }

        return;
    }

    // for each win check if reachable
    int res = 0;
    for (auto& cur : cwins) {
        gs cs = start;
        for (int i = 0; i < 4; i++) {
            cs[cur[i * 2]] = cur[i * 2 + 1];
        }

        // dbg(cur, cs);
        int check = win(cs);
        if (check == 1) {
            res |= 1;
            break;
        }
    }

    for (auto& cur : fwins) {
        gs cs = start;
        for (int i = 0; i < 4; i++) {
            cs[cur[i * 2]] = cur[i * 2 + 1];
        }
        // dbg(2, cur, cs);

        int check = win(cs);
        if (check == 2) {
            res |= 2;
            break;
        }
    }

    if (res == 1) {
        cout << "C\n";
    }
    else if (res == 2) {
        cout << "F\n";
    }
    else {
        cout << "?\n";
    }
}

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
}

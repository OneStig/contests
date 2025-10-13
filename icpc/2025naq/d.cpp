#include <bits/stdc++.h>

using namespace std;

#define ONLINE_JUDGE

#ifndef ONLINE_JUDGE
#include "cpp-dump/cpp-dump.hpp"
#define dbg(...) cpp_dump(__VA_ARGS__)
#else
#define dbg(...)
#endif

typedef int uci;
#define int long long
#define ld long double
#define ve vector
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
typedef pair<int, int> pii;

#define double long double

int r, c;
bool inside(int i, int j) {
    return i >= 0 && j >= 0 && i < r && j < c;
}

uci main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> r >> c;

    int is, js, ie, je;
    cin >> is >> js >> ie >> je;
    is--, js--, ie--, je--;

    vector<vector<bool>> g(r, vector<bool>(c));
    for (int i = 0; i < r; i++) {
        string thisrow;
        cin >> thisrow;
        for (int j = 0; j < c; j++) {
            g[i][j] = thisrow[j] == '0';
        }
    }

    int i = is, j = js, dir = 0;
    int di[] = {0, 1, 0, -1};
    int dj[] = {1, 0, -1, 0};

    int max_steps = 50000;
    while (max_steps--) {
        if (i == ie && j == je) {
            cout << "1\n";
            return 0;
        }

        // turn left go forwards
        int leftdir = (dir + 3) % 4;
        int lefti = i + di[leftdir], leftj = j + dj[leftdir];
        if (inside(lefti, leftj) && g[lefti][leftj]) {
            i = lefti;
            j = leftj;
            dir = leftdir;
            continue;
        }

        int fori = i + di[dir], forj = j + dj[dir];
        if (inside(fori, forj) && g[fori][forj]) {
            i = fori;
            j = forj;
            continue;
        }

        dir = (dir + 1) % 4;
    }

    cout << "0\n";
}
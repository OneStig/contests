#include <bits/stdc++.h>

using namespace std;

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

const int MAX_B = 31;
const int MAX_N = 2e5 + 5;

int w[MAX_N], pfx[MAX_N];

int hbit(int x) {
    int res = -1;
    while (x != 0) {
        x /= 2;
        res++;
    }

    return res;
}

int go(int targ, int pos, ve<array<int, MAX_B>>& phigh) {
    if (pos == 0) return 0;

    int curh = hbit(targ);

    int dpos = 0;
    for (int b = curh; b < MAX_B; b++) {
        dpos = max(dpos, phigh[pos][b]);
    }

    int nxt = targ ^ pfx[pos] ^ pfx[dpos];
    if (dpos == 0 || w[dpos] > nxt) {
        return pos - dpos;
    }

    nxt ^= w[dpos];

    return pos - dpos + 1 + go(nxt, dpos - 1, phigh);
}

uci main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        int n, q;
        cin >> n >> q;

        for (int i = 1; i <= n; i++) {
            cin >> w[i];
            pfx[i] = pfx[i - 1] ^ w[i];
        }

        ve<array<int, MAX_B>> phigh(n + 1);
        for (int i = 1; i <= n; i++) {
            phigh[i] = phigh[i - 1];
            phigh[i][hbit(w[i])] = i;
        }

        while (q--) {
            int x;
            cin >> x;

            cout << go(x, n, phigh) << ' ';
        }
        cout << '\n';
    }
}

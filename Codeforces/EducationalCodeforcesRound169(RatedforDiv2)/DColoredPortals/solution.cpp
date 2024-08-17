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

const int INF = 1e9;

void solve() {
    // BG, RY
    // BY, GR
    // BR, GY
    map<string, int> what {
        {"BG", 0},
        {"RY", 0},
        {"BY", 1},
        {"GR", 1},
        {"BR", 2},
        {"GY", 2}
    };

    int n, q;
    cin >> n >> q;
    vector<string> c(n);

    for (string& x : c) cin >> x;

    // last occurence of something not of that type
    vector<array<int, 3> > pfx(n), sfx(n);
    pfx[0] = {0, 0, 0};
    pfx[0][what[c[0]]] = -1;
    sfx[n - 1] = {n - 1, n - 1, n - 1};
    sfx[n - 1][what[c[n - 1]]] = -1;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            if (j == what[c[i]]) {
                pfx[i][j] = pfx[i - 1][j];
            }
            else {
                pfx[i][j] = i;
            }
        }
    }

    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j < 3; j++) {
            if (j == what[c[i]]) {
                sfx[i][j] = sfx[i + 1][j];
            }
            else {
                sfx[i][j] = i;
            }
        }
    }
    dbg(pfx, sfx);

    while (q--) {
        int x, y;
        cin >> x >> y;
        x--, y--;

        if (x == y) {
            cout << 0 << '\n';
            continue;
        }

        if (x > y) {
            swap(x, y);
        }

        if (what[c[x]] != what[c[y]] || c[x] == c[y]) {
            cout << y - x << '\n';
            continue;
        }

        int ans = INF;

        int bw = pfx[y][what[c[y]]], fw = sfx[x][what[c[x]]];
        if (bw != -1) {
            ans = abs(y - bw) + abs(x - bw);
        }

        if (fw != -1) {
            ans = min(ans, abs(y - fw) + abs(x - fw));
        }

        cout << (ans == INF ? -1 : ans) << '\n';
    }
}

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}

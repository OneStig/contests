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

const int INF = 1e15;

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, k;
    cin >> n >> k;

    vector<vector<int>> g(n, vector<int>(n));
    vector<vector<pair<int, int>>> coords(k + 1);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> g[i][j];
            coords[g[i][j]].push_back({i, j});
        }
    }

    vector<int> dpr(n, INF), dpc(n, INF);

    for (auto& c : coords[1]) {
        dpr[c.first] = 0;
        dpc[c.second] = 0;
    }

    for (int ck = 2; ck <= k; ck++) {
        vector<int> ndpr(n, INF), ndpc(n, INF);

        for (auto& c : coords[ck]) {
            int best = INF;
            for (int i = 0; i < n; i++) {
                best = min(best, dpr[i] + (i - c.first) * (i - c.first));
                best = min(best, dpc[i] + (i - c.second) * (i - c.second));
            }

            ndpr[c.first] = min(ndpr[c.first], best);
            ndpc[c.second] = min(ndpc[c.second], best);
        }

        dpr = ndpr;
        dpc = ndpc;
    }

    int ans = INF;
    for (int& x : dpr) {
        ans = min(ans, x);
    }

    for (int& x : dpc) {
        ans = min(ans, x);
    }

    cout << (ans == INF ? -1 : ans) << '\n';
}

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

#define ll long long
typedef int uci;
#define int long long
#define ld long double
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

const int MAX_S = 1001;

void solve() {
    int n, q;
    cin >> n >> q;

    vector<vector<int>> pfx(MAX_S, vector<int>(MAX_S));

    for (int i = 0; i < n; i++) {
        int hi, wi;
        cin >> hi >> wi;
        pfx[hi][wi] += hi * wi;
    }

    for (int i = 1; i < MAX_S; i++) {
        for (int j = 1; j < MAX_S; j++) {
            pfx[i][j] += pfx[i - 1][j] + pfx[i][j - 1] - pfx[i - 1][j - 1];
        }
    }

    while (q--) {
        int hs, ws, hb, wb;
        cin >> hs >> ws >> hb >> wb;

        if (hs + 1 == hb || ws + 1 == wb) {
            cout << "0\n";
            continue;
        }

        int ans = pfx[hb - 1][wb - 1] - pfx[hb - 1][ws] - pfx[hs][wb - 1] + pfx[hs][ws];
        cout << ans << '\n';
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

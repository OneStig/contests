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

void solve() {
    int n, q;
    cin >> n >> q;
    string a, b;
    cin >> a >> b;

    vector<vector<int>> apfx(26, vector<int>(n + 1)), bpfx(26, vector<int>(n + 1));

    for (int i = 0; i < n; i++) {
        for (int c = 0; c < 26; c++) {
            apfx[c][i + 1] = apfx[c][i];
            bpfx[c][i + 1] = bpfx[c][i];
        }

        apfx[a[i] - 'a'][i + 1]++;
        bpfx[b[i] - 'a'][i + 1]++;
    }

    while (q--) {
        int l, r;
        cin >> l >> r;

        int total{};

        for (int c = 0; c < 26; c++) {
            total += abs((apfx[c][r] - apfx[c][l - 1]) - (bpfx[c][r] - bpfx[c][l - 1]));
        }

        cout << total / 2 << '\n';
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

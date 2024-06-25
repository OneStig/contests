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

int gcd (int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<vector<int>> heights(n, vector<int>(m));
    vector<vector<int>> types(n, vector<int>(m));
    
    int snow = 0, nosnow = 0;
    bool hasa = 0, hasb = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> heights[i][j];
        }
    }
    
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            types[i][j] = s[j] - '0';
            if (types[i][j] == 0) {
                snow += heights[i][j];
                hasa = true;
            } else {
                nosnow += heights[i][j];
                hasb = true;
            }

        }
    }

    vector<vector<int>> pfx(n + 1, vector<int>(m + 1));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            pfx[i][j] = (types[i - 1][j - 1] ? 1 : -1);
            pfx[i][j] += pfx[i - 1][j] + pfx[i][j - 1] - pfx[i - 1][j - 1];
        }
    }
    
    int diff = abs(snow - nosnow);

    if (diff == 0) {
        cout << "YES\n";
        return;
    }
    
    vector<int> diffs;
    for (int i = 0; i <= n - k; i++) {
        for (int j = 0; j <= m - k; j++) {
            int curdiff = pfx[i + k][j + k] - pfx[i + k][j] - pfx[i][j + k] + pfx[i][j];
            if (curdiff != 0) {
                diffs.push_back(abs(curdiff));
            }
        }
    }
    
    if (diffs.empty()) {
        cout << "NO\n";
        return;
    }
    
    int g = diffs[0];
    for (int i = 1; i < diffs.size(); i++) {
        g = gcd(g, diffs[i]);
    }

    cout << (diff % g == 0 ? "YES\n" : "NO\n");
}

uci main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}

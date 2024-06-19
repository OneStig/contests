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
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> before(n * m + 1), after(n * m + 1);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            before[x] = {i, j};
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            after[x] = {i, j};
        }
    }
    
    string ans = "YES";

    vector<int> row(n, -1), col(m, -1);

    for (int i = 1; i <= n * m; i++) {
        if (row[before[i].first] == -1) {
            row[before[i].first] = after[i].first;
        }
        else if (row[before[i].first] != after[i].first) {
            ans = "NO";
            break;
        }

        if (col[before[i].second] == -1) {
            col[before[i].second] = after[i].second;
        }
        else if (col[before[i].second] != after[i].second) {
            ans = "NO";
            break;
        }
    }

    cout << ans << '\n';
}

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}

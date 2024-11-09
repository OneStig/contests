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

void dfs(int x, vector<vector<int>>& lift, vector<vector<int>>& adj) {
    lift[x][0] = x;

    for (int& nb : adj[x]) {
        if (nb == lift[x][1]) continue;

        lift[nb][1] = x;
        dfs(nb, lift, adj);
    }
}

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> adj(n + 1);

    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> perm(n);
    for (int& x : perm) cin >> x;

    vector<vector<int>> lift(n + 1, vector<int>(4));
    lift[1][1] = 1;
    dfs(1, lift, adj);

    for (int up = 2; up < 4; up++) {
        for (int i = 1; i <= n; i++) {
            lift[i][up] = lift[lift[i][up - 1]][1];
        }
    }

    // dbg(lift);

    bool ans = 1;
    for (int i = 1; i < n; i++) {
        int a = perm[i - 1], b = perm[i];

        bool found = 0;
        for (int j = 0; j < 4; j++) {
            if (found) break;
            for (int k = 0; k < 4 - j; k++) {
                if (lift[a][j] == lift[b][k]) {
                    found = 1;
                    break;
                }
            }
        }

        if (!found) {
            ans = 0;
            break;
        }
    }

    cout << ans << '\n';
}

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int tc;
    cin >> tc;

    while (tc--) {
        solve();
    }
}

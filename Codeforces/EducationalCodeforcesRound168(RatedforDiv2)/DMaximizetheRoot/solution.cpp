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

const int MAX_A = 1e9;

int dfs(int x, vector<vector<int>>& adj, vector<int>& a) {
    if (adj[x].empty()) return a[x];

    int cur = a[x];
    int smchild = 1e9;

    for (int nb : adj[x]) {
        smchild = min(smchild, dfs(nb, adj, a));
    }

    if (smchild < cur) {
        a[x] = smchild;
    } else {
        a[x] = cur + (smchild - cur) / 2;
    }

    return a[x];
}

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int& x : a) cin >> x;

        vector<vector<int>> adj(n);

        for (int i = 1; i < n; i++) {
            int p;
            cin >> p;
            adj[p - 1].push_back(i);
        }

        int ans = a[0];

        dfs(0, adj, a);

        int sm = MAX_A;

        for (int nb : adj[0]) {
            sm = min(sm, a[nb]);
        }

        cout << ans + sm << '\n';
    }
}

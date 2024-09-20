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

// return # of groups, and # unpaired
pair<int, int> dfs(int x, int par, vector<vector<int>>& adj, int need) {
    int groups{}, unpaired = 1;
    for (int nb : adj[x]) {
        if (nb == par) continue;
        pair<int, int> resp = dfs(nb, x, adj, need);
        groups += resp.first;
        unpaired += resp.second;
    }

    if (unpaired >= need) {
        return {groups + 1, 0};
    }
    return {groups, unpaired};
}

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> adj(n + 1);

        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int ans = 1, l = 1, r = n;
        while (l <= r) {
            int mid = (l + r) / 2;
            pair<int, int> check = dfs(1, 0, adj, mid);

            if (check.first > k) {
                ans = max(ans, mid);
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }

        cout << ans << '\n';
    }
}

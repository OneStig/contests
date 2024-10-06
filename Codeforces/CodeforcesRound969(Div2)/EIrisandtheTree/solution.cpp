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

void dfs(int x, vector<vector<int>>& adj, vector<int>& subtree) {
    int cur = x;
    for (int& nb : adj[x]) {
        dfs(nb, adj, subtree);
        cur = max(cur, subtree[nb]);
    }
    subtree[x] = cur;
}

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n, w;
        cin >> n >> w;

        vector<int> p(n);
        vector<vector<int>> g(n);

        vector<int> st(n), left(n);
        int notfull = n;
        for (int i = 1; i < n; i++) {
            cin >> p[i];
            p[i]--;
            g[p[i]].push_back(i);
        }

        int total{};
        dfs(0, g, st);

        for (int i = 1; i < n; i++) {
            int prev = i - 1;
            left[prev]++;
            left[st[i]]++;
        }

        for (int ev = 1; ev < n; ev++) {
            int x, y;
            cin >> x >> y;
            x--;
            w -= y;

            int prev = (x - 1) % n;
            int next = st[x];

            total += 2 * y;

            if (--left[prev] == 0) notfull--;
            if (--left[next] == 0) notfull--;

            int ans = total + w * notfull;
            cout << ans << ' ';
        }

        cout << '\n';
    }
}

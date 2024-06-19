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

const int MAX_N = 50;

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    int tp;
    cin >> tp;
    stack<int> dfs;
    while (tp--) {
        int x;
        cin >> x;
        dfs.push(MAX_N + x);
    }

    vector<vector<int>> adj(101);

    for (int i = 0; i < m; i++) {
        int count;
        cin >> count;
        while (count--) {
            int pers;
            cin >> pers;
            adj[MAX_N + pers].push_back(i);
            adj[i].push_back(MAX_N + pers);
        }
    }

    vector<bool> vis(101);
    while (!dfs.empty()) {
        int cur = dfs.top();
        dfs.pop();

        if (vis[cur]) continue;
        vis[cur] = 1;

        for (int& nb : adj[cur]) {
            if (!vis[nb]) {
                dfs.push(nb);
            }
        }
    }

    int ans{};

    for (int i = 0; i < m; i++) {
        ans += !vis[i];
    }

    cout << ans << '\n';
}

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

const int MAX_N = 1e5 + 1;

vector<int> adj[MAX_N];
int parent[MAX_N];

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    while (m--) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    queue<int> bfs;
    bfs.push(1);
    parent[1] = -1;

    while (!bfs.empty()) {
        int cur = bfs.front();
        bfs.pop();

        for (int& nb : adj[cur]) {
            if (!parent[nb]) {
                parent[nb] = cur;
                bfs.push(nb);
            }
        }
    }

    if (!parent[n]) {
        cout << "IMPOSSIBLE\n";
    }
    else {
        vector<int> ans;
        int bt = n;
        while (bt != -1) {
            ans.push_back(bt);
            bt = parent[bt];
        }

        reverse(all(ans));
        cout << sz(ans) << '\n';
        for (int& x : ans) {
            cout << x << ' ';
        }

        cout << '\n';
    }
}

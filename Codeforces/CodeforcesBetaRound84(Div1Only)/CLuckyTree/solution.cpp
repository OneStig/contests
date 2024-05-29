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

int n;
int rel[MAX_N], ans[MAX_N], children[MAX_N];

void dfs(int x, int par, bool lucky, vector<vector<pair<int, bool>>>& adj) {
    int sum = 0;
    for (auto& nb : adj[x]) {
        if (nb.first == par) continue;
        dfs(nb.first, x, lucky || nb.second, adj);
        if (nb.second) {
            sum += children[nb.first];
        }
        else {
            sum += rel[nb.first];
        }
        children[x] += children[nb.first];
    }

    children[x]++;
    rel[x] = sum;
}

void dfs2(int x, int par, int above, vector<vector<pair<int, bool>>>& adj) {
    ans[x] = rel[above] + n - children[above];

    for (auto& nb : adj[x]) {
        if (nb.first == par) continue;
        int nextab = (nb.second ? nb.first : above);
        dfs2(nb.first, x, nextab, adj);
    }
}

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;

    vector<vector<pair<int, bool>>> adj(n);

    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;

        bool lucky = 1;

        while (w != 0) {
            if (w % 10 != 4 && w % 10 != 7) {
                lucky = 0;
                break;
            }
            w /= 10;
        }

        adj[u].push_back({v, lucky});
        adj[v].push_back({u, lucky});
    }

    dfs(0, -1, 0, adj);
    dfs2(0, -1, 0, adj);

    int total{};

    for (int i = 0; i < n; i++) {
        total += ans[i] * ans[i] - ans[i];
        dbg(ans[i], rel[i], children[i]);
    }

    cout << total << '\n';
}

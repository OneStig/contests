#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "cpp-dump/cpp-dump.hpp"
#define dbg(...) cpp_dump(__VA_ARGS__)
#else
#define dbg(...)
#endif

typedef int uci;
#define int long long
#define ld long double
#define ve vector
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
typedef pair<int, int> pii;

int n, d;

void dfs(int x, int par, ve<int>& stk, ve<ve<int>>& adj, set<int>& targ, set<int>& addit) {
    if (targ.count(x) && sz(stk) > d) {
        addit.insert(stk[sz(stk) - d - 1]);
    }

    for (int& nb : adj[x]) {
        if (nb == par) continue;

        stk.push_back(nb);
        dfs(nb, x, stk, adj, targ, addit);
        stk.pop_back();
    }
}

int dfs2(int x, int par, ve<ve<int>>& adj, set<int>& targ) {
    int sum = 0;

    for (int& nb : adj[x]) {
        if (nb == par) continue;

        int child = dfs2(nb, x, adj, targ);
        if (child != 0) {
            sum += child + 1;
        }
    }

    if (sum != 0 || targ.count(x)) {
        sum++;
    }

    return sum;
}

uci main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> d;

    ve<ve<int>> adj(n + 1);

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    set<int> visa, visb;
    int m;
    cin >> m;
    while (m--) {
        int a;
        cin >> a;
        visa.insert(a);
    }
    cin >> m;
    while (m--) {
        int b;
        cin >> b;
        visb.insert(b);
    }

    ve<int> stk = {1};
    dfs(1, 0, stk, adj, visa, visb);
    dfs(1, 0, stk, adj, visb, visa);

    int a = dfs2(1, 0, adj, visa) - 1;
    int b = dfs2(1, 0, adj, visb) - 1;

    dbg(visa, visb);
    dbg(a, b);

    cout << a + b << '\n';
}

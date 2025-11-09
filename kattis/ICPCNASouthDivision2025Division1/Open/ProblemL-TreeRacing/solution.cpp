#include <bits/stdc++.h>

using namespace std;

#define ONLINE_JUDGE

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

void dfs(int x, int p, ve<ve<int>>& adj, ve<int>& next) {
    next[x] = p;
    for (int& nb : adj[x]) {
        if (nb == p) continue;
        dfs(nb, x, adj, next);
    }
}

uci main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m, k;
    cin >> n >> m >> k;

    ve<ve<int>> adj(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    typedef array<int, 4> Event;

    priority_queue<Event, vector<Event>, greater<Event>> pq;

    for (int i = 0; i < m; i++) {
        int p, t;
        cin >> p >> t;
        pq.push({0, t, i, p});
    }

    int finish;
    cin >> finish;

    ve<int> next(n + 1);
    dfs(finish, -1, adj, next);

    int specialc;
    cin >> specialc;
    ve<int> remain(n + 1, 1e9);
    while (specialc--) {
        int x;
        cin >> x;
        remain[x] = k;
    }

    // result for racers
    ve<int> ans(m);

    // event: time - 0, speed - 1, racer - 2, node - 3
    while (sz(pq)) {
        Event cur = pq.top();
        pq.pop();
        
        if (remain[cur[3]] == 0) {
            ans[cur[2]] = -1;
            continue;
        }

        remain[cur[3]]--;
        if (cur[3] == finish) {
            ans[cur[2]] = cur[0];
            continue;
        }

        pq.push({cur[0] + cur[1], cur[1], cur[2], next[cur[3]]});
    }

    for (int& x : ans) {
        cout << x << '\n';
    }
}

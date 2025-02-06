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

uci main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;

    ve<ve<int>> adj(n + 10);
    ve<int> c(n + 10);

    for (int i = 1; i <= n; i++) {
        cin >> c[i];
        adj[c[i]].push_back(i);
    }

    ve<bool> vis(n + 10), cycle(n + 10);

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            set<int> local;
            int bt = i;

            while (!vis[bt]) {
                vis[bt] = 1;
                local.insert(bt);
                bt = c[bt];
            }

            if (local.count(bt)) {
                int nbt = bt;
                while (!cycle[nbt]) {
                    cycle[nbt] = 1;
                    nbt = c[nbt];
                }
            }
        }
    }

    ve<array<int, 3>> ans;

    queue<int> todo;
    for (int i = 1; i <= n; i++) {
        if (cycle[i]) {
            for (int nb : adj[i]) {
                if (!cycle[nb]) {
                    todo.push(nb);
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (cycle[i]) {
            int cur = i;
            while (cycle[cur]) {
                cycle[cur] = 0;
                if (cycle[c[cur]]) {
                    ans.push_back({1, cur, c[cur]});
                }

                cur = c[cur];
            }
        }
    }

    reverse(all(ans));

    while (sz(todo)) {
        int cur = todo.front();
        todo.pop();

        ans.push_back({2, c[cur], cur});

        for (int& nb : adj[cur]) {
            todo.push(nb);
        }
    }

    cout << sz(ans) << '\n';
    for (auto [x, y, z] : ans) {
        cout << x << ' ' << y << ' ' << z << '\n';
    }
}

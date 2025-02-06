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

#define vi vector<int>

bool s[250001];
int treesize[250001];
int pof[250001];
int dfsord[250001];
int clk = 0;

void dfs(int x, int p, ve<ve<int>>& adj, ve<int>& par) {
    dfsord[x] = clk++;
    par[x] = p;
    for (int& nb : adj[x]) {
        if (nb == p) continue;
        dfs(nb, x, adj, par);
    }
}

uci main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    ve<int> par(n + 1); ve<ve<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0, adj, par);

    auto cmp = [&](int a, int b) {
        return dfsord[a] < dfsord[b];
    };

    int q;
    cin >> q;

    while (q--) {
        int k;
        cin >> k;

        ve<int> todo(k);
        for (int i = 0; i < k; i++) {
            cin >> todo[i];
            s[todo[i]] = 1;
            treesize[todo[i]] = 1;
            pof[todo[i]] = todo[i];
        }

        sort(all(todo), cmp);

        int strength = 0;

        for (int i = 0; i < k; i++) {
            if (s[par[todo[i]]]) {
                treesize[pof[par[todo[i]]]] += treesize[todo[i]];
                pof[todo[i]] = pof[par[todo[i]]];
            }
        }

        for (int i = 0; i < k; i++) {
            s[todo[i]] = 0;

            if (pof[todo[i]] == todo[i]) {
                int setsize = treesize[todo[i]];
                strength += setsize * (setsize - 1) / 2;
            }
        }

        cout << strength << '\n';
    }
}

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

void dfs(int x, int p, ve<ve<int>>& adj, string& str, unordered_set<string>& guids, string& hexs) {
    str.push_back(hexs[x]);
    guids.insert(str);

    for (int& nb : adj[x]) {
        if (nb == p) continue;
        dfs(nb, x, adj, str, guids, hexs);
    }

    str.pop_back();
}

uci main() {
    cin.tie(0)->sync_with_stdio(0);

    string hexs;
    int n;
    cin >> n >> hexs;

    ve<pair<char, int>> starts(n);
    for (int i = 0; i < n; i++) {
        starts[i].first = hexs[i];
        starts[i].second = i;
    }

    sort(all(starts));

    ve<ve<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ans = 0;
    unordered_set<string> guids;
    char last = 'A';
    for (auto stp : starts) {
        int st = stp.second;

        if (last != stp.first) {
            ans += sz(guids);
            last = stp.first;
            guids = unordered_set<string>();
        }

        string str;

        dfs(st, -1, adj, str, guids, hexs);
    }

    cout << ans + sz(guids) << '\n';
}

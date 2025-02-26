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

const int MAX_N = 2e5;

bool rem[MAX_N];
int sub[MAX_N];

int dfs_s(ve<ve<int>>& adj, int c, int p = -1) {
    sub[c] = 1;
    for (int ch : adj[c]) {
        if (ch == p || rem[ch]) continue;
        sub[c] += dfs_s(adj, ch, c);
    }
    return sub[c];
}

int get_c(ve<ve<int>>& adj, int c, int n, int p = -1) {
    for (int ch : adj[c]) {
        if (ch == p || rem[ch]) continue;
        if (sub[ch] * 2 > n) {
            return get_c(adj, ch, n, c);
        }
    }

    return c;
}

int build(ve<ve<int>>& adj, ve<ve<int>>& cent, int c = 0) {
    int cen = get_c(adj, c, dfs_s(adj, c));
    rem[cen] = 1;

    for (int ch : adj[cen]) {
        if (!rem[ch]) {
            cent[cen].push_back(build(adj, cent, ch));
        }
    }
    return cen;
}

void dfs(ve<char>& ans, ve<ve<int>>& cent, int x, int ply = 0) {
    ans[x] = 'A' + ply;
    for (int ch : cent[x]) {
        dfs(ans, cent, ch, ply + 1);
    }
}

uci main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;

    ve<ve<int>> adj(n);

    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    ve<ve<int>> cent(n);
    int root = build(adj, cent);

    ve<char> ans(n);
    dfs(ans, cent, root);
    for (char c : ans) {
        cout << c << ' ';
    }

    cout << '\n';
}

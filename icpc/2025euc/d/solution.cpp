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

void dfs(int x, string pfx, ve<pii>& tree, ve<string>& ans) {
    if (tree[x].first == -1) {
        ans[x] = pfx;
    }
    else {
        dfs(tree[x].first, pfx + "-", tree, ans);
        dfs(tree[x].second, pfx + ".", tree, ans);
    }
}

uci main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;

    ve<ld> freq;
    ve<string> ans(n);

    priority_queue<pair<ld, int>> pq;

    for (int i = 0; i < n; i++) {
        ld cf;
        cin >> cf;
        freq.push_back(cf);

        pq.push({-cf, i});
    }

    ve<pii> tree(n, {-1, -1});

    while (sz(pq) > 1) {
        auto [afreq, a] = pq.top();
        pq.pop();
        auto [bfreq, b] = pq.top();
        pq.pop();

        if (afreq < bfreq) {
            swap(a, b);
        }

        ld newfreq = -afreq - bfreq;

        pq.push({-newfreq, sz(freq)});
        freq.push_back(newfreq);
        tree.push_back({a, b});
    }

    auto [_, root] = pq.top();
    dfs(root, "", tree, ans);

    for (auto& x : ans) {
        cout << x << '\n';
    }
}

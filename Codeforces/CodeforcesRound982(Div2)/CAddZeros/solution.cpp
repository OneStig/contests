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

void solve() {
    int n;
    cin >> n;

    map<int, ve<int>> moves;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        moves[a[i] + i - 1].push_back(i - 1);
    }

    // |a| = a_i + i - 1
    map<int, int> dp;

    for (auto it = moves.rbegin(); it != moves.rend(); it++) {
        auto& [len, tr] = *it;
        dp[len] = len;

        for (int& inc : tr) {
            dp[len] = max({dp[len], len + inc, dp[len + inc]});
        }
    }

    cout << max(n, dp[n]) << '\n';
}

uci main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}

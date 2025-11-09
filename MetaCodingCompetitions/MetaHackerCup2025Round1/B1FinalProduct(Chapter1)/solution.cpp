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

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    ve<int> ans(2 * n, 1);
    ans.back() = b;

    for (int& x : ans) {
        cout << ' ' << x;
    }

    cout << '\n';
}

uci main() {
    cin.tie(0)->sync_with_stdio(0);

    int tc;
    cin >> tc;

    for (int i = 1; i <= tc; i++) {
        cout << "Case #" << i << ":";
        solve();
    }
}

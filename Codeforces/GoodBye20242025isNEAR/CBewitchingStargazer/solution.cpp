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

pii recur(int r, int k) {
    if (r < k) return {0, 0};
    int m = (r + 1) / 2;
    if (r % 2 == 0) {
        auto [sum, child] = recur(m, k);
        return {2 * sum + child * m, 2 * child};
    }

    auto [sum, child] = recur(m - 1, k);
    return {2 * sum + child * m + m, 2 * child + 1};
}

uci main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        auto [ans, _] = recur(n, k);
        cout << ans << '\n';
    }
}

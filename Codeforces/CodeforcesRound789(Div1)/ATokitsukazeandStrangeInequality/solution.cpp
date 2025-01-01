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

uci main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        ve<int> p(n);
        for (int& x : p) cin >> x;

        ve<ve<int>> gt(n + 1, ve<int>(n + 1));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = 1; j <= n; j++) {
                gt[i][j] = gt[i + 1][j] + (p[i] < j);
            }
        }

        int ans = 0;
        for (int c = 2; c < n - 1; c++) {
            int combs = 0;
            for (int a = c - 2; a >= 0; a--) {
                combs += gt[c + 1][p[a + 1]];
                if (p[a] < p[c]) {
                    ans += combs;
                }
            }
        }

        cout << ans << '\n';
    }
}

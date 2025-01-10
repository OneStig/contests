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
        ve<int> b(n);

        for (int& x : b) cin >> x;

        ve<bool> dp(n);

        for (int i = 0; i < n; i++) {
            if ((i == 0 || dp[i - 1]) && i + b[i] < n) {
                dp[i + b[i]] = 1;
            }

            if (i - b[i] == 0 || (i - b[i] - 1 >= 0 && dp[i - b[i] - 1])) {
                dp[i] = 1;
            }
        }

        cout << (dp[n - 1] ? "YES" : "NO") << '\n';
    }
}

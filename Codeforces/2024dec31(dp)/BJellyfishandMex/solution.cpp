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

        map<int, int> f;
        ve<int> a(n);
        for (int& x : a) {
            cin >> x;
            f[x]++;
        }

        int mex = 5000;
        for (int i = 0; i < 5000; i++) {
            if (!f[i]) {
                mex = i;
                break;
            }
        }

        ve<int> dp(mex + 1, 1e9);
        dp[mex] = 0;
        for (int i = mex - 1; i >= 0; i--) {
            for (int j = i + 1; j <= mex; j++) {
                dp[i] = min(dp[i], f[i] * j + dp[j]);
            }
        }

        cout << dp[0] - mex << '\n';
    }
}

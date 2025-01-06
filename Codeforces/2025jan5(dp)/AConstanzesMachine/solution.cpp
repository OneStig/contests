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

const int MOD = 1e9 + 7;

uci main() {
    cin.tie(0)->sync_with_stdio(0);

    string s;
    cin >> s;
    int n = sz(s);

    ve<int> dp(n + 1);
    dp[0] = 1;

    for (int i = 0; i < n; i++) {
        if (s[i] == 'm' || s[i] == 'w') {
            dp[n] = 0;
            break;
        }

        if (i == 0 || s[i] != s[i - 1] || (s[i] != 'u' && s[i] != 'n')) {
            dp[i + 1] = dp[i];
        }
        else {
            dp[i + 1] = dp[i] + dp[i - 1];
        }

        dp[i + 1] %= MOD;
    }

    cout << dp[n] << '\n';
}

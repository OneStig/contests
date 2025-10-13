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

const int MAX_SUM = 90010;
const int MID_SUM = 45005;

uci main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    ve<int> a(n);

    for (int& x : a) {
        cin >> x;
    }

    int max_n = n + 10;
    int midn = max_n / 2;

    vector<bitset<MAX_SUM>> dp(max_n), ndp;
    // dp[halfn][MID_SUM] = 0;
    //
    // dp[delta ppl][delta sum] = max number of ppl assigned

    for (int i = 0; i < n; i++) {
        // 300^3
        // delta sum, 
    }
}

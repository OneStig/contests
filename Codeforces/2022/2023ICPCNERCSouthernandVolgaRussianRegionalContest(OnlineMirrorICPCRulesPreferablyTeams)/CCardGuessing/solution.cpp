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

const int MOD = 998244353;
const int MAX_N = 501;

int powmod(int a, int b) {
    int res = 1;
    a %= MOD;
    while (b > 0) {
        if (b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }

    return res;
}

int invmod(int a) {
    return powmod(a, MOD - 2);
}

int fact[4 * MAX_N], inv[4 * MAX_N];

int nck(int n, int k) {
    if (k < 0 || k > n) return 0;
    return (((fact[n] * inv[k]) % MOD) * inv[n - k]) % MOD;
}

uci main() {
    cin.tie(0)->sync_with_stdio(0);

    fact[0] = 1;
    for (int i = 1; i < MAX_N * 4; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }

    inv[4 * MAX_N - 1] = powmod(fact[4 * MAX_N - 1], MOD - 2);
    for (int i = 4 * MAX_N - 2; i >= 0; i--) {
        inv[i] = (inv[i + 1] * (i + 1)) % MOD;
    }

    int n, k;
    cin >> n >> k;

    int ans = 0;

    // go through all 4n cards
    for (int i = 1; i <= 4 * n; i++) {
        int kwindow = min(i - 1, k);
        for (int j = 0; j <= kwindow; j++) {
            // observed j count of "cur" suit in last k

            // how many total combinations such that we see j of them?
            //
            int total = nck(kwindow, j) * nck(4 * n - kwindow, n - j);

            // how many combinations such such that j is the min
        }
    }
}

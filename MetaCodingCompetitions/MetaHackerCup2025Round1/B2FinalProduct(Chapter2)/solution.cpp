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

const int MOD = 1e9 + 7;
const int mx = 70;

ve<int> fact(mx + 1), invf(mx + 1);

int modpow(int base, int exp) {
    int res = 1;

    base %= MOD;

    while (exp > 0) {
        if (exp % 2 == 1) {
            res = (res * base) % MOD;
        }

        base = (base * base) % MOD;
        exp /= 2;
    }

    return res;
}

int modinv(int x) {
    return modpow(x, MOD - 2);
}

ve<int> pfacts(int n){
    ve<int> out;
    if (n <= 1) return out;

    while (n % 2 == 0) out.push_back(2), n /= 2;
    while (n % 3 == 0) out.push_back(3), n /= 3;

    for (int i = 5; i * i <= n; i += 6){
        while (n % i == 0) {
            out.push_back(i);
            n /= i;
        }

        while (n % (i + 2) == 0) {
            out.push_back(i + 2);
            n /= (i + 2);
        }
    }

    if (n > 1) out.push_back(n);

    return out;
}

map<pii, int> cache;

int seqs(int n, int k) {
    if (k == 1) return 1;
    
    if (cache.count({n, k})) return cache[{n, k}];

    vector<int> p = pfacts(k);
    sort(all(p));

    vector<int> exps;
    for (int i = 0; i < sz(p);){
        int j = i;
        while (j < sz(p) && p[j] == p[i]) {
            j++;
        }
        exps.push_back(j - i);
        i = j;
    }

    auto stars = [&](int a){
        int num = 1;
        for (int i = 0; i < a; i++) {
            num = num * ((n + i) % MOD) % MOD;
        }
        return (num * invf[a]) % MOD;
    };

    int ans = 1;
    for (int a : exps) {
        ans = (ans * stars(a)) % MOD;
    }
    
    cache[{n, k}] = ans;
    return ans;
}

void solve() {
    int n, a, b;
    cin >> n >> a >> b;

    set<int> factors;
    for (int i = 1; i * i <= b; i++) {
        if (b % i == 0) {
            factors.insert(i);
            factors.insert(b / i);
        }
    }

    // for each possible midpoint <= a
    // count # of combs to mid, then # of combs up to b / mid

    int ans = 0;
    for (int mid : factors) {
        if (mid > a) break;
        int left = seqs(n, mid);
        int right = seqs(n, b / mid);
        ans = (ans + left * right) % MOD;
    }
     
    cout << ans << '\n';
}

uci main() {
    cin.tie(0)->sync_with_stdio(0);

    fact[0] = 1;
    for (int i = 1; i <= mx; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }
    invf[mx] = modinv(fact[mx]);
    for (int i = mx; i > 0; i--) {
        invf[i - 1] = invf[i] * i % MOD;
    }

    int tc;
    cin >> tc;

    for (int cs = 1; cs <= tc; cs++) {
        cout << "Case #" << cs << ": ";
        solve();
    }
}

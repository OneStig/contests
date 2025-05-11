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

const int PBOUND = 1e7;

uci main() {
    cin.tie(0)->sync_with_stdio(0);

    ve<int> lp(PBOUND + 1);
    ve<int> primes;

    for (int i = 2; i < PBOUND; i++) {
        if (lp[i] == 0) {
            lp[i] = i;
            primes.push_back(i);
        }

        for (int j = 0; i * primes[j] <= PBOUND; j++) {
            lp[i * primes[j]] = primes[j];
            if (primes[j] == lp[i]) {
                break;
            }
        }
    }

    ve<int> pfx(sz(primes));
    pfx[0] = primes[0];
    for (int i = 1; i < sz(primes); i++) {
        pfx[i] = pfx[i - 1] + primes[i];
    }
    dbg(sz(primes));

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        ve<int> a(n);
        for (int& x : a) cin >> x;
        sort(a.rbegin(), a.rend());

        int avail = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            avail += a[i];

            if (avail < pfx[i]) {
                ans = n - i;
                break;
            }
        }

        cout << ans << '\n';
    }
}

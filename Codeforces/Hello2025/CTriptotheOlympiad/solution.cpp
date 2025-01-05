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
        int l, r;
        cin >> l >> r;
        int maxb = log2(r) + 2;
        int m = 0;

        int dbit = -1;
        for (int b = maxb; b >= 0; b--) {
            int mask = 1 << b;
            bool lm = (l & mask);
            bool rm = (r & mask);
            int sum = lm + rm;

            if (sum == 1 && dbit == -1) {
                dbit = b;
            }

            if (dbit != -1) {
                if (sum != 1) {
                    m += (lm ? 0 : mask);
                }
            }
            else {
                m += (lm ? mask : 0);
            }
        }

        for (int b = dbit; b >= 0; b--) {
            int mask = 1 << b;
            bool lm = (l & mask);
            bool rm = (r & mask);
            int sum = lm + rm;

            if (sum == 1 && m <= l && m + mask < r) {
                m += mask;
            }
        }


        cout << l << ' ' << m << ' ' << r << '\n';
    }
}

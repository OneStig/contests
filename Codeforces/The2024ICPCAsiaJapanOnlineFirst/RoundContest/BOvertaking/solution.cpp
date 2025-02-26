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

    int n;
    while (cin >> n) {
        if (n == 0) break;
        ve<int> a(n), b(n);
        for (int& x : a) cin >> x;
        for (int& x : b) cin >> x;

        int ans = 0, last = 0, asum = 0, bsum = 0;
        for (int i = 0; i < n; i++) {
            asum += a[i], bsum += b[i];

            if (asum < bsum) {
                if (last == 1) {
                    ans++;
                }

                last = -1;
            }
            else if (asum > bsum) {
                if (last == -1) {
                    ans++;
                }
                last = 1;
            }
        }

        cout << ans << '\n';
    }
}

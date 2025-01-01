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
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        int x = -1, y = -1;
        for (int xc = a + 1; xc <= c; xc++) {
            int ytarg = lcm(a * b, xc) / xc;

            int l = 1, r = 1e5 + 1;
            while (l <= r) {
                int m = (l + r) / 2;

                if (ytarg * m > b && ytarg * m <= d) {
                    l = m;
                    break;
                }

                if (ytarg * m > b) {
                    r = m - 1;
                }
                else {
                    l = m + 1;
                }
            }

            if (ytarg * l > b && ytarg * l <= d) {
                x = xc;
                y = ytarg * l;
                break;
            }
        }

        cout << x << ' ' << y << '\n';
    }
}

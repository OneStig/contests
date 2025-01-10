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

    int q;
    cin >> q;

    while (q--) {
        int c, m, x;
        cin >> c >> m >> x;

        int l = 0, r = min({c, m});
        while (l < r) {
            int mid = (l + r + 1) / 2;
            int rem = x + c - mid + m - mid;

            if (rem < mid) {
                r = mid - 1;
            }
            else {
                l = mid;
            }
        }

        cout << l << '\n';
    }
}

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

    int x, y, l, r;
    cin >> x >> y >> l >> r;

    set<int> bad;

    int cx = 1;
    for (int i = 0; i < 60; i++) {
        int cy = 1;
        for (int j = 0; j < 60; j++) {
            bad.insert(cx + cy);

            if (cy < (r + y - 1) / y) {
                cy *= y;
            }
            else {
                break;
            }
        }

        if (cx < (r + x - 1) / x) {
            cx *= x;
        }
        else {
            break;
        }
    }

    ve<int> nums(all(bad));

    int gap = max(0ll, r - nums.back());

    for (int i = 1; i < sz(nums); i++) {
        int bot = max(nums[i - 1], l - 1);
        int top = min(nums[i], r + 1);

        gap = max(gap, top - bot - 1);
    }

    cout << gap << '\n';
}

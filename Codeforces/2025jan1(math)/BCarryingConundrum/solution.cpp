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
        string s;
        cin >> s;

        array<int, 2> nums = {0, 0};

        for (int i = 0; i < sz(s); i++) {
            nums[i % 2] *= 10;
            nums[i % 2] += s[i] - '0';
        }

        int ans = (nums[0] + 1) * (nums[1] + 1) - 2;
        cout << ans << '\n';
    }
}

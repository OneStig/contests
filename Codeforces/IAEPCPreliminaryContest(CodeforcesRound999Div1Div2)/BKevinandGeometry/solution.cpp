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
        int n;
        cin >> n;

        ve<int> pairs;
        map<int, int> freq;

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;

            if (++freq[x] == 2) {
                freq.erase(x);
                pairs.push_back(x);
            }
        }

        if (sz(pairs) == 0) {
            cout << "-1\n";
            continue;
        }

        if (sz(pairs) > 1) {
            cout << pairs[0] << ' ' << pairs[0] << ' ' << pairs[1] << ' ' << pairs[1] << '\n';
            continue;
        }

        int ans1 = -1, ans2, last = INT_MIN;
        for (auto [x, _] : freq) {
            if (x - last < 2 * pairs[0]) {
                ans1 = last;
                ans2 = x;
                break;
            }
            last = x;
        }

        if (ans1 == -1) {
            cout << "-1\n";
        }
        else {
            cout << ans1 << ' ' << ans2 << ' ' << pairs[0] << ' ' << pairs[0] << '\n';
        }
    }
}

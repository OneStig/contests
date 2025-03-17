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
        int n, k;
        cin >> n >> k;

        multiset<int> vids;
        for (int i = 0; i < n; i++) {
            int di;
            cin >> di;
            vids.insert(di);
        }

        int ans = 0;
        while (sz(vids)) {
            int first = *vids.begin();
            vids.erase(vids.begin());

            if (sz(vids) == 0) break;

            if (first >= k) {
                ans++;
                continue;
            }

            if (sz(vids) == 1) break;

            int target = k - first - 1;
            auto search = vids.upper_bound(target);

            if (search == vids.begin()) {
                vids.erase(prev(vids.end()));
                ans++;
                continue;
            }

            if (sz(vids) <= 2) break;

            search--;

            vids.erase(search);
            vids.erase(prev(vids.end()));
            
            ans++;
        }

        cout << ans << '\n';
    }
}

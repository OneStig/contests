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

        map<int, int> collide;
        vector<int> blocked;
        vector<pii> lr(n);

        for (int i = 0; i < n; i++) {
            cin >> lr[i].first >> lr[i].second;
            if (lr[i].first == lr[i].second) {
                if (++collide[lr[i].first] == 1) {
                    blocked.push_back(lr[i].first);
                }
            }
        }

        sort(all(blocked));

        for (int i = 0; i < n; i++) {
            int l = lr[i].first;
            int r = lr[i].second;

            if (l == r) {
                cout << (collide[l] == 1);
            }
            else {
                int lb = lower_bound(all(blocked), l) - blocked.begin();
                int ub = upper_bound(all(blocked), r) - blocked.begin() - 1;

                cout << (ub - lb != r - l);
            }
        }

        cout << '\n';
    }
}

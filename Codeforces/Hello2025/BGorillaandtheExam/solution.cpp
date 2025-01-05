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
        map<int, int> freq;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;

            freq[a]++;
        }

        ve<pii> pf;
        for (auto [x, y] : freq) {
            pf.push_back({y, x});
        }

        sort(all(pf));
        int sub = 0;
        for (int i = 0; i < sz(pf) - 1; i++) {
            if (pf[i].first <= k) {
                k -= pf[i].first;
                sub++;
            }
            else {
                break;
            }
        }

        cout << sz(pf) - sub << '\n';
    }
}

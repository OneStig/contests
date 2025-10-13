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

        set<int> seen;
        int kfreq = 0;

        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;

            if (a == k) {
                kfreq++;
            }
            else if (a < k) {
                seen.insert(a);
            }
        }

        cout << max(kfreq, k - sz(seen)) << '\n';
    }
}

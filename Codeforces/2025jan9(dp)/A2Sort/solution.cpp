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
        ve<int> a(n);
        for (int& x : a) cin >> x;

        int ans = 0;
        int count = 0;

        for (int i = n - 2; i >= 0; i--) {
            if (a[i] < 2 * a[i + 1]) {
                count++;
            }
            else {
                count = 0;
            }

            if (count >= k) {
                ans++;
            }
        }

        cout << ans << '\n';
    }
}

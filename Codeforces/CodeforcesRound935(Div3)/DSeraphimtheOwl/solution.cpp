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
        int n, m;
        cin >> n >> m;

        vector<int> a(n), b(n);
        for (int& x : a) cin >> x;
        for (int& x : b) cin >> x;

        vector<int> dpa(n + 1), dpb(n + 1);
        for (int i = n - 1; i >= 0; i--) {
            dpa[i] = a[i] + min(dpa[i + 1], dpb[i + 1]);
            dpb[i] = b[i] += min(dpa[i + 1], dpb[i + 1]);
        }

        int ans = 1e15;
        for (int i = 0; i < m; i++) {
            ans = min(ans, dpa[i]);
        }
        cout << ans << '\n';
    }
}

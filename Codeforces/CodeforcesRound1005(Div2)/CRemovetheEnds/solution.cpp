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

        ve<int> a(n), pfx(n), sfx(n);
        for (int& x : a) cin >> x;
        pfx.front() = max(a.front(), 0ll);
        sfx.back() = a.back() < 0 ? -a.back() : 0;

        for (int i = 1; i < n; i++) {
            pfx[i] =  pfx[i - 1] + (a[i] > 0 ? a[i] : 0);
        }

        for (int i = n - 2; i >= 0; i--) {
            sfx[i] = sfx[i + 1] + (a[i] < 0 ? -a[i] : 0);
        }

        int ans = max(sfx.front(), pfx.back());

        for (int i = 1; i < n; i++) {
            ans = max(ans, pfx[i - 1] + sfx[i]);
        }

        cout << ans << '\n';
    }
}

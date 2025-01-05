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

    int n;
    cin >> n;

    ve<int> a(n);
    for (int& x : a) cin >> x;
    ve<int> sorta = a;
    sort(all(sorta));

    int ans = (sorta[0] + 1) / 2 + (sorta[1] + 1) / 2;

    for (int i = 0; i < n - 2; i++) {
        int x = a[i], y = a[i + 2];
        ans = min(ans, min(x, y) + (max(x, y) - min(x, y) + 1) / 2);
    }

    for (int i = 1; i < n; i++) {
        int x = a[i - 1], y = a[i];
        if (y < x) swap(x, y);

        int k = 2 * x - y;
        if (k <= 0) {
            int cur = (y + 1) / 2;
            ans = min(ans, cur);
        }
        else {
            int cur = x - k;
            cur += (2 * k + 2) / 3;

            ans = min(ans, cur);
        }
    }

    cout << ans << '\n';
}


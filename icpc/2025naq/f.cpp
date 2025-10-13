#include <bits/stdc++.h>

using namespace std;

#define ONLINE_JUDGE

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

#define double long double

uci main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    ve<int> a(n);
    for (int& x : a) cin >> x;
    sort(all(a));

    double ksum = 0, x2 = 0;
    for (int i = 0; i < k; i++) {
        ksum += a[i];
        x2 += a[i] * a[i];
    }

    double u = ksum / (double)k;
    double ans = k * u * u - 2 * u * ksum + x2;

    for (int i = k; i < n; i++) {
        int nxt = a[i];
        int prev = a[i - k];
        x2 += nxt * nxt - prev * prev;
        ksum += nxt - prev;
    
        u = ksum / (double)k;
        double curans = k * u * u - u * 2 * ksum + x2;
        ans = min(ans, curans);
    }

    cout << fixed << setprecision(10) << ans << '\n';
}
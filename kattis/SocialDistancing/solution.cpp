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

uci main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    ve<pii> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    
        if (i != 0 && a[i].first < a[i - 1].first) {
            swap(a[i], a[i - 1]);
        }
    }

    int ans = 0;
    for (int i = 1; i < n; i++) {
        ans += a[i].second > a[i - 1].second ? a[i].first : a[i - 1].first;
    }
    cout << ans << '\n';
}

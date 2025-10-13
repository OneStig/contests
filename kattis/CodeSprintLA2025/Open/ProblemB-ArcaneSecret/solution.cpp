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

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int& x : a) {
        cin >> x;
    }

    sort(all(a));

    int gs = n / k;

    set<int> works;
    for (int i = 0; i < n; i++) {
        int below = (i - gs + 1) / gs;
        int above = n - i - 1;

        if (below >= k / 2 && above >= k / 2) {
            works.insert(a[i]);
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (works.count(a[i])) {
            ans++;
        }
    }

    cout << ans << '\n';
}

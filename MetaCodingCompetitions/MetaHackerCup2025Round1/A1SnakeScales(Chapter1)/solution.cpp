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

    int t;
    cin >> t;

    for (int cs = 1; cs <= t; cs++) {
        int n;
        cin >> n;

        ve<int> a(n);
        int ans = 0;
        for (int& x : a) cin >> x;
    
        for (int i = 1; i < n; i++) {
            ans = max(ans, abs(a[i] - a[i - 1]));
        }

        cout << "Case #" << cs << ": " << ans << '\n';
    }
}

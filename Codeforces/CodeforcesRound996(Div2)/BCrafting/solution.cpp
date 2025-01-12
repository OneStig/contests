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
        ve<int> a(n), b(n);
        for (int& x : a) cin >> x;
        for (int& x : b) cin >> x;

        ve<int> bad;
        for (int i = 0; i < n; i++) {
            if (a[i] < b[i]) {
                bad.push_back(i);
            }
        }

        if (sz(bad) > 1) {
            cout << "NO\n";
            continue;
        }
        else if (sz(bad) == 0) {
            cout << "YES\n";
            continue;
        }
        
        int dec = b[bad[0]] - a[bad[0]];

        bool yes = 1;
        for (int i = 0; i < n; i++) {
            if (i == bad[0]) continue;
            if (a[i] - dec < b[i]) {
                yes = 0;
                break;
            }
        }

        cout << (yes ? "YES" : "NO") << '\n';
    }
}

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

        ve<int> a(n);
        for (int& x : a) {
            cin >> x;
            x = abs(x);
        }

        bool yes = 0;
        if (n == 1) {
            yes = a[0] == 0;
        }
        else {
            map<int, ve<int>> sums;

            for (int i = 0; i < (1 << n); i++) {
                int cur = 0;
                for (int j = 0; j < n; j++) {
                    if (i & (1 << j)) {
                        cur += a[j];
                    }
                }

                for (int s : sums[cur]) {
                    if ((s | i) == (s ^ i)) {
                        yes = 1;
                        break;
                    }
                }

                sums[cur].push_back(i);

                if (yes) {
                    break;
                }
            }
        }

        cout << (yes ? "YES" : "NO") << '\n';
    }
}

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

const int INF = 1e9;

uci main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        ve<int> a(n);

        for (int& x : a) cin >> x;

        int mn = INF, k;
        int l = 0, r = INF;
        while (l <= r) {
            int mid = (l + r) / 2;

            bool good = 1;
            int klb = 0, kub = 1e9;

            for (int i = 1; i < n; i++) {
                int x = a[i - 1], y = a[i];
                if (x == -1 && y == -1) continue;

                if (x != -1 && y != -1) {
                    if (abs(x - y) > mid) {
                        good = 0;
                        break;
                    }
                }

                if (x == -1) {
                    klb = max(klb, y - mid);
                    kub = min(kub, y + mid);
                }
                else if (y == -1) {
                    klb = max(klb, x - mid);
                    kub = min(kub, x + mid);
                }
            }


            if (klb > kub) {
                good = 0;
            }

            if (good) {
                mn = mid;
                k = klb;

                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }

        cout << mn << ' ' << k << '\n';
    }
}

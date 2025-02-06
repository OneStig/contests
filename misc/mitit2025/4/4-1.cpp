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

#define X first
#define Y second

const int MOD = 1e9 + 7;

uci main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int ans = 0;

        ve<pii> ud, lr;

        for (int i = 0; i < n; i++) {
            int x, y;
            string ty;
            cin >> x >> y >> ty;

            if (ty == "UD") {
                ud.push_back({x, y});
            }
            else {
                lr.push_back({x, y});
            }
        }

        dbg(lr, ud);

        for (int mask = 0; mask < (1ll << n); mask++) {
            bool good = 1;
            for (int i = 0; i < sz(lr); i++) {
                for (int j = 0; j < sz(ud); j++) {
                    int lrd = (mask & (1 << i)) != 0;
                    int udd = (mask & (1 << (j + sz(lr)))) != 0;

                    if (udd && lr[i].Y > ud[j].Y && ((lr[i].X > ud[j].X && !lrd) || (lr[i].X < ud[j].X && lrd))) {
                        good = 0;
                        break;
                    }

                    dbg(udd, lr[i], ud[j], (lr[i].X > ud[j].X && !lrd), lr[i].Y < ud[j].Y);
                    if (!udd && lr[i].Y < ud[j].Y && ((lr[i].X > ud[j].X && !lrd) || (lr[i].X < ud[j].X && lrd))) {
                        good = 0;
                        break;
                    }
                }

                if (!good) break;
            }

            dbg(mask, good);
            ans += good;
        }

        if (ans == 0) {
            cout << "NO\n0\n";
        }
        else {
            cout << "YES\n" << ans << '\n';
        }
    }
}

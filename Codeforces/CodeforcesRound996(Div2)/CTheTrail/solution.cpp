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

const int MX = 1e9;

uci main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;

        ve<ve<int>> a(n, ve<int>(m)), b;
        for (auto& x : a) for (auto& y : x) cin >> y;
        ve<int> rs(n), cs(m);
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                rs[r] += a[r][c];
                cs[c] += a[r][c];
            }
        }
        

        // int ftarg = (s[0] == 'D' ? rs[0] : cs[0]);
        for (int k : {-MX, 0ll, MX}) {
            int targ = k;
            ve<int> rsum = rs, csum = cs;
            b = a;

            if (s[0] == 'D') {
                b[0][0] = targ - rsum[0];
            }
            else {
                b[0][0] = targ - csum[0];
            }

            rsum[0] += b[0][0];
            csum[0] += b[0][0];

            int r = 0, c = 0;
            for (int i = 0; i < sz(s); i++) {
                int targ = k;
                if (s[i] == 'D') {
                    // targ = rsum[r];
                    r++;
                }
                else {
                    // targ = csum[c];
                    c++;
                }

                if (i + 1 == sz(s) || s[i + 1] == 'D') {
                    b[r][c] = targ - rsum[r];
                }
                else {
                    b[r][c] = targ - csum[c];
                }

                rsum[r] += b[r][c];
                csum[c] += b[r][c];
            }

            if (csum.back() == csum.front() && rsum.back() == rsum.front() && rsum.front() == csum.front()) {
                break;
            }
        }

        for (auto& x : b) {
            for (auto& y : x) {
                cout << y << ' ';
            }
            cout << '\n';
        }

        dbg(a);
        dbg(b);
    }
}

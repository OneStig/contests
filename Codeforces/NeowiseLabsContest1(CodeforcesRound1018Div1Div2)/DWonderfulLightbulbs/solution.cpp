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

//
// x
// xx
//  x
// 
// y = -x + k

uci main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        map<int, int> xf;
        map<int, int> diag;

        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            xf[x]++;

            int curdiag = x + y;
            diag[curdiag]++;
        }

        int ax;
        for (auto [x, count] : xf) {
            if (count % 2 == 1) {
                ax = x;
                break;
            }
        }

        int ay;
        for (auto [k, count] : diag) {
            if (count % 2 == 1) {
                ay = -ax + k;
            }
        }

        cout << ax << ' ' << ay << '\n';
    }
}

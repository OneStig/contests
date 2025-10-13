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

#define L first
#define R second

uci main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        ve<int> d(n);
        ve<pii> o(n);
        for (int& x : d) cin >> x;
        for (pii& x : o) cin >> x.L >> x.R;

        bool good = 1;

        ve<int> option;

        int l = 0, r = 0;
        for (int i = 0; i < n; i++) {
            if (d[i] == -1) {
                d[i] = 0;
                r++;
                option.push_back(i);
            }
            else {
                l += d[i];
                r += d[i];
            }

            r = min(r, o[i].R);
            if (l < o[i].L) {
                if (o[i].L > r) {
                    good = 0;
                    break;
                }

                int need = o[i].L - l;
                while (need--) {
                    d[option.back()] = 1;
                    option.pop_back();
                }

                l = o[i].L;
            }

            if (l > r) {
                good = 0;
                break;
            }
        }


        if (good) {
            for (int& x : d)
                cout << x << ' ';
            cout << '\n';
        }
        else {
            cout << -1 << '\n';
        }
    }
}

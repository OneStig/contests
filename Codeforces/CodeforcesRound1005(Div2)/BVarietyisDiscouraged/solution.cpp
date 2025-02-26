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
        map<int, int> freq;

        for (int& x : a) {
            cin >> x;
            freq[x]++;
        }

        int ansl = 0, ansr = -1;
        int l = 0;

        for (int r = 0; r < n; r++) {
            if (freq[a[r]] != 1) {
                l = r + 1;
                continue;
            }

            if (r - l > ansr - ansl) {
                ansr = r;
                ansl = l;
            }
        }

        if (ansr == -1) {
            cout << 0 << '\n';
        }
        else {
            cout << ansl + 1 << ' ' << ansr + 1 << '\n';
        }
    }
}

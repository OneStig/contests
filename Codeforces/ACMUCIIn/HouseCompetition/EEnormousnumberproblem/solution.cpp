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

const int MAX_SQRTN = 1e4;

uci main() {
    cin.tie(0)->sync_with_stdio(0);

    vector<bool> isp(MAX_SQRTN + 1, true);
    ve<int> ps;
    isp[0] = isp[1] = false;
    for (int i = 2; i <= MAX_SQRTN; i++) {
        if (isp[i]) {
            ps.push_back(i);
            if (i * i <= MAX_SQRTN) {
                for (int j = i * i; j <= MAX_SQRTN; j += i) {
                    isp[j] = false;
                }
            }
        }
    }

    int q;
    cin >> q;

    while (q--) {
        int nn, mm;
        cin >> nn >> mm;
        int n = nn, m = mm;

        set<int> used;
        for (int p : ps) {
            if (n % p == 0 || m % p == 0) {
                used.insert(p);
            }

            while (n % p == 0) {
                n /= p;
            }

            while (m % p == 0) {
                m /= p;
            }
        }

        used.insert(n);
        used.insert(m);
        used.erase(1);

        int ans = nn * mm;

        for (int p : used) {
            ans = ans / p * (p - 1);
        }

        cout << ans << '\n';
    }
}


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

#define F first
#define S second

const int INF = 1e15;

bool comp(pii a, pii b) {
    if ((a.S - a.F > 0) == (b.S - b.F > 0)) {
        if (a.S - a.F <= 0) {
            return a.S > b.S;
        }
 
        return a.F < b.F;
    }
 
    return (a.S - a.F) > (b.S - b.F);
}

uci main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int asum = 0, bsum = 0;
        ve<pii> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i].F >> a[i].S;
            asum += a[i].F;
            bsum += a[i].S;
        }

        int cand = -1;
        for (int i = 0; i < n; i++) {
            if (bsum - a[i].second >= asum) {
                if (cand == -1 || comp(a[cand], a[i])) {
                    cand = i;
                }
            }
        }

        if (cand == -1) {
            cout << "-1\n";
            continue;
        }

        pii tmp = a[cand];
        a.erase(a.begin() + cand);
        sort(all(a), comp);
        a.push_back(tmp);

        int ans = 0;

        int free = 0;
        for (int i = 0; i < n; i++) {
            ans += a[i].F;
            int mv = min(free, a[i].F);
            free -= mv;
            a[i].F -= mv;
            a[n - 1].F += a[i].F;
            free += a[i].S;

        }

        cout << ans << '\n';
    }
}

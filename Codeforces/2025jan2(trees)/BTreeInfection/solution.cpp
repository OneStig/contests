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

        ve<int> deg(n + 1);

        for (int i = 2; i <= n; i++) {
            int p;
            cin >> p;
            deg[p]++;
        }

        ve<int> gps = {1};
        for (int& x : deg) {
            if (x != 0) {
                gps.push_back(x);
            }
        }

        sort(gps.rbegin(), gps.rend());

        priority_queue<int> rem;
        int offset = 0;

        int k = sz(gps);
        for (int i = 0; i < sz(gps); i++) {
            int left = gps[i] - (sz(gps) - i);
            if (left > 0) rem.push(left);
        }

        while (sz(rem) && rem.top() > offset) {
            rem.push(rem.top() - 1);
            rem.pop();
            offset++;
            k++;
        }

        cout << k << '\n';
    }
}

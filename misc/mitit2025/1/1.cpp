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

uci main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;

    if (n <= 9) {
        cout << n << '\n';
        return 0;
    }

    ve<int> dig(9);
    iota(all(dig), 1);
    set<int> seen;
    queue<int> q;

    for (int& x : dig) {
        seen.insert(x);
        q.push(x);
    }

    while (sz(q)) {
        int cur = q.front();
        q.pop();

        for (int f = 2; f <= 9; f++) {
            int cand = cur * f;
            if (cand > n || seen.count(cand)) continue;

            int tmp = cand;
            bool found = 0;
            while (tmp != 0) {
                if (tmp % 10 == f) {
                    found = 1;
                    break;
                }

                tmp /= 10;
            }

            if (found) {
                seen.insert(cand);
                q.push(cand);
            }
        }
    }

    int ans = sz(seen);

    cout << ans << '\n';
}

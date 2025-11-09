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

    int m;
    cin >> m;

    map<int, int> freq;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        freq[x + 1]++;
    }

    int ans = 1;
    for (auto [num, occ] : freq) {
        int base = (num + 2) / 2;
        if (num % 2 == 0) {
            occ -= 2;
        }
        else {
            occ--;
        }

        int mn = base + max(0ll, (occ + 1) / 2);
        ans = max(ans, mn);
    }

    cout << ans << '\n';
}
// diagnoals = 2n - 1
// 1 = 2n
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
        int n, p;
        cin >> n >> p;

        

        ve<int> a(n);
        ve<pii> todo;
        for (int i = 0; i < n; i++) {
            cin >> a[i];

            if (a[i] < p) {
                todo.push_back({a[i], i});
            }
        }

        sort(all(todo));

        int comps = n;
        int ans = 0;

        ve<bool> join(n);
        for (auto [mn, ind] : todo) {
            for (int l = ind - 1; l >= 0 && !join[l]; l--) {
                if (a[l] < a[ind] || a[l] % a[ind] != 0) break;
                join[l] = 1;
                ans += a[ind];
                comps--;
            }

            for (int r = ind + 1; r < n && !join[r - 1]; r++) {
                if (a[r] < a[ind] || a[r] % a[ind] != 0) break;
                join[r - 1] = 1;
                ans += a[ind];
                comps--;
            }
        }

        ans += (comps - 1) * p;
        cout << ans << '\n';
    }
}

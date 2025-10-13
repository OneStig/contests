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

const int MAX_B = 2e14 + 1;

uci main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        ve<int> b(n + 1);
        for (int i = 1; i <= n; i++) cin >> b[i];

        ve<ve<pii>> adj(n + 1);
        for (int i = 0; i < m; i++) {
            int s, t, w;
            cin >> s >> t >> w;
            adj[s].push_back({t, w});
        }

        int l = 1, r = MAX_B;
        while (l < r) {
            int mid = (l + r) / 2;

            ve<int> best(n + 1, -1);
            best[1] = min(mid, b[1]);
            for (int i = 1; i < n; i++) {
                for (auto [nxt, cost] : adj[i]) {
                    if (best[i] >= cost) {
                        best[nxt] = max(best[nxt], min(mid, best[i] + b[nxt]));
                    }
                }

            }

            if (best[n] == -1) {
                l = mid + 1;
            }
            else {
                r = mid;
            }

        }

        cout << (l >= MAX_B ? -1 : l) << '\n';
    }
}

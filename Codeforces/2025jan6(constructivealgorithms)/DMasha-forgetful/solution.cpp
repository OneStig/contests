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
        int n, m;
        cin >> n >> m;

        string s;
        map<string, array<int, 3>> intv;
        for (int i = 1; i <= n; i++) {
            string cur;
            cin >> cur;

            for (int j = 0; j < m - 1; j++) {
                string a = cur.substr(j, 2);
                intv[a] = {j + 1, j + 2, i};

                if (j + 2 < m) {
                    string b = cur.substr(j, 3);
                    intv[b] = {j + 1, j + 3, i};
                }
            }
        }

        cin >> s;

        ve<int> dp(m, -2);
        ve<array<int, 3>> dpa(m);

        for (int i = 1; i < m; i++) {
            string p2 = s.substr(i - 1, 2);

            if (intv.count(p2) && (i == 1 || dp[i - 2] != -2)) {
                dp[i] = i - 2;
                dpa[i] = intv[p2];
                continue;
            }

            if (i > 1) {
                string p3 = s.substr(i - 2, 3);

                if (intv.count(p3) && (i == 2 || dp[i - 3] != -2)) {
                    dp[i] = i - 3;
                    dpa[i] = intv[p3];
                }
            }
        }

        if (dp[m - 1] == -2) {
            cout << -1 << '\n';
        }
        else {
            ve<array<int, 3>> ans;
            int cur = m - 1;
            while (cur != -1) {
                ans.push_back(dpa[cur]);
                cur = dp[cur];
            }

            reverse(all(ans));
            cout << sz(ans) << '\n';
            for (auto [x, y, z] : ans) {
                cout << x << ' ' << y << ' ' << z << '\n';
            }
        }
    }
}

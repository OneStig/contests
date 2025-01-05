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

        int sum = 0;
        ve<int> rsum(n);
        ve<ve<int>> a(n, ve<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
                rsum[i] += a[i][j];
            }
            sum += rsum[i];
        }


        if (sum % n != 0) {
            cout << "-1\n";
            continue;
        }

        ve<tuple<int, int, int>> ans;

        int targ = sum / n;

        ve<ve<int>> ones(m), zeros(m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (rsum[i] == targ) break;

                if (rsum[i] < targ && a[i][j] == 0) {
                    while (sz(ones[j]) && rsum[ones[j].back()] == targ) {
                        ones[j].pop_back();
                    }

                    if (sz(ones[j])) {
                        rsum[i]++;
                        rsum[ones[j].back()]--;
                        ans.push_back({ones[j].back(), i, j});
                        ones[j].pop_back();
                    }
                    else {
                        zeros[j].push_back(i);
                    }
                }

                if (rsum[i] > targ && a[i][j] == 1) {
                    while (sz(zeros[j]) && rsum[zeros[j].back()] == targ) {
                        zeros[j].pop_back();
                    }

                    if (sz(zeros[j])) {
                        rsum[i]--;
                        rsum[zeros[j].back()]++;
                        ans.push_back({zeros[j].back(), i, j});
                        zeros[j].pop_back();
                    }
                    else {
                        ones[j].push_back(i);
                    }
                }
            }
        }

        cout << sz(ans) << '\n';
        for (auto& [x, y, z] : ans) {
            cout << x + 1 << ' ' << y + 1 << ' ' << z + 1 << '\n';
        }
    }
}

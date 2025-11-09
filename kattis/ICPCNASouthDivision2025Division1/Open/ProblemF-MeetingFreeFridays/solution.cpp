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

const int INF = 1e9;

int bsearch(int time, ve<pii>& meetings) {
    // finds last index <= time
    int l = 0, r = sz(meetings) - 1;
    while (l < r) {
        int mid = (l + r + 1) / 2;
    
        if (meetings[mid].first <= time) {
            l = mid;
        }
        else {
            r = mid - 1;
        }
    }

    return l;
}

uci main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, t, k;
    cin >> n >> t >> k;

    ve<pii> meetings(n + 1);
    for (int i = 1; i <= n; i++) {
        auto& x = meetings[i];
        cin >> x.second >> x.first;
    }

    sort(all(meetings));
    ve<ve<int>> dp(n + 1, ve<int>(n + 1, -INF));
    ve<ve<int>> best(n + 1, ve<int>(n + 1, -INF));
    dp[0][0] = 0;
    best[0][0] = 0;

    for (int i = 1; i <= n; i++) {
        dp[i][0] = meetings[i].first;

        for (int j = 1; j <= i; j++) {
            // dont attend cur meeting;
            dp[i][j] = dp[i - 1][j] + meetings[i].first - meetings[i - 1].first;
        
            // attend cur meeting, find best j - 1
            // that occurs before meetings[i].second
            dbg(i, j, meetings[i].second, bsearch(meetings[i].second, meetings));
            int opt2 = best[bsearch(meetings[i].second, meetings)][j - 1] + meetings[i].second;
            dbg(opt2);

            dp[i][j] = max(dp[i][j], opt2);
        }

        for (int j = 0; j <= i; j++) {
            best[i][j] = max(best[i - 1][j], dp[i][j] - meetings[i].first);
            dbg(i, j, best[i][j], dp[i][j]);
        }
    }

    int ans = 0;
    for (int i = 0; i <= n; i++) {
        if (dp[n][i] + t - meetings[n].first >= k) {
            ans = i;
        }
    }

    cout << ans << '\n';
}

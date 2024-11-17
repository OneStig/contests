#include <bits/stdc++.h>

using namespace std;

typedef int uci;
#define int long long
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

bool can_make(string s, string t) {
    if(s[0] == '?' && s[1] == '?') {
        return true;
    }

    if(s[0] == '?' && s[1] == t[1]) {
        return true;
    }

    if(s[0] == t[0] && s[1] == '?') {
        return true;
    }

    if(s[0] == t[0] && s[1] == t[1]) {
        return true;
    }

    return false;
}

void solve() {
    int n, r;
    cin >> n >> r;

    vector<string> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<vector<int>> dp(n+1,vector<int>(100,0));
    for (int i = n; i >=0; i--) {
        for (int x = 0; x < r+1; x++) {
            if (i == n) {
                dp[i][x] = 1;
                continue;
            }
            for (int p = x+1; p < r+1; p++) {
                string pp = to_string(p);
                if (pp.size() == 1) {
                    pp = '0' + pp;
                }
                if (can_make(a[i],pp)) {
                    dp[i][x] += dp[i+1][p];
                }
            }
            //cout << i << " " << x << " " << dp[i][x] << "\n";
        }
    }
    cout << dp[0][0] << "\n";
    /*
    vector<int> dp(100, 0);
    for(int i = 0; i < n; ++i) {
        vector<int> ndp(100, 0);
        for(int j = 1; j < r+1; ++j) {
            string p = to_string(j);
            if(sz(p) == 1) {
                p = '0' + p;
            }

            if(can_make(a[i], p)) {
                for(int t = 0; t < j; ++t) {
                    ndp[j] += dp[t];
                }
            }
        }

        swap(ndp, dp);
    }

    int sum = 0;
    for(int i = 0; i < 100; ++i) {
        sum += dp[i];
    }

    cout << sum << "\n";*/
}
uci main() {
    cin.tie(0)->sync_with_stdio();
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}
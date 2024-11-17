#include <bits/stdc++.h>

using namespace std;

typedef int uci;
#define int long long
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()


uci main() {
    cin.tie(0)->sync_with_stdio();
    int n,m;
    cin >> n >> m;
    set<int> a;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        a.insert(x);
    }

    vector<pair<int,int>> qs;
    for (int i = 0; i < m; i++) {
        char c;
        int r;
        cin >> c >> r;
        if (c == 'Q') {
            qs.push_back({1,r});
        }
        else {
            qs.push_back({2,r});
            a.erase(r);
        }
    }

    reverse(all(qs));

    int maxi = 1e5 + 1;
    vector<int> dp(maxi, -1);
    dp[0] = 0;
    for(auto x : a) {
        dp[x]  = 1;
    }

    for(int i = 0; i < maxi; ++i) {
        for(auto x : a) {
            if(dp[i] >= 0 && i + x < maxi) {
                if (dp[i+x] == -1) {
                    dp[i+x] = dp[i] + 1;
                }
                dp[i + x] = min(dp[i + x], dp[i] + 1);
            }
        }
    }

    vector<int> ans;

    for(int j = 0; j < m; ++j) {
        if(qs[j].first == 1) {
            ans.push_back(dp[qs[j].second]);
        }

        else {
            int x = qs[j].second;
            for(int i = 0; i < maxi; ++i) {
                if(dp[i] >= 0 && i + x < maxi) {
                    if (dp[i+x] == -1) {
                        dp[i+x] = dp[i] + 1;
                    }
                    dp[i + x] = min(dp[i + x], dp[i] + 1);
                }
            }
        }
    }
    reverse(all(ans));
    for (auto i : ans) {
        cout <<i << "\n";
    }
}
#include <bits/stdc++.h>

using namespace std;

typedef int uci;
#define int long long
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

int mod = 1e9+7;

int f(vector<int>&a) {
    int ans = 0;
    int sum = 0;
    for (int i =0; i < a.size(); i++) {
        ans += (a[i] * a[i]) * (a.size() - 1);
        ans = ans % mod;
        sum += a[i];
        sum %= mod;
    }
    for (int i = 0; i < sz(a); i++) {
        ans -= (a[i] * sum)%mod;
        ans += a[i] * a[i];
        ans = ans % mod;
    }
    ans += mod;
    ans = ans % mod;
    return ans;
}

uci main() {
    cin.tie(0)->sync_with_stdio();
    string s;
    cin >> s;
    int n = s.size();
    vector<int> a;
    for (int i = 0; i < n; i++) {
        a.push_back(s[i] - 'A');
    }
    //for (auto i : a) {
    //    cout << i << " ";
    //}
    //cout << "\n";
    int ans = 0;
    vector<vector<int>> as(27);
    for (int i = 0; i < n; i++) {

        as[a[i]].push_back(i);
        as[26].push_back(i);
    }
    for (int i = 0; i < 27;i++) {
        //cout << i << " ";
        //for (auto j : as[i]) {
        //    cout << j <<" ";
        //}
        //cout << "\n";
        if (i == 26) {
            ans += f(as[i]);
        }
        else {
            ans -= f(as[i]);
        }
        ans = ans % mod;
        //cout << ans <<"\n";
    }

    cout << (ans + mod)%mod << "\n";
}
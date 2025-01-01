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

void solve() {
    int n, k;
    string s;
    cin >> n >> k >> k >> s;

    ve<int> z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if (i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }

    z[0] = n;

    l = 0;
    r = n / k;

    while (l != r) {
        int m = (l + r + 1) / 2;
        int count = 0;

        int ind = 0;
        while (ind < n && count < k) {
            if (z[ind] >= m) {
                count++;
                ind += m;
            }
            else {
                ind++;
            }
        }

        if (count >= k) {
            l = m;
        }
        else {
            r = m - 1;
        }
    }
    
    cout << l << "\n";
}

uci main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}

#include <bits/stdc++.h>

using namespace std;

typedef int uci;
#define int long long
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

uci main() {
    cin.tie(0)->sync_with_stdio();
    int n;
    cin >> n;
    vector<int> a;
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        a.push_back(k);
    }
    sort(all(a));
    if (a[0] == 1) {
        cout << 1 << "\n";
        return 0;
    }
    if (a[0] == n) {
        cout << 1 << "\n";
        return 0;
    }
    int ans = 1;
    int ival = a[0];
    for (int i = m-1; i > 0; i--) {
        //cout << ival << " " << ans << "\n";
        if (ival <= 2) {
            continue;
        }
        if (a[i] == n) {
            continue;
        }
        if (a[i] < n - ival + 2) {
            continue;
        }
        ans += 1;
        ival = a[i] - (n - ival) - 1;
    }
    cout << ans << "\n";
}
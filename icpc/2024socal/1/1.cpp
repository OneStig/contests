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
    vector<int> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    set<int> st;
    for(int i = 0; i < n; ++i) {
        for(int j = i + 1; j < n; ++j) {
            st.insert(a[i] + a[j]);
        }
    }

    cout << n * (n - 1) / 2 << " " << sz(st) << "\n";
}
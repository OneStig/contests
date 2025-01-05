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
        int n, k;
        cin >> n >> k;

        ve<int> a(n);
        for (int& x : a) cin >> x;

        int pos = 1;
        int ind = 0;
        for (int i = 0; i < k; i++) {
            while (ind < n && a[ind] <= pos + ind) {
                ind++;
            }
            pos += ind;
        }

        cout << pos << '\n';
    }
}

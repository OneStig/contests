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
        int n, k, l;
        cin >> n >> k >> l;

        ve<int> a(n);
        for (int& x : a) {
            cin >> x;
            x *= 2;
        }
        k *= 2;
        l *= 2;

        int pos = k;
        int time = a[0];
        for (int i = 1; i < n; i++) {
            if (a[i] - time <= pos) {
                pos = min(pos, a[i] + time) + k;
                if (pos >= l) break;
            }
            else {
                int mid = min((pos + (a[i] - time)) / 2, l);
                time += mid - pos;
                pos = mid + k;
                if (pos >= l) break;
            }
        }

        if (pos < l) {
            time += l - pos;
        }

        cout << time << '\n';
    }
}

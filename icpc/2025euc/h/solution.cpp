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

    int n, a, b;
    cin >> n >> a >> b;

    ve<int> d(n - 1);
    int sum = 0;

    for (int& x : d) {
        cin >> x;
        sum += x;
    }

    if (sum % 2 != (a + b) % 2) {
        cout << "NO\n";
    }

    for (int& x : d) {
        if (x > sum - x) {
            cout << "NO\n";
            return 0;
        }
    }

    ve<pii> ans;

    while (sz(d)) {
    }
}

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

uci main() {
    cin.tie(0)->sync_with_stdio(0);

    int k;
    cin >> k;
    string a, b;
    cin >> a >> b;

    int same = 0;
    for (int i = 0; i < sz(a); i++) {
        same += a[i] == b[i];
    }

    int ans = min(same, k) + min(sz(a) - same, sz(a) - k);
    cout << ans << '\n';
}

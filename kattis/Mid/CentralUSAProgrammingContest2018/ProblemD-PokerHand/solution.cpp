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
    map<char, int> b;
    for (int i = 0; i < 5; i++) {
        string a;
        cin >> a;
        b[a[0]]++;
    }

    int ans = 1;
    for (auto [_, f] : b) {
        ans = max(ans, f);
    }

    cout << ans << '\n';
}

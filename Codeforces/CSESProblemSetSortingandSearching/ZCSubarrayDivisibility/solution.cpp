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

    int n;
    cin >> n;
    ve<int> a(n);

    for (int& x : a) cin >> x;

    ve<int> cnt(n);
    cnt[0]++;

    int pfx = 0, ans = 0;
    for (int& x : a) {
        pfx += x;

        int mod = pfx %  n;
        if (mod < 0) mod += n;
        ans += cnt[mod];
        cnt[mod]++;
    }

    cout << ans << '\n';
}

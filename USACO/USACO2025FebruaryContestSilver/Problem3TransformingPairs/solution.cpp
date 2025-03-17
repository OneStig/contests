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

int solve(int a, int b, int c, int d) {
    if (d < b || c < a) return -1;
    if (b == d) {
        swap(a, b);
        swap(c, d);
    }

    if (a == c) {
        int diff = d - b;
        if (diff % a == 0) {
            return diff / a;
        }

        return -1;
    }

    if (c > d) {
        swap(a, b);
        swap(c, d);
    }

    int mxdiff = d - c;
    int moves = max((mxdiff + c - 1) / c, 1ll);

    int res = solve(a, b, c, d - moves * c);
    if (res == -1) return -1;
    return moves + res;
}

uci main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << solve(a, b, c, d) << '\n';
    }
}

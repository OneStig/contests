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

#define X first
#define Y second

int DX[] = {-1, 1, -1, 1}, DY[] = {-1, -1, 1, 1};

// walls are top, right, bottom, left

pii wall(pii pos, pii delta) {
    return {0, 0};
}


uci main() {
    cin.tie(0)->sync_with_stdio(0);

    int w, h, cx, cy, n;
    while (1) {
        cin >> w >> h >> cx >> cy >> n;
        if (w == 0) break;

        ve<pii> balls(n);
        for (auto& b : balls) {
            cin >> b.X >> b.Y;
        }

    }
}

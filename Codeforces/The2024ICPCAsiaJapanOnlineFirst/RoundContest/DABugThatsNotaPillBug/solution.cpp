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
    while (cin >> n) {
        if (n == 0) break;

        int a, b, d;
        cin >> a >> b >> d;
        int dx = 1, dy = 0;

        set<pii> lst;
        for (int i = 0; i < n; i++) {
            int u, v;
            cin >> u >> v;
            lst.insert({u, v});
        }

        map<int, pair<pii, pii>> dist;
        map<pair<pii, pii>, int> DIST;

        int cd = 0;
        while (cd <= d) {
            pair<pii, pii> state = {{a, b}, {dx, dy}};
            if (DIST.count(state)) {
                int rep = cd - DIST[state];
                if (rep == 0) {
                    dx = 0;
                    dy = 0;
                    break;
                }
                if (d > 2 * cd) {
                    d = (d - 2 * cd) % rep + 2 * cd;
                }
            }

            dist[cd] = state;
            DIST[state] = cd;

            if (a < 0 || b < 0 || a > 100 || b > 100) {
                break;
            }

            int A = a + dx;
            int B = b + dy;

            if (lst.count({A, B})) {
                int DX = dx;
                int DY = dy;
                dy = DX;
                dx = -DY;
                continue;
            }

            state = {{A, B}, {dx, dy}};

            cd++;
            a = A;
            b = B;
        }

        if (cd < d) {
            a = a + dx * (d - cd);
            b = b + dy * (d - cd);
            cout << a << ' ' << b << '\n';
        }
        else {
            cout << dist[d].first.first << ' ' << dist[d].first.second << '\n';
        }
    }
}

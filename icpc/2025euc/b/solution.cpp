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

int getr(pii x) {
    int a = x.first;
    int b = x.second;
    return a * (a - 1) * b * (b - 1) / 4;
}

uci main() {
    cin.tie(0)->sync_with_stdio(0);

    int k;
    cin >> k;

    if (k == 0) {
        cout << "1 1\n.\n";
        return 0;
    }

    int origk = k;

    ve<pii> ans, vans;

    for (int width = 2025; width >= 2024; width--) {
        // int avail = width + max(0ll, 2024 - width);
        k = origk;

        ve<pii> rect, vert;

        // int rwidth = 2025 / width;

        int cap = 2025;
        int vcap = max(0ll, 2024 - width);

        int sum = -1;
        int vsum = -1;

        while (k != 0) {
            pii cur = {2, 2};

            while (1) {
                pii next = cur;
                if (next.first < width) {
                    next.first++;
                }
                else {
                    next.second++;
                }

                // dbg(cur, getr(cur));

                if (getr(next) > k) {
                    k -= getr(cur);
                    if (sum + cur.second + 1 > cap) {
                        vsum += cur.second + 1;
                        vert.push_back(cur);
                    }
                    else {
                        sum += cur.second + 1;
                        rect.push_back(cur);
                    }
                    break;
                }

                cur = next;
            }
        }

        // dbg(width, rect);

        if (sum <= cap && vsum <= vcap) {
            ans = rect;
            vans = vert;
            break;
        }
    }

    // dbg(ans);

    // if (sz(ans) == 0 && sz(vans) == 0) {
    //    while (1);
    //}

    ve<string> toprint;

    for (auto cur : ans) {
        if (sz(toprint) != 0) {
            toprint.emplace_back(string(2025, '.'));
        }
        for (int row = 0; row < cur.second; row++) {
            string grid(cur.first, '#');
            string blank(2025 - cur.first, '.');
            toprint.push_back(grid + blank);
        }
    }

    // dbg(ans, vans);

    int empty = 2025 - sz(toprint);
    for (int i = 0; i < empty; i++) {
        toprint.emplace_back(string(2025, '.'));
    }

    int col = 2024;
    for (auto cur : vans) {
        while (cur.first) {
            for (int row = 0; row < cur.second; row++) {
                toprint[row][col] = '#';
            }
            col--;
        }
        col--;
    }
    
    cout << sz(toprint) << " 2025\n";
    for (string& s : toprint) {
        cout << s << '\n';
    }


    // dbg(ans);
}

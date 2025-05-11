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

const int INF = 1e9;

uci main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, k;
    string s;
    cin >> n >> k >> s;

    // precompute cutoffs

    ve<ve<int>> occ(n + 1, ve<int>(k, n));
    ve<int> toend(n + 1, 0); // num of chars to add to end

    for (int i = n - 1; i >= 0; i--) {
        int c = s[i] - 'a';

        occ[i] = occ[i + 1];
        occ[i][c] = i;

        int cbest = INF;
        for (int nc = 0; nc < k; nc++) {
            cbest = min(cbest, 1 + toend[occ[i + 1][nc]]);
        }
        toend[i] = cbest;
    }

    dbg(toend);


    int q;
    cin >> q;

    while (q--) {
        string qs;
        cin >> qs;

        int end = -1;
        for (char c : qs) {
            if (end == n) break;

            int ic = c - 'a';
            end = occ[end + 1][ic];
        }

        cout << toend[end] << '\n';
    }
}


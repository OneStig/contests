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
        string s;
        cin >> s;
        int n = sz(s);

        for (int i = 0; i < n; i++) {
            int best = i;
            int bestval = 0;
            for (int j = 0; j + i < min(i + 9, n); j++) {
                if (s[j + i] - j > bestval) {
                    bestval = s[i + j] - j;
                    best = i + j;
                }
            }

            while (best != i) {
                swap(s[best], s[best - 1]);
                best--;
            }

            s[i] = bestval;
        }

        cout << s << '\n';
    }
}

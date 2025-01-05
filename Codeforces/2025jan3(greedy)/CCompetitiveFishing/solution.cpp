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
        int n, k;
        string s;
        cin >> n >> k >> s;

        int diff = 0;

        ve<int> inc;
        int run = 0;
        for (int i = n - 1; i > 0; i--) {
            run += (s[i] == '1' ? 1 : -1);
            if (run > 0) {
                inc.push_back(run);
            }
        }

        sort(all(inc));

        int count = 1;
        while (diff < k && sz(inc)) {
            diff += inc.back();
            inc.pop_back();
            count++;
        }

        cout << (diff >= k ? count : -1)  << '\n';
    }
}

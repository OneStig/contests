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
        int n, m;
        cin >> n >> m;

        int tot = 0;
        ve<int> reduc;
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;

            tot += sz(s);
            reverse(all(s));
            int revlen = log10(stoi(s)) + 1;
            if (sz(s) - revlen != 0) {
                reduc.push_back(sz(s) - revlen);
            }
        }

        sort(reduc.rbegin(), reduc.rend());
        for (int i = 0; i < sz(reduc); i += 2) {
            tot -= reduc[i];
        }

        cout << (tot > m ? "Sasha" : "Anna") << '\n';
    }
}

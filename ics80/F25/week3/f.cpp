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
        int n, q;
        string s;
        cin >> n >> q >> s;

        unordered_map<string, multiset<int>> queries;

        for (int i = 0; i < q; i++) {
            string x, y;
            cin >> x >> y;

            queries[x + y].insert(i);
        }

        for (char& c : s) {
            if (c == 'a') continue;
            if (c == 'b') {
                if (sz(queries["ba"])) {
                    c = 'a';
                    queries["ba"].erase(queries["ba"].begin());
                }
                else if (sz(queries["bc"]) && sz(queries["ca"])) {
                    auto bc = queries["bc"].begin();
                    auto ca = queries["ca"].upper_bound(*bc);

                    if (ca != queries["ca"].end()) {
                        c = 'a';
                        queries["bc"].erase(bc);
                        queries["ca"].erase(ca);
                    }
                }
            }
            else if (c == 'c') {
                if (sz(queries["ca"])) {
                    c = 'a';
                    queries["ca"].erase(queries["ca"].begin());
                }
                else if (sz(queries["cb"])) {
                    c = 'b';
                    auto cb = queries["cb"].begin();

                    if (sz(queries["ba"])) {
                        auto ba = queries["ba"].upper_bound(*cb);

                        if (ba != queries["ba"].end()) {
                            queries["ba"].erase(ba);
                            c = 'a';
                        }
                    }

                    queries["cb"].erase(cb);
                }

            }

        }

        cout << s << '\n';
    }
}

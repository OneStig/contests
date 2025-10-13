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

void solve() {
    int n, q;
    string s;
    cin >> n >> q >> s;

    map<string, multiset<int>> avail;

    for (int i = 0; i < q; i++) {
        string from, to;
        cin >> from >> to;

        avail[from + to].insert(i);
    }

    for (char& c : s) {
        if (c == 'a') continue;
        if (c == 'b') {
            // b -> a
            // b -> c, c -> a
            // we will never regret taking b -> a
            // if c needs it, then we need c -> a to swap

            if (sz(avail["ba"])) {
                c = 'a';
                avail["ba"].erase(avail["ba"].begin());
            }
            else if (sz(avail["bc"]) && sz(avail["ca"])) {
                auto first = avail["bc"].begin();
                auto second = avail["ca"].upper_bound(*first);

                if (second != avail["ca"].end()) {
                    c = 'a';
                    avail["bc"].erase(first);
                    avail["ca"].erase(second);
                }
            }
        }
        else if (c == 'c') {
            // c -> a
            // c -> b -> a
            // or just c -> b

            if (sz(avail["ca"])) {
                c = 'a';
                avail["ca"].erase(avail["ca"].begin());
            }
            else if (sz(avail["cb"])) {
                // at least take c -> b
                c = 'b';
                auto first = avail["cb"].begin();

                // then try b -> a

                if (sz(avail["ba"])) {
                    auto second = avail["ba"].upper_bound(*first);

                    if (second != avail["ba"].end()) {
                        avail["ba"].erase(second);
                        c = 'a';
                    }
                }

                avail["cb"].erase(first);
            }

        }

    }

    cout << s << '\n';
}

uci main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}

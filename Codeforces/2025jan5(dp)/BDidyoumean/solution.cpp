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

    set<char> vow = {'a', 'e', 'i', 'o', 'u'};

    string s;
    cin >> s;

    int row = 0;
    set<char> inrow;
    for (char c : s) {
        if (vow.count(c)) {
            row = 0;
            inrow = set<char>();
        }
        else {
            row++;
            inrow.insert(c);
        }

        if (row >= 3 && sz(inrow) > 1) {
            cout << ' ';
            row = 1;
            inrow = {c};
        }

        cout << c;
    }
    cout << '\n';
}

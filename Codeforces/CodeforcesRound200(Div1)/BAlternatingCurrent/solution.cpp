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

    string s;
    cin >> s;

    stack<char> stk;
    for (char c : s) {
        if (sz(stk) == 0 || stk.top() != c) {
            stk.push(c);
        }
        else {
            stk.pop();
        }
    }

    cout << (sz(stk) ? "No" : "Yes") << '\n';
}

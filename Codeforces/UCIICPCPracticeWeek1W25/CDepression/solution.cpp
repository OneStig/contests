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

    int h = stoi(s.substr(0, 2)), m = stoi(s.substr(3, 2));

    ld x = (h % 12) / 12.0 * 360.0 + (1.0 / 12.0 * 360.0 * (m % 60) / 60.0);
    ld y = (m % 60) / 60.0 * 360.0;
    cout << fixed << setprecision(12) << x << ' ' << y << '\n';
}

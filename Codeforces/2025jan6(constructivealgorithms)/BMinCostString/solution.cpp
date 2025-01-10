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

    int n, k;
    cin >> n >> k;

    map<char, int> nxt;

    for (int i = 0; i < k; i++) {
        char p = 'a' + i;
        nxt[p] = i;
    }

    int cur = 0;
    for (int i = 0; i < n; i++) {
        char p = 'a' + cur;
        cout << p;
        cur = nxt[p];
        nxt[p] = (nxt[p] + 1) % k;
    }

    cout << '\n';
}

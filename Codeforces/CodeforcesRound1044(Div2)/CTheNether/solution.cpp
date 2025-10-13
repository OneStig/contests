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

int ask(int x, ve<int>& s) {
    cout << "? " << x << " " << sz(s);
    for (int& a : s) cout << " " << a;
    cout << endl;
    int res;
    cin >> res;
    return res;
}

int askone(int x, int y) {
    cout << "? " << x << " 2 " << x << " " << y << endl;
    int res;
    cin >> res;
    return res;
}

void solve() {
    int n;
    cin >> n;

    map<int, ve<int>> mx;
    ve<int> allnodes(n);
    iota(all(allnodes), 1);

    for (int i = 1; i <= n; i++) {
        mx[ask(i, allnodes)].push_back(i);
    }


    auto it = prev(mx.end());
    int cur = it->second.back();
    int len = it->first;

    ve<int> chain;
    chain.reserve(len);
    chain.push_back(cur);

    while (len > 1) {
        len--;
        for (int nxt : mx[len]) {
            int check = askone(cur, nxt);
            if (check > 1) {
                cur = nxt;
                chain.push_back(cur);
                break;
            }
        }
    }

    cout << "! " << sz(chain);
    for (int& x : chain) {
        cout << " " << x;
    }
    cout << endl;
}

uci main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}

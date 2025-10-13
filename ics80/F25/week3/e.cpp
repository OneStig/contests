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

int n;

int ask(int pos, int set) {
    ve<int> a(n + 1, 2);
    a[pos] += set;
    cout << '?';
    for (int i = 1; i <= n; i++) {
        cout << ' ' << a[i];
    }
    cout << endl;

    int res;
    cin >> res;
    return res;
}

uci main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;

    if (n == 2) {
        int ans = ask(1, -1);
        if (ans == 0) {
            cout << "! 1 2" << endl;
        }
        else {
            cout << "! 2 1" << endl;
        }
        return 0;
    }

    ve<int> succ(n + 1);

    for (int i = 1; i <= n; i++) {
        int prev = ask(i, -1);
        int nxt = ask(i, 1);
    
        if (prev == 0) {
            succ[0] = i;
        }
        else if (prev != i) {
            succ[prev] = i;
        }

        if (nxt != 0) {
            succ[i] = nxt;
        }
    }

    ve<int> ans(n);

    int cur = succ[0];
    for (int i = 1; i <= n; i++) {
        ans[cur - 1] = i;
        cur = succ[cur];
    }

    cout << "!";
    for (int& x : ans) cout << ' ' << x;
    cout << endl;
}

// go right to left, set all 1s last one 2 to find successor
// do opposite to find precursors?

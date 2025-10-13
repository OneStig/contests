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

    int n;
    cin >> n;

    ve<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int ans = 0;
    ve<bool> vis(n + 1);
    for (int i = 1; i <= n; i++) {
        if (a[i] == i) continue;
        
        if (!vis[i]) {
            int gs = 0;
            int mn = i;
            int cur = i;
            while (!vis[cur]) {
                gs++;
                mn = min(mn, cur);
                vis[cur] = 1;
                ans += cur;
                cur = a[cur];
            }

            int noswap = (gs - 2) * mn;
            // swap mn and 1 back and fortth
            // resolve the cycle for (gs - 1 things)
            int swapone = mn + gs + 1;
            ans += min(noswap, swapone);
        }
    }

    cout << ans << '\n';
}

// theory: we only want to do swaps in disjoint cycles (never across cycles?)
// e.g. a -> b -> c -> d -> a
//      a -> c -> d -> a (b) paid cost of c
// this seems too simple to be correct, but what is counterexample?
// ^ counterexample
// there exists a case where we want to swap 1 into a cycle to minimize the cost
// swap 1 <-> mn, after resolve cycle, mn <-> 1

// 1 a b c
// a 1 b c (a 1)
// a b 1 c (b 1)
// a b c 1 (c 1)
// a b 1 c (c 1)
// a 1 b c (b 1)
// 1 a b c (a 1)
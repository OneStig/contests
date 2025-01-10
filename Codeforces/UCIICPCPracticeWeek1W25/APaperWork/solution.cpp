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

    ve<int> a(n);
    for (int& x : a) cin >> x;

    ve<int> ans;
    int count = 0;
    int lt = 0;
    for (int& x : a) {
        if (x < 0) {
            if (lt == 2) {
                ans.push_back(count);
                count = 0;
                lt = 0;
            }
            lt++;
        }

        count++;
    }

    ans.push_back(count);

    cout << sz(ans) << '\n';
    for (int& x : ans) cout << x << ' ';
    cout << '\n';
}

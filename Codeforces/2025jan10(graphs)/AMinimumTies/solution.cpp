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
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (n % 2 == 1) {
                    if (j - i <= n / 2) {
                        cout << 1 << ' ';
                    }
                    else {
                        cout << -1 << ' ';
                    }
                }
                else {
                    if (j - i == n / 2) {
                        cout << 0 << ' ';
                    }
                    else if (j - i < n / 2) {
                        cout << 1 << ' ';
                    }
                    else {
                        cout << -1 << ' ';
                    }
                }
            }
        }

        cout << '\n';
    }
}

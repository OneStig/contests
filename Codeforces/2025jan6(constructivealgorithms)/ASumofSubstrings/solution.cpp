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
        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        int sum = 0;
        int left = -1;
        int right = n;
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (i < n - 1) {
                sum += (s[i] - '0') * 10 + (s[i + 1] - '0');
            }

            if (s[i] == '1') {
                if (left == -1) {
                    left = i;
                }
                count++;
                right = i;
            }
        }

        count -= s[n - 1] == '1';

        if (right < n - 1 && k >= n - right - 1 && count) {
            count--;
            k -= n - right - 1;
            sum -= 10;

            if (right == 0) {
                sum++;
            }
        }

        if (left != 0 && k >= left && count) {
            sum--;
        }

        cout << sum << '\n';
    }
}

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
        string s;
        cin >> s;
        int n = sz(s);

        int sum = 0, opt = 0;
        for (char c : s) {
            if (c == '(') sum++;
            else if (c == ')') sum--;
            else opt++;
        }

        int open = 0, close = 0;

        if (sum > 0) {
            close += abs(sum);
        }
        else {
            open += abs(sum);
        }
        opt -= abs(sum);
        close += opt / 2;
        open += opt / 2;

        bool unique = 1;

        if (open != 0 && close != 0) {
            int count = 0;
            int newsum = 0;
            unique = 0;
            for (int i = 0; i < n; i++) {
                if (s[i] == '(') newsum++;
                else if (s[i] == ')') newsum--;
                else {
                    count++;
                    if (count < open || count == open + 1) {
                        newsum++;
                    }
                    else {
                        newsum--;
                    }
                }

                if (newsum < 0) {
                    unique = 1;
                    break;
                }
            }
        }

        cout << (unique ? "YES" : "NO") << '\n';
    }
}

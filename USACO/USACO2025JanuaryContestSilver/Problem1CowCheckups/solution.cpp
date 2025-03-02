#include <bits/stdc++.h>

using namespace std;

// #define ONLINE_JUDGE

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

const int MAX_N = 5e5;

int n;
int a[MAX_N], b[MAX_N];

uci main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    unordered_map<int, ve<int>> bpos, bpfx;

    for (int i = 0; i < n; i++) {
        cin >> b[i];
        bpos[b[i]].push_back(i);
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) {
            // if in correct position, count times not rev
            int left = i * (i + 1) / 2;
            int right = (n - i - 1) * (n - i) / 2;

            ans += left + right;
        }

        // for all correct things in b, count pairs?

    }
}

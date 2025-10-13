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

int ask(int x) {
    cout << "? " << x + 1 << endl;
    int res;
    cin >> res;
    return res;
}

uci main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        if (2 * k == n) {
            cout << "! " << k << ' ' << k << endl;
            continue;
        }

        ve<int> a(k + 1), b(k + 1);

        for (int i = 0; i < k; i++) {
            int num = ask(i);
            a[num] = i;
        }

        for (int i = n - k; i < n; i++) {
            int num = ask(i);
            b[num] = i % k;
        }

        int cand = -1;
        for (int i = 1; i <= k; i++) {
            if (a[i] != b[i]) {
                cand = i;
                break;
            }
        }

        if (cand == -1) {
            cout << "! -1" << endl;
            continue;
        }

        int l = 0, r = n / k - 1;

        while (l < r) {
            int mid = (l + r + 1) / 2;

            int expect = mid * k + a[cand];
            int check = ask(expect);

            if (check == cand) {
                l = mid;
            }
            else {
                r = mid - 1;
            }
        }

        int aans = -1, bans = -1;
        int last = 1; // 0 - ambg, 1 - a, 2 - b
        for (int i = l * k + a[cand] + 1; 1; i++) {
            int check = ask(i);
            bool agood = a[check] == i % k;
            bool bgood = b[check] == i % k;

            if ((bgood && !agood) || i == n - k) {
                if (last == 1) {
                    aans = i;
                    bans = n - i;
                }
                
                break;
            }

            if ((agood && !bgood) || i < k) {
                last = 1;
            }
            else {
                last = 0;
            }
        }

        if (aans == -1) {
            cout << "! -1" << endl;
        }
        else {
            cout << "! " << aans << ' ' << bans << endl;
        }
    }
}

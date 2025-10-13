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

const int MAX_N = 1644934081;
const int MAX_RT = sqrt(MAX_N) + 1;

ve<int> psq;
ve<int> contrib;

int csp(int m) {
    // # of semi primes <= m

    int count = m;

    for (int i = 2; i <= MAX_RT; i++) {
        int delta = m / (i * i);
        if (delta == 0) break;
    
        count += delta * contrib[i];
    }

    return count;
}

uci main() {
    cin.tie(0)->sync_with_stdio(0);

    ve<bool> isp(MAX_RT + 1, 1);
    contrib.resize(MAX_RT + 1, 1);

    for (int i = 2; i <= MAX_RT; i++) {
        if (isp[i]) {
            int sq = i * i;
            psq.push_back(sq);

            for (int j = sq; j <= MAX_RT; j += sq) {
                contrib[j] *= 0;
            }

            contrib[i] *= -1;
            for (int j = 2 * i; j <= MAX_RT; j += i) {
                isp[j] = 0;
                contrib[j] *= -1;
            }
        }
    }

    int k;
    cin >> k;

    int l = 1, r = MAX_N;
    while (l < r) {
        int m = (l + r) / 2;
        bool issp = 1;
    
        for (int& p : psq) {
            if (m % p == 0) {
                issp = 0;
                break;
            }
        }

        int count = csp(m);
    
        if (count == k && issp) {
            l = m;
            break;
        }
    
        if (count < k) {
            l = m + 1;
        }
        else {
            r = m - 1;
        }
    }

    cout << l << '\n';
}

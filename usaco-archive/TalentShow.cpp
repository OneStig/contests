#include <bits/stdc++.h>

using namespace std;

int n, w;

int weights[1001];
int talent[1001];


long long dp[1001];

bool test(long long y) {
    for (int i = 0; i <= w; i++) {
        dp[i] = LLONG_MIN;
    }

    dp[0] = 0;

    for (int j = 0; j < n; j++) {
        long long value = 1000 * (long long)talent[j] - y * (long long)weights[j];
        int inc = weights[j];

        for (int k = w; k >= 0; k--) {
            int k1 = min(w, k + inc);
            if (dp[k] != LLONG_MIN) {
                dp[k1] = max(dp[k1], dp[k] + value);
            } 
        }
    }

    return dp[w] >= 0;
}

int main() {
    freopen("talent.in", "r", stdin);
    freopen("talent.out", "w", stdout);

    cin >> n >> w;
    for (int i = 0; i < n; i++) {
        cin >> weights[i] >> talent[i];
    }

    long long lo = 0;
    long long hi = (250 * 1000 * 1000) + 1;

    while (hi > lo + 1) {
        long long mid = (lo + hi) / 2;
        if (test(mid)) {
            lo = mid;
        } else {
            hi = mid;
        }
    }

    cout << lo << endl;
}
#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<long long> nums(n + 1);

        for (int i = 1; i <= n; i++) {
            cin >> nums[i];
        }

        long long sol = LLONG_MIN;

        for (long long i = max(n - 2 * k, 1); i <= n; i++) {
            for (long long j = i + 1; j <= n; j++) {
                sol = max(sol, i * j - k * (nums[i] | nums[j]));
            }
        }

        cout << sol << endl;
    }
}
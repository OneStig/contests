#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<long long> nums(n);

        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        long long ans = nums[0] * nums[1];

        for (int i = 2; i < n; i++) {
            ans = max(ans, nums[i - 1] * nums[i]);
        }

        cout << ans << endl;
    }
}
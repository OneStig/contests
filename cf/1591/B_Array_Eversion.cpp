#include <bits/stdc++.h>

using namespace std;


int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        int mx = INT_MIN;

        for (int i = 0; i < n; i++) {
            cin >> nums[i];
            mx = max(mx, nums[i]);
        }

        if (nums[nums.size() - 1] == mx) {
            cout << 0 << endl;
            continue;
        }

        int ans = 1;

        int cmx = nums[nums.size() - 1];

        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] == mx) {
                break;
            }

            if (nums[i] > cmx) {
                ans++;
                cmx = nums[i];
            }
        }

        cout << ans << endl;
    }
}
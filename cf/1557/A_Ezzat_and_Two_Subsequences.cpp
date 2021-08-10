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
        long long sum = 0;

        for (int i = 0; i < n; i++) {
            cin >> nums[i];
            mx = max(mx, nums[i]);
            sum += nums[i];
        }

        sum -= mx;
        cout << setprecision(20) << mx + sum / (double)(n - 1) << endl;
    }
}
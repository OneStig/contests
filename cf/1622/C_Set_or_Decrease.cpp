#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        
        long long n, k;
        cin >> n >> k;

        long long sum = 0;
        vector<int> nums(n);

        for (int i = 0; i < n; i++) {
            cin >> nums[i];
            sum += nums[i];
        }

        sort(nums.begin(), nums.end());

        int i = nums.size() - 1;
        int count = 1;
        int reduc = 0;
        int moves = 0;
        while (sum > k && i > 0) {
            if (nums[i] - nums[0] + reduc > count) {
                sum -= nums[i] - nums[0];
                sum -= reduc;
                count++;
                i--;
            }
            else {
                sum -= count;
                reduc++;
            }
            moves++;
        }

        if (sum > k) {
            long long x = sum - k;
            moves += (x + count - 1) / n;
        }

        cout << moves << endl;
    }
}
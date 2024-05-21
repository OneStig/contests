#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int main() {
    int t, n;
    cin >> t >> n;

    cout << t << "\n";
    while (t--) {
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            nums[i] = i + 1;
        }

        random_shuffle(nums.begin(), nums.end());
        cout << n << '\n';
        for (int& x : nums) {
            cout << x << ' ';
        }

        cout << '\n';
    }
}

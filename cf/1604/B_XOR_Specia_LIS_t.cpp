#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> nums(n);

        for (int& i : nums) {
            cin >> i;
        }

        if (n % 2 == 0) {
            cout << "YES" << endl;
            continue;
        }

        int last = nums[0];

        int b = 0;

        for (int i = 1; i < n; i++) {
            if (nums[i] <= last) {
                b = 1;
                break;
            }

            last = nums[i];
        }

        if (b) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}
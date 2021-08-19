#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int s = INT_MAX;

        vector<int> nums(n);

        for (int i = 0; i < n; i++) {
            cin >> nums[i];
            s = min(s, nums[i]);
        }

        int sol = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] != s) {
                sol++;
            }
        }

        cout << sol << endl;
    }
}
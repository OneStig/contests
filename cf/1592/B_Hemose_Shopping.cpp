#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, x;
        cin >> n >> x;

        vector<int> nums(n);
        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            cin >> nums[i];
            ans[i] = nums[i]; 
        }

        sort(ans.begin(), ans.end());

        unordered_map<int, int> m;

        for (int i = 0; i < n; i++) {
            m[ans[i]] = i;
        }

        int f = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] != ans[i] && (max(n - 1 - i, i) < x || max(n - 1 - m[nums[i]], m[nums[i]]) < x)) {
                f = 1;
                break;
            }
        }

        if (f) {
            cout << "NO" << endl;
        }
        else {
            cout << "YES" << endl;
        }
    }
}
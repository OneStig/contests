#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> nums(n);
        map<int, int> act;

        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        vector<int> tmp = nums;
        sort(tmp.begin(), tmp.end());

        for (int i = 0; i < n; i++) {
            act[tmp[i]] = i;
        }

        int req = 1;

        for (int i = 1; i < n; i++) {
            if (act[nums[i]] - 1 != act[nums[i - 1]]) {
                req++;
            }
        }

        cout << (req <= k ? "Yes" : "No") << endl;
    }
}
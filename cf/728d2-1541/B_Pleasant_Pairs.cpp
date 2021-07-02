#include <bits/stdc++.h>

using namespace std;

int nums[200000];

int main() {
    int t;
    cin >> t;

    while (t--) {
        memset(nums, -1, sizeof(nums));

        int n;
        cin >> n;
        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            nums[arr[i]] = i;
        }
                        
        for (int i = 1; i < 4 * n; i++) {

        }
    }
}
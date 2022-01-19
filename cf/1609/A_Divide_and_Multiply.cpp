#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;

        vector<int> nums(n);

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            cin >> nums[i];
            ans += nums[i];
        }

        for (int i = 0; i < n; i++) {
            long long test = 0;
            long long mult = 1;
            for (int j = 0; j < n; j++) {
                if (j != i) {
                    long long cur = nums[j];

                    while (cur % 2 == 0 && cur != 0) {
                        mult *= 2;
                        cur /= 2;
                    }

                    test += cur;
                }
            }

            test += nums[i] * mult;
            ans = max(ans, test);
        }

        cout << ans << endl;
    }
}
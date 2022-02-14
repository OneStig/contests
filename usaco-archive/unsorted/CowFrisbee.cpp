#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    long long sum = 0;

    for (int i = 0; i < n; i++) {
        int mx = 0;
        for (int j = i + 1; j < n; j++) {
            if (mx > nums[i]) {
                break;
            }

            if (mx < nums[j]) {
                mx = nums[j];
                sum += j - i + 1;
            }
        }
    }

    cout << sum << endl;
}
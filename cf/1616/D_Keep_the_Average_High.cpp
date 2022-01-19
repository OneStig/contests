#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> nums(n);

        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        int best = 0;

        for (int i = 0; i < n; i++) {
            unordered_map<double, int> slopes;
            vector<double> unique;

            for (int j = 0; j < n; j++) {
                if (i == j) {continue;}

                double cur = (nums[j] - nums[i]) * 1.0 / (j - i);

                if (slopes[cur] == 0) {
                    unique.push_back(cur);
                }

                slopes[cur]++;
            }

            for (double e : unique) {
                best = max(best, slopes[e]);
            }
        }

        cout << n - 1 - best << endl;
    }
}
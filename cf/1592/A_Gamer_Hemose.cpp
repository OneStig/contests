#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, h;
        cin >> n >> h;

        int b = INT_MIN;
        int b2 = INT_MIN;
        int b3 = 0;

        vector<int> w(n);

        for (int i = 0; i < n; i++) {
            cin >> w[i];
            if (w[i] > b) {
                b = w[i];
                b3 = i;
            }
        }

        for (int i = 0; i < n; i++) {
            if (b3 != i) {
                b2 = max(b2, w[i]);
            }
        }

        int ans = 2 * (h / (b + b2));

        if (h % (b + b2) > 0) {
            ans ++;

            if (h % (b + b2) > b) {
                ans++;
            }
        }


        cout << ans << endl;
    }
}
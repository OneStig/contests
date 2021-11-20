#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int m = INT_MIN;

        for (int i = 1; i <= n; i++) {
            int k;
            cin >> k;
            
            m = max(m, k - i);
        }

        cout << max(0, m) << endl;
    }
}
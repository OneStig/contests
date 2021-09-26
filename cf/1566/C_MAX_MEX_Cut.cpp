#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        string a, b;
        cin >> n >> a >> b;

        int ans = 0;

        vector<bool> flag(n);

        for (int i = 0; i < n; i++) {
            if (a[i] - '0' + b[i] - '0' == 1) {
                ans += 2;
            } else if (a[i] - '0' + b[i] - '0' == 0) {
                ans++;
            } else if (a[i] - '0' + b[i] - '0' == 2) {
                if (i > 0 && !flag[i - 1] && a[i - 1] - '0' + b[i - 1] - '0' == 0) {
                    ans++;
                    continue;
                }
                if (i < n - 1 && a[i + 1] - '0' + b[i + 1] - '0' == 0) {
                    flag[i + 1] = 1;
                    ans++;
                    
                }
            }
        }

        cout << ans << endl;
    }
}
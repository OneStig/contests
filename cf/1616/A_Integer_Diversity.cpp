#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int ans = 0;

        unordered_map<int, bool> s;

        while (n--) {
            int k;
            cin >> k;

            if (!s[k]) {
                ans++;
                s[k] = 1;
            }
            else {
                if (!s[-k]) {
                    ans++;
                    s[-k] = 1;
                }
            }
        }

        cout << ans << endl;
    }
}
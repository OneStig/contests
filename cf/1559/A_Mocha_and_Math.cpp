#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int ans;
        int tmp;
        cin >> ans;

        for (int i = 1; i < n; i++) {
            cin >> tmp;
            ans &= tmp;
        }

        cout << ans << endl;
    }
}
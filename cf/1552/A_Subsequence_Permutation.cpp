#include <bits/stdc++.h>

using namespace std;

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        int n;

        int let[26];

        memset(let, 0, sizeof(let));

        
        cin >> n;
        string s;
        cin >> s;

        for (int i = 0; i < n; i++) {
            let[s[i] - 'a']++;
        }

        string comp = "";

        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < let[i]; j++) {
                comp += ('a' + i);
            }
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] != comp[i]) {
                ans++;
            }
        }

        cout << ans << endl;
    }
}
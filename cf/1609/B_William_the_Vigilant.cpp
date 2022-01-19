#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    vector<bool> flag(n);

    int sum = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == 'a') {
            if (i + 1 < n && i + 2 < n && s[i + 1] == 'b' && s[i + 2] == 'c') {
                sum++;
                flag[i] = 1;
            }
        }
    }

    for (int i = 0; i < q; i++) {
        int p;
        char c;
        cin >> p >> c;

        p--;

        int orig = 0;

        for (int j = max(0, p - 2); j <= p; j++) {
            flag[j] = 0;
            if (s[j] == 'a') {
                if (j + 1 < n && j + 2 < n && s[j + 1] == 'b' && s[j + 2] == 'c') {
                    orig++;
                }
            }
        }

        // cout << "org" << orig << endl;
        int aft = 0;

        s[p] = c;

        for (int j = max(0, p - 2); j <= p; j++) {
            if (s[j] == 'a') {
                if (j + 1 < n && j + 2 < n && s[j + 1] == 'b' && s[j + 2] == 'c') {
                    aft++;
                    flag[j] = 1;
                }
            }
        }

        // cout << "af" << aft << endl;

        sum += aft - orig;
        cout << sum << endl;
    }
}
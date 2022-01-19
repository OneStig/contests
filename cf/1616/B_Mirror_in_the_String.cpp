#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int t;
    cin >> t;
 
    while (t--) {
        int n;
        cin >> n;
 
        string s;
        cin >> s;
 
        int pos = 0;
 
        cout << s[0];
 
        char last = s[0];

        for (int i = 1; i < n; i++) {
            if (s[i] - 'a' == s[i - 1] - 'a' && s[i] - 'a' < last - 'a') {

                cout << s[i];
                pos = i;
            }
            else if (s[i] - 'a' < s[i - 1] - 'a') {
                cout << s[i];
                pos = i;
                last = s[i - 1];
            }
            else {
                break;
            }
        }
 
        for (int i = pos; i >= 0; i--) {
            cout << s[i];
        }
 
        cout << endl;
    }
}
#include <bits/stdc++.h>

using namespace std;

typedef int uci;
#define int long long
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

uci main() {
    cin.tie(0)->sync_with_stdio();
    int n;
    cin >> n;
    while (n--) {
        string a;
        cin >> a;
        string b;
        cin >> b;
        set<char> s;
        for (int i = 0; i < a.size(); i++) {
            s.insert(a[i]);
        }
        bool good = true;
        for (auto i : b) {
            if (s.find(i) == s.end()) {
                good = false;

            }
        }
        if (good) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}
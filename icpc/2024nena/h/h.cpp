#include <bits/stdc++.h>

using namespace std;

typedef int uci;
#define int long long
#define sz(x) ((int)x.size())
#define a first
#define b second
#define all(a) (a).begin(), (a).end()

uci main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n;
    cin >> n;
    vector<int> lst;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++){
        lst.push_back(s[i] - 'A');
      //  cout << s[i] - 'A' << " ";
   }
    //cout << "\n";
    vector<pair<int,int>> conds;
    vector<int> a;
    for (int i = 0; i < n; i++) {
        a.push_back(i);
    }
    for (int i = 0; i < n; i++) {
        //cout << a.size() << "\n";
        //for (int i = 0; i < a.size(); i++) {
        //   cout <<i << " ";
        //}
        //cout << "\n";
        int j;
        for (j = 0; j < a.size(); j++) {
            if (a[j] == lst[i]) {
                break;
            }
        }
        //cout << j << "\n";
        conds.push_back({j,n - i});
        a.erase(a.begin() + j);
    }
    int x = 0;
    int y = 1;
    for (int i = 1; i < n+1; i++) {
        if (i == 2 or i == 3 or i == 5 or i == 7
            or i == 11 or i == 13 or i == 17 or i == 19) {
            //cout << x <<" " << y << "\n";
            ///cout << i << " " << conds[n-i].a << " " << conds[n-i].b << "\n";

            if (y == 1) {
                x = conds[n-i].a;
                y = i;

                continue;
            }
            for (int r = 0; r < y * i; r++) {
                if (r % i == conds[n-i].a and r % y == x) {
                    x = r;
                }
            }
            y *= i;
        }
    }
    int c = 1;
    for (int i = 1; i < n+1;i++) {
        c = lcm(c,i);
    }
    //cout << x << " " << y << "\n";
    bool good = false;
    for (int v = x; v < c; v+=y) {
        bool g = true;
        for (int i = 0; i < n; i++) {
            if (v % conds[i].b != conds[i].a) {
                g = false;
            }
        }
        if (g) {
            cout << "YES\n";
            cout << v << "\n";
            good = true;
            break;
        }
    }
    if (!good) {
        cout << "NO\n";
    }
}
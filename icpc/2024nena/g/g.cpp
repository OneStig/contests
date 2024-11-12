#include <bits/stdc++.h>

using namespace std;

typedef int uci;
#define int long long
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

uci main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int p, n;
    cin >> p >> n;

    vector<string> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    set<char> possible;
    for(int i = 0; i < p; ++i) {
        possible.insert(char('A' + i));
    }


    int maxim = 0;
    for(int bit = 0; bit < (1 << n); ++bit) {
        set<char> available = possible;
        bool ok = true;
        int cnt = 0;
        for(int i = 0; i < n && ok; ++i) {
            if((bit >> i) & 1) {
                cnt++;
                if(sz(a[i]) > p) {
                    ok = false;
                }
                else {
                    for(auto c : a[i]) {
                        if(available.find(c) != available.end()) {
                            available.erase(c);
                        }

                        else {
                            ok = false;
                        }
                    }
                }
            }
        }

        if(ok) {
            maxim = max(maxim, cnt);
        }
    }

    cout << maxim << endl;
}
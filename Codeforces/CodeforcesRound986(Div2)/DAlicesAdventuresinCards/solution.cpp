#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "cpp-dump/cpp-dump.hpp"
#define dbg(...) cpp_dump(__VA_ARGS__)
#else
#define dbg(...)
#endif

typedef int uci;
#define int long long
#define ld long double
#define ve vector
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
typedef pair<int, int> pii;

uci main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        ve<int> Q(n + 1), K(n + 1), J(n + 1);

        for (int i = 1; i <= n; i++) cin >> Q[i];
        for (int i = 1; i <= n; i++) cin >> K[i];
        for (int i = 1; i <= n; i++) cin >> J[i];

        ve<pair<char, int>> path(n + 1, {'x', 0});

        int qc = n, kc = n, jc = n;
        for (int i = n - 1; i > 0; i--) {
            if (Q[qc] < Q[i]) {
                path[i] = {'q', qc};
            }
            else if (K[kc] < K[i]) {
                path[i] = {'k', kc};
            }
            else if (J[jc] < J[i]) {
                path[i] = {'j', jc};
            }

            if (path[i].second != 0) {
                if (Q[i] < Q[qc]) {
                    qc = i;
                }
                if (K[i] < K[kc]) {
                    kc = i;
                }
                if (J[i] < J[jc]) {
                    jc = i;
                }
            }
        }
        
        if (path[1].second != 0) {
            cout << "YES\n";
            vector<pair<char, int>> prnt;
            int cur = 1;
            while (cur != n) {
                prnt.push_back(path[cur]);
                cur = path[cur].second;
            }
            cout << sz(prnt) << '\n';
            for (auto& p : prnt) {
                cout << p.first << ' ' << p.second << '\n';
            }
        }
        else {
            cout << "NO\n";
        }
    }
}

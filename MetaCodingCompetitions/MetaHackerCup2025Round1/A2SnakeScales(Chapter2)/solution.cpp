#include <bits/stdc++.h>

using namespace std;

#define ONLINE_JUDGE

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

void solve() {
    int n;
    cin >> n;

    ve<int> a(n);
    set<int> found;
    priority_queue<pii, ve<pii>, greater<pii>> pq;
    for (int i = 0; i < n; i++) {
        cin >> a[i]; 
        pq.push({a[i], i});
    }

    int ans = 0;
    while (sz(found) != n) {
        auto [cost, node] = pq.top();
        pq.pop();
        
        if (!found.count(node)) {
            found.insert(node);
            ans = max(ans, cost);
        
            if (node - 1 >= 0 && !found.count(node - 1)) {
                pq.push({abs(a[node] - a[node - 1]), node - 1});
            }

            if (node + 1 < n && !found.count(node + 1)) {
                pq.push({abs(a[node] - a[node + 1]), node + 1});
            }
        }
    }

    cout << ans << '\n';
}

uci main() {
    cin.tie(0)->sync_with_stdio(0);

    int tc;
    cin >> tc;
    for (int cs = 1; cs <= tc; cs++) {
        cout << "Case #" << cs << ": ";
        solve();
    }
}

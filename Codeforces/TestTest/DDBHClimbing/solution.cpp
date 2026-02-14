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

    int n;
    cin >> n;

    ve<int> k(n);
    for (int& x : k) cin >> x;

    priority_queue<pii, ve<pii>, greater<pii>> pq;
    pq.push({0, 0});

    int cur = 0;
    for (int i = 0; i < n; i++) {
        while (pq.size() && pq.top().second < i) {
            pq.pop();
        }
        cur = pq.top().first;

        pq.push({cur + 1, i + k[i]});
    }

    cout << n - cur << '\n';
}

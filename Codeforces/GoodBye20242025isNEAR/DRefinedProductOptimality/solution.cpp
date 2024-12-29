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

const int MOD = 998244353;

pii iv = {1, 1};
pii f(pii a, pii b) {
    int cmp = min(a.first, a.second) * min(b.first, b.second) % MOD;
    return {cmp, cmp};
} // commutative

struct ST {
  vector<pii> s; int n;
  ST(int n = 0) : s(2*n, iv), n(n) {}
  void update(int i, pii v) { // a[i] = v
    for (s[i += n] = v; i /= 2;)
      s[i] = f(s[i * 2], s[i * 2 + 1]);
  }
  int query(int b, int e) { // query [b, e)
    pii r = iv;
    for (b += n, e += n; b < e; b /= 2, e /= 2) {
      if (b % 2) r = f(r, s[b++]);
      if (e % 2) r = f(s[--e], r);
    }
    return min(r.first, r.second);
  }
};

void solve() {
    int n, q;
    cin >> n >> q;
    ve<int> a(n), b(n);
    for (int& x : a) cin >> x;
    for (int& x : b) cin >> x;

    ve<int> avals = a;
    ve<int> bvals = b;
    sort(all(avals));
    sort(all(bvals));

    ST st(n);
    for (int i = 0; i < n; i++) {
        pii cur = {avals[i], bvals[i]};
        st.update(i, cur);
    }

    cout << st.query(0, n);
    while (q--) {
        int o, x;
        cin >> o >> x;
        x--;
        if (o == 1) {
            // increment a_x
            int pos = upper_bound(all(avals), a[x]) - avals.begin() - 1;
            avals[pos]++;
            a[x]++;
            st.update(pos, {avals[pos], bvals[pos]});
        }
        else {
            // increment b_x
            int pos = upper_bound(all(bvals), b[x]) - bvals.begin() - 1;
            bvals[pos]++;
            b[x]++;
            st.update(pos, {avals[pos], bvals[pos]});
        }

        cout << ' ' << st.query(0, n);
    }
    cout << '\n';
}

uci main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}

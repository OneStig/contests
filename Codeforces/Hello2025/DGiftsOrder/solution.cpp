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

const int INF = 1e12;

struct Pt {
    int pmx, pmn, smx, smn, c1{}, c2{};

    Pt() : pmx{-INF}, pmn{INF}, smx{-INF}, smn{INF} {}
    Pt(int a, int i) : pmx{a + i}, pmn{a + i}, smx{a - i}, smn{a - i} {}

    Pt unite(const Pt& other) {
        Pt ret{};
        ret.pmx = max(pmx, other.pmx);
        ret.pmn = min(pmn, other.pmn);
        ret.smx = max(smx, other.smx);
        ret.smn = min(smn, other.smn);

        ret.c1 = max(pmx - other.pmn, max(c1, other.c1));
        ret.c2 = max(other.smx - smn, max(c2, other.c2));

        return ret;
    }
};


// max, min, max left ans, max right ans
Pt iv{};

Pt f(Pt a, Pt b) { 
    return a.unite(b);
}

struct ST {
  vector<Pt> s; int n;
  ST(int n = 0) : s(2*n, iv), n(n) {}
  void update(int i, Pt v) { // a[i] = v
    for (s[i += n] = v; i /= 2;)
      s[i] = f(s[i * 2], s[i * 2 + 1]);
  }
  Pt query(int b, int e) { // query [b, e)
    Pt r = iv;

    for (b += n, e += n; b < e; b /= 2, e /= 2) {
      if (b % 2) r = f(r, s[b++]);
      if (e % 2) r = f(s[--e], r);
    }
    return r;
  }
};

// case 1: a_l is max, then a_l - a_r - (r - l)
// (a_l + l) - (a_r + r)
// case 2: a_l is min, then a_r - a_l - (r - l)
// (a_r - r) - (a_l - l)

uci main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        int n, q;
        cin >> n >> q;

        int faken = pow(2, (int)log2(n) + 1);
        ST st(faken);

        for (int i = 1; i <= n; i++) {
            int a;
            cin >> a;
            Pt test = Pt{a, i};
            st.update(i - 1, Pt{a, i});
        }

        for (int i = 1; i < sz(st.s); i++) {
            Pt& x = st.s[i];
            dbg(i, x.pmx, x.pmn, x.smx, x.smn, x.c1, x.c2);
        }

        auto ans = [&]() -> int {
            Pt tot = st.query(0, n);
            return max(tot.c1, tot.c2);
        };

        cout << ans() << '\n';
        
        while (q--) {
            int p, x;
            cin >> p >> x;

            st.update(p - 1, Pt{x, p});
            cout << ans() << '\n';
        }
    }
}

#include <bits/stdc++.h>

using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifndef ONLINE_JUDGE
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

typedef int uci;
#define int long long
#define ld long double
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

int iv = INT_MIN;
int f(int a, int b) { return max(a, b); } 

struct ST {
  vector<int> s; int n;
  ST(int n = 0) : s(2*n, iv), n(n) {}
  void update(int i, int v) { // a[i] = v
    for (s[i += n] = v; i /= 2;)
      s[i] = f(s[i * 2], s[i * 2 + 1]);
  }
  int query(int b, int e) { // query [b, e)
    int r = iv;
    for (b += n, e += n; b < e; b /= 2, e /= 2) {
      if (b % 2) r = f(r, s[b++]);
      if (e % 2) r = f(s[--e], r);
    }
    return r;
  }
};

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
    
        vector<int> a(n), b(m);
        for (int& x : a) cin >> x;
        for (int& x : b) cin >> x;
    
        int kev = a[0];
        sort(all(a));
        sort(all(b));
    
        // int kevpos = (upper_bound(all(a), kev) - a.begin()) - 1;
        // dbg(a, kev);
        // dbg(b);
    
        ST st(m);
        vector<int> pos(m);
    
        for (int i = 0; i < m; i++) {
            auto solvers = lower_bound(all(a), b[i]);
            int better = a.end() - solvers;

            if (kev >= b[i]) {
                better = 0;
            }

            pos[i] = better + 1;
        }

        sort(all(pos));

        for (int i = 0; i < m; i++) {
            st.update(i, pos[i]);
        }

        for (int k = 1; k <= m; k++) {
            int sum = 0;
            
            for (int j = 0; j + k <= m; j += k) {
                sum += st.query(j, j + k);
            }

            cout << sum << ' ';
            // cout << pos[contests - 1] << ' ';
        }
        cout << '\n';
    }
}

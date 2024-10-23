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
int f(int a, int b) { return max(a, b); } // commutative

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

    int n;
    cin >> n;
    vector<array<int, 3>> a(n);

    set<int> comp;
    map<int, int> at;

    for(int i = 0; i < n; ++i){
        int l, r;
        cin >> l >> r;
        a[i][0] = l;
        a[i][1] = -r;
        a[i][2] = i;
        comp.insert(l);
        comp.insert(l + r - 1);
    }

    int cnt = 0;
    for (int x : comp) {
        at[x] = cnt++;
    }

    sort(all(a));
    map<int, int> ans;

    ST tree(sz(comp));

    vector<int> best(sz(comp), -1);
    for (auto& cur : a) {
        int l = cur[0], r = cur[0] - cur[1] - 1, ind = cur[2];

        int curans = max(0ll, tree.query(at[r], sz(comp)) + 1);
        ans[ind] = curans;

        if (curans > best[at[r]]) {
            best[at[r]] = curans;
            tree.update(at[r], curans);
        }
    }

    for(int i = 0; i < n; ++i){
        cout << ans[i] << "\n";
    }
}

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

const int MOD = 1e9 + 7;
const int MAX_N = 1e5 + 1;

int fact[MAX_N + 5], inv_fact[MAX_N + 5];

int power(int x, int y, int p) {
    int res = 1;
    x = x % p;

    while (y > 0) {
        if (y & 1) {
            res = (res * x) % p;
        }

        y = y >> 1;
        x = (x * x) % p;
    }

    return res;
}

int binom(int n, int k) {
    return fact[n] * inv_fact[k] % MOD * inv_fact[n - k] % MOD;
}

// compute for [l, r)
int segment(int x, int l, int r, vector<vector<int>>& occ) {
    if (r == l) {
        return 1;
    }

    if (!sz(occ[x])) {
        return 0;
    }

    int mid = occ[x].back();

    if (mid < l || mid >= r) {
        return 0;
    }

    occ[x].pop_back();

    int cur = binom(r - l - 1, mid - l);
    cur = cur % MOD * segment(x + 1, mid + 1, r, occ) % MOD;
    cur = cur % MOD * segment(x, l, mid, occ) % MOD;

    return cur;
}

void solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    vector<vector<int>> occ(n + 2);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        occ[v[i]].push_back(i);
    }

    cout << segment(1, 0, n, occ) % MOD << '\n';
}

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    fact[0] = 1;
    for (int i = 1; i < MAX_N; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }

    inv_fact[MAX_N - 1] = power(fact[MAX_N - 1], MOD - 2, MOD);

    for (int i = MAX_N - 2; i >= 0; i--) {
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;
    }

    int t;
    cin >> t;

    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
}

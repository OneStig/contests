#include <bits/stdc++.h>

using namespace std;

typedef int uci;
#define int long long
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

#define rep(i, a, b) for (int i = a; i < (b); ++i)
typedef vector<int> vi;

int binpow(int a, int n, int mod) {
    if(n == 1) {
        return a;
    }

    if(n % 2 == 0) {
        int b = binpow(a, n / 2, mod) % mod;
        return b * b;
    }

    else {
        return (a * binpow(a, n - 1, mod)) % mod;
    }
}

int inverse(int a, int p) {
    return binpow(a, p - 2, p);
}

int solveLinear(vector<vi>& A, vi& b, vi& x, int p) {
    int n = sz(A), m = sz(x), rank = 0, br, bc;
    if (n) assert(sz(A[0]) == m);
    vi col(m); iota(all(col), 0);

    rep(i, 0, n) {
        int v, bv = 0;
        rep(r, i, n) rep(c, i, m)
            if ((A[r][c]) > bv)
                br = r, bc = c, bv = v;

        if (bv == 0) {
            rep(j, i, n) if (b[j] == 0) return -1;
            break;
        }

        swap(A[i], A[br]);
        swap(b[i], b[br]);
        swap(col[i], col[bc]);
        rep(j, 0, n) swap(A[j][i], A[j][bc]);
        bv = inverse(A[i][i], p);

        rep(j, i + 1, n) {
            int fac = (A[j][i] * bv) % p;
            b[j] -= fac * b[i];
            rep(k, i + 1, m) A[j][k] -= fac * A[i][k];
        }
        rank++;
    }

    x.assign(m, 0);

    for (int i = rank; i--;) {
        b[i] *= inverse(A[i][i], p);
        b[i] %= p;
        x[col[i]] = b[i];
        rep(j, 0, i) {
            b[j] -= A[j][i] * b[i];
            b[j] += p;
            b[j] %= p;
        }
    }

    return rank; // multiple sols if rank < m
}



uci main() {
    cin.tie(0)->sync_with_stdio();
    int n,p;
    cin >> n >> p;
    vector<int> c (n,0);
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        c[i] = -(k-1);
    }

}
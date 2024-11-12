#include <bits/stdc++.h>

using namespace std;

typedef int uci;
#define int long long
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

struct Frac {
    typedef Frac F;
    int a, b;
    explicit Frac(int a=0, int b=1) : a(a), b(b) {}
    void reduce() {
        int g = gcd(a, b);
        a = a / g;
        b = b / g;
    }

    Frac operator+(F f) const {
        int l = lcm(b, f.b);
        // a/b + f.a/f.b
        //F nf(a * f.b + b * f.a , b * f.b);
        F nf(a * (l / b) + f.a * (l / f.b), l);
        nf.reduce();
        return nf;
    }

    Frac operator*(F f) const {
        F nf(a * f.a, b * f.b);
        nf.reduce();
        return nf;
    }
};

int N;
int D;

int zero = 0;
map<array<int, 3>,Frac> cache;
Frac f(int x, int y, int d) {
    if (d > D) {
        return Frac(0, 1);
    }
    if (x == y) {
        return Frac(1,1);
    }
    if (cache.find({x,y,d}) != cache.end()) {
        return cache[{x,y,d}];
    }
    int n,m,o,p;
    n = max(x-1,1ll);
    m = min(x+1,N);
    o = max(y-1,1ll);
    p = min(y+1,N);
    cache[{x,y,d}] =  Frac(1,4) * f(n,o,d+1) + Frac(1,4) * f(m,o,d+1) +
        Frac(1,4) * f(n,p,d+1) + Frac(1,4) * f(m,p,d+1);
    return cache[{x,y,d}];
}

uci main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int  x, y;
    cin >> N >> x >> y >> D;

    Frac a = f(x,y,0);
    cout << a.a <<  "/" << a.b << "\n";
}
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

#define F first
#define S second

const int INF = 1e15;

struct Tree {
	typedef int T;
	static constexpr T unit = INT_MIN;
	T f(T a, T b) { return max(a, b); } // (any associative fn)
	vector<T> s; int n;
	Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int b, int e) { // query [b, e)
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};

bool comp(pii a, pii b) {
    if ((a.S - a.F > 0) == (b.S - b.F > 0)) {
        if (a.S - a.F <= 0) {
            return a.S > b.S;
        }
 
        return a.F < b.F;
    }
 
    return (a.S - a.F) > (b.S - b.F);
}

uci main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int asum = 0, bsum = 0;
        ve<pii> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i].F >> a[i].S;
            asum += a[i].F;
            bsum += a[i].S;
        }

        sort(all(a));

        for (int i = 0; i < n; i++) {
            if (bsum - a[i].second >= asum) {
            }
        }

    }
}

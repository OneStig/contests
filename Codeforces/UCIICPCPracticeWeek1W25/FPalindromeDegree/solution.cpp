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
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define irep(i, a, b) for(int i = a; i > (b); --i)
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
typedef pair<int, int> pii;
#define ve vector
typedef ve<int> vi;
typedef ve<vi> vvi;

array<vi, 2> manacher(const string& s) {
	int n = sz(s);
	array<vi,2> p = {vi(n+1), vi(n)};
	rep(z,0,2) for (int i=0,l=0,r=0; i < n; i++) {
		int t = r-i+!z;
		if (i<r) p[z][i] = min(t, p[z][l+t]);
		int L = i-p[z][i], R = i+p[z][i]-!z;
		while (L>=1 && R+1<n && s[L-1] == s[R+1])
			p[z][i]++, L--, R++;
		if (R>r) l=L, r=R;
	}
	return p;
}

uci main() {
    cin.tie(0)->sync_with_stdio(0);

    string s;
    cin >> s;

    auto p = manacher(s);
    ve<int> deg(sz(s));
    deg[0] = 1;
    int ans = 1;

    for (int i = 1; i < sz(s); i++) {
        int mid = (i + 1) / 2;

        if (p[1 - (i % 2)][mid] == mid) {
            deg[i] = deg[mid - 1] + 1;
        }
        ans += deg[i];
    }

    cout << ans << '\n';
}
